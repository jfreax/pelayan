#ifndef RESPONSE_H
#define RESPONSE_H

#include <stdio.h>
#include "buffer.h"

struct Client;

/**
 * HTTP Statuscodes
 */
enum HTTPCODE
{
	OK = 200,
	
	MOVED_PERMANENTLY = 301,
	FOUND = 302,
	
	FORBIDDEN = 403,
	NOTFOUND = 404
};


/**
 * Handle the response to the client.
 */
struct Response
{
	int sended;
	
	char* filename;
	char* sysFilename;
	FILE *file;
	int fileSize;

	struct DString* header;
	
	int noType; /* for status sites like 404 */
	int redirect;
	int noContent;
	int compressed;
	
	int received;
};


/**
 * \memberof Response
 * Initialize a new response object
 * \param id Client
 */
void resInit( struct Client* client );


/**
 * \memberof Response
 * Delete a response and free some memory. Does not close the #file!
 * \param id Client
 */
void resDel( struct Client* client );

/**
 * \memberof Response
 * 
 */
int receive( struct Client* client );


/**
 * \memberof Response
 * Checks for example if file exists or file not a directory is...\n
 * Then send an answer to client.
 * \param id Client
 */
void response( struct Client* client );


/**
 * \memberof Response
 * 
 * \param id Client
 */
void resClose( struct Client* client );


/**
 * \memberof Response
 * Send the content
 * \param id Client
 */
int resSendFile( struct Client* client );


/**
 * \memberof Response
 * Send the HTTP header
 * \param id Client
 */
void resSendHeader( struct Client* client );


/**
 * \memberof Response
 * Send a CRLF
 * \param id Client
 */
void resSendEnd( struct Client* client );


/**
 * \memberof Response
 * Send the size in hexadecimal of the next chunk
 * \param id client
 * \param size Size of content to send
 */
void resSendChunksize( struct Client* client, int size );


/**
 * \memberof Response
 * Send the http status
 * \param id Client
 * \param status HTTP status code
 */
void resAddStatus( struct Response* res, enum HTTPCODE status );


/**
 * \memberof Response
 * Send the http header "Content-Type"
 * \param id Client
 */
void resAddType( struct Response* res, const char* type, const char* cate );


/**
 * \memberof Response
 * Send the http header "Content-Length"
 * \param id client
 * \param size Size of content to send
 */
void resAddLength( struct Response* res, int size );


/**
 * \memberof Response
 * Send the http header "Content-Encoding:"
 * \param id client
 */
void resAddEncoding( struct Response* res );


/**
 * \memberof Response
 * Send the http header "Location"
 * \param id Client
 * \param location New location (complete URI)
 */
void resAddNewLocation( struct Response* res, char* location );


/**
 * \memberof Response
 * Send the http header "Accept-Ranges"
 * \param res Response object
 */
void resAddAcceptRange( struct Response* res );


/**
 * \memberof Response
 * Send the http header "Connection" if "keep-alive" is enabled
 * \param client Client
 */
void resAddConnection( struct Client* client );


/**
 * \memberof Response
 * Change filename und send this one.
 * \param id Client
 * \param filename New filename to send
 */
void resRetryWFilename( struct Client* client, const char* filename );


#endif // RESPONSE_H