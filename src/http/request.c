#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "socket/client.h"
#include "http/request.h"
#include "http/response.h"
#include "misc/tokenizer.h"
#include "intern/settings.h"



void reqInit( struct Client* client )
{
	struct Request* req = &client->request;

	req->headerEnd = 0;
	
	req->method = NONE;
	req->httpVersion = HTTP_11;
	
	req->filename = NULL;
	req->systemFilename = dstInitCString("");
	
	req->contentLength = -1;
}


void reqDel( struct Client* client )
{
	dstDel( client->request.filename );
	dstDel( client->request.systemFilename );
}


int reqParse( struct Client* client )
{
	struct Request* req = &client->request;
	struct Buffer* buf = &client->buffer;

	char* str;
	int i = 0;
	for ( ; i < buf->line; ++i ) {
// 		printf("ReParse: %s\n", buf->data[i]->str );
		if( ( str = dstTok( buf->data[i], " \t" ) ) ) {
			switch( reqGetKeyword( str ) ) {
				case GET:
					req->method = GET;
					req->filename = dstInitCString2( dstTok( buf->data[i], " \t" ) );
					if ( !strcmp( "HTTP/1.0", dstTok( buf->data[i], " \t" ) ) ) {
						req->httpVersion = HTTP_10;
						req->connection = CLOSE;
					} else {
// 						req->httpVersion = HTTP_10;
// 						req->connection = CLOSE;
						req->httpVersion = HTTP_11;
						req->connection = KEEP_ALIVE;
					}
					
					break;
				case POST:
					req->method = POST;
					req->filename = dstInitCString2( dstTok( buf->data[i], " \t" ) );
					break;
				case CONNECTION:
					if ( !strcmp( dstTok( buf->data[i], " \t" ), "Keep-Alive" ) ) {
						req->connection = KEEP_ALIVE;
					}
					break;
				case CONTENT_LENGTH:
// 					printf("!!!LENGTH: %d\n", atoi( dstTok( buf->data[i], " \t" ) ) );
					req->contentLength = atoi( dstTok( buf->data[i], " \t" ) );
					break;
			}
		}
	}
	
	if ( req->method == POST && req->contentLength >= 0 ) {
		req->headerEnd = i;
		receive( client );
		return 1;
	} else if ( req->method != NONE &&  req->filename && req->filename->length ) {
		reqCalcRealFilename( client );
		response( client );
		return 1;
	}
	
	return 0;
}



enum Keyword reqGetKeyword( char* key )
{
	if( !strcmp( key, "GET" ) ) {
		return GET;
	}
	if ( !strcmp( key, "POST" ) ) {
		return POST;
	}
	if ( !strcmp( key, "HEAD" ) ) {
		return HEAD;
	}
	if ( !strcmp( key, "TRACE" ) ) {
		return TRACE;
	}
	if ( !strcmp( key, "ACCEPT_ENCODING:" ) ) {
		return ACCEPT_ENCODING;
	}
	if ( !strcmp( key, "Connection:" ) ) {
		return CONNECTION;
	}
	if ( !strcmp( key,  "Content-Length:" ) ) {
		return CONTENT_LENGTH;
	}

	return NONE;
}


void reqTestCompletness( struct Client* client )
{
	struct Buffer* buffer = &client->buffer;
	
	if ( buffer->line > 1 ) {
		if ( !buffer->data[buffer->line-1]->length ) {
			if ( !client->completeRequest ) {
				client->completeRequest = 1;

				if ( reqParse( client ) ) {
					bufReset( buffer );
					return;
				} else { /* Error while parsing.. no complete request! */
					client->completeRequest = 0;
				}
			}
		}
	}
}


void reqCalcRealFilename( struct Client* client )
{
	struct Request* req = &client->request;
	
	dstDel( req->systemFilename );
	
	req->systemFilename = dstInit( settings.path );
	dstAppend( req->systemFilename, req->filename->str );
	
	/* Test if itsdirectory */
	struct stat stBuf;
	int status = stat( req->systemFilename->str, &stBuf );
	if ( !status && S_ISDIR( stBuf.st_mode ) ) {
		/* If its end without a '/', then redirect! */
		if ( dstGetLastChar( req->systemFilename ) != '/' ) {
			client->response.redirect = 1;
			dstAppend( req->systemFilename, "/" );
		}
		
		dstAppend( req->systemFilename, settings.standardfile );
	}
	
}


const char* reqGetFileType( struct Request* req )
{
	const char* tmp = req->systemFilename->str;
	char* str = strrchr( tmp, '.' );
	if ( str ) {
		return str + 1;
	}

	return 0;
}
