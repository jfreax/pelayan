#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

#include "socket/server.h"
#include "socket/client.h"
#include "socket/send.h"
#include "http/response.h"
#include "intern/settings.h"
#include "filetype.h"
#include <misc/mstring.h>
#include <http/request.h>

void resInit( struct Client* client )
{
	struct Response* res = &client->response;
	
	res->file = NULL;

	res->sended = 0;
	res->received = 0;
	
	res->sysFilename = malloc( sizeof( char ) );
	res->noType = 0;
	res->redirect = 0;
	res->noContent = 0;
	res->compressed = 0;
	
	res->header = dstInitCString("");
}


void resDel( struct Client* client )
{
	struct Response* res = &client->response;

	free( res->sysFilename );
	dstDel( res->header );
}


int receive( struct Client* client )
{
	printf("Receive from %d (%d), method -> %d\n", client->clientID, client->fd->fd, client->request.method );
	struct Request* req = &client->request;
	struct Response* res = &client->response;
	
	if ( client->request.method != POST ) {
		return;
	}
	if ( !client->completeRequest )
		return 0;
	
	if ( req->contentLength == 0 ) { /* No content, block client */
		client->isBlocked = 1;
		return 0;
	} else {
		client->isBlocked = 2;
		struct Buffer* buf = &client->buffer;
		for ( int i = req->headerEnd; i <= buf->line; ++i ) {
			int len = buf->data[i]->length;
			res->received += len;

			dstAppendCString( client->server->buffer, buf->data[i]->str );
		}
		
		if ( res->received >= req->contentLength ) {
			res->received = 0;
			srvBroadcast( client->server );
			return 1;
		}
	}
	return 0;
}


void response( struct Client* client )
{
	if ( client->request.method == POST ) {
		return;
	}
	
	printf("Respone to %d, method -> %d\n", client->clientID, client->request.method );
	
	struct Request* req = &client->request;
	struct Response* res = &client->response;
	
	if ( !client->completeRequest )
		return;
	
	const char* type = reqGetFileType( req );	
	const char* cate = ftGetCat( type );

	/* Redirect to a new site */
	if ( res->redirect ) {
		 res->redirect = 0;
		resAddStatus( res, FOUND );

		struct DString* dstr = dstInit("http://%s%s/", settings.domain, req->filename->str );
		resAddNewLocation( res, dstr->str );
		dstDel( dstr );

		resAddLength( res, 0 );
		resAddConnection( client );
		
		resSendHeader( client );
		resClose( client );
		
		client->completeRequest = 0;
		
		return;
	}
	
	/* Send only the http header */
	if ( req->method == HEAD ) {
		res->noContent = 1;
	}

	if ( !res->file ) {
// 		printf("Open file\n");
		res->file = fopen( req->systemFilename->str, "r" );

		/* Check for errors */
		if ( res->file == NULL ) {
			resAddStatus( res, NOTFOUND );
			resRetryWFilename( client, "404.html" );
		} else if ( !cate ) { /* Filetype not allowed! */
			resAddStatus( res, FORBIDDEN );
			resRetryWFilename( client, "forbidden.html" );
		} else { /* No error found */
			
// 			printf( "\t%d: Start response\n", con.fds[id].fd );

			// Obtain file size:
			fseek( res->file , 0 , SEEK_END );
			int size = res->fileSize = ftell( res->file );
			rewind( res->file );

			/* Activate pollout */
			client->fd->events |= POLLOUT;
			client->fd->events ^= POLLIN;
// 
			/* SEND HEADER */
			resAddStatus( res, OK );

			resAddType( res, type, cate );
			resAddLength( res, size );
			resAddEncoding( res );
			resAddConnection( client );
			
			resSendHeader( client );

			/* Initialize the compress class */
			if ( res->compressed )
				cprInit( &client->cprBuffer, res->file );

		}
	} else {
		if ( resSendFile( client ) ) {
// 			printf( "\t%d: End response\n", client->fd->fd );
			
			client->fd->events ^= POLLOUT;
			client->fd->events |= POLLIN;

			fclose( res->file );
			res->file = NULL;

			resClose( client );
			res->noType = 0;
			
			client->completeRequest = 0;
			
			if( req->connection == CLOSE ) {
				clDelete( client->server, client );
			}
			
// 			dstReset( res->header );
		}
	}
}


void resClose( struct Client* client )
{
	client->response.sended = 0;
	client->completeRequest = 0;
}


int resSendFile( struct Client* client )
{
	struct Response* res = &client->response;
	
	if ( res->fileSize > res->sended &&
			!client->response.noContent ) { /* Method HEAD - send no file! */

		int result;

		/*Send data in gzip format */
		if ( res->compressed ) {
			result = cprGetNext( &client->cprBuffer );

			if ( result ) { /* Compressed data to send */
// 				printf("Send %d bytes\n", result);
				resSendChunksize( client, result );
// 				gzflush( con.clients[id].cprBuffer.file, Z_FULL_FLUSH );
				ssend( client->fd->fd, client->cprBuffer.out, result );
				resSendEnd( client );
// 				resSendEnd( id );
			} else { /* No data anymore... stop sending */
				resSendChunksize( client, 0 );
				resSendEnd( client );
				res->sended = res->fileSize;
				
				cprDel( &client->cprBuffer );
			}

		} else { /* Send in plain text */
			int addSize = res->fileSize > settings.bufferSize ? settings.bufferSize : res->fileSize;
			
			char* buffer = malloc( (addSize+1) * sizeof( char ) );
			int result = fread( buffer, 1, addSize, res->file );

			if ( result < settings.bufferSize ) {
				buffer[result] = 0;
			}

			res->sended += result;
			ssend( client->fd->fd, buffer, result );
			
			free( buffer );
		}

		return 0;
	}

	return 1;
}


void resSendHeader( struct Client* client )
{
	struct Response* res = &client->response;
	
	dstAppendCString( res->header, "\r\n" );
	ssend( client->fd->fd, res->header->str, res->header->length );
	
	dstReset( res->header );
}


void resSendEnd( struct Client* client )
{
	ssend( client->fd->fd, "\r\n", 2 );
}


void resSendChunksize( struct Client* client, int size )
{
	char* buffer = malloc( 30 * sizeof( char ) );

	sprintf( buffer, "%X\r\n", size );
	ssend( client->fd->fd, buffer, strlen( buffer ) );

	free( buffer );
}


void resAddStatus( struct Response* res, enum HTTPCODE status )
{
	if ( res->noType ) {
		return;
	}
	
	switch ( status ) {
	case OK:
		dstAppendCString( res->header, "HTTP/1.1 200 OK\r\n" );
		break;
	case FOUND:
		dstAppendCString( res->header, "HTTP/1.1 302 Found\r\n" );
// 		ssend( con.fds[id].fd, "HTTP/1.1 302 Found\r\n", 20 );
		break;
	case FORBIDDEN:
		dstAppendCString( res->header, "HTTP/1.1 403 Forbidden\r\n" );
// 		ssend( con.fds[id].fd, "HTTP/1.1 403 Forbidden\r\n", 24 );
		break;
	case NOTFOUND:
		dstAppendCString( res->header, "HTTP/1.1 404 Not Found\r\n" );
// 		ssend( con.fds[id].fd, "HTTP/1.1 404 Not Found\r\n", 24 );
		break;
	default:
		break;
	}

	return;
}


void resAddType( struct Response* res, const char* type, const char* cate )
{
	dstAppend( res->header, "Content-Type: %s/%s\r\n", cate, type );

	if ( strcmp( cate, "text" ) ) {
		resAddAcceptRange( res );
	}
}


void resAddLength( struct Response* res, int size )
{
	if ( !res->compressed ) {
		dstAppend( res->header, "Content-Length: %d\r\n", size );
	} else {
		dstAppendCString( res->header, "Transfer-Encoding: chunked\r\n" );
	}
}


void resAddEncoding( struct Response* res )
{
	if ( res->compressed ) {
		dstAppendCString( res->header, "Content-Encoding: gzip\r\n" );
	}
}


void resAddNewLocation( struct Response* res, char* location )
{
	dstAppend( res->header, "Location: %s\r\n", location );
}


void resAddAcceptRange( struct Response* res )
{
	dstAppendCString( res->header, "Accept-Ranges: bytes\r\n" );
}


void resAddConnection( struct Client* client )
{
	struct Request* req = &client->request;
	if ( req->connection == KEEP_ALIVE ) {
		dstAppendCString( client->response.header, "Connection: Keep-Alive\r\n" );
	}
}


void resRetryWFilename( struct Client* client, const char* filename )
{
	printf("Retry filename\n");
// 	strcpy( con.clients[id].request.filename, filename );
	dstDel( client->request.filename );
	client->request.filename = dstInitCString( filename );
	reqCalcRealFilename( client );

	client->response.noType = 1;

	close( client->response.file );
	client->response.file = NULL;

	response( client );
}



