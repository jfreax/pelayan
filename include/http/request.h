#ifndef REQUEST_H
#define REQUEST_H

#include "socket/client.h"
#include "misc/dstring.h"


struct Client;

enum ConnectionType
{
	KEEP_ALIVE,
	CLOSE
};


enum Keyword
{
	NONE,
	GET,
	POST,
	HEAD,
	TRACE,
	ACCEPT_ENCODING,
	CONNECTION,
	CONTENT_LENGTH
};


enum HTTPVERSION
{
	HTTP_10,
	HTTP_11
};

/**
 * Parse and save all information about a request.
 */
struct Request
{
	int headerEnd;
	
	enum Keyword method;
	enum ConnectionType connection;
	enum HTTPVERSION httpVersion;
	
	struct DString* filename;
	struct DString* systemFilename;
	char* host;
	
	int contentLength;
};


/**
 * \memberof Request
 * Initialize a new request object
 * \param client Client
 */
void reqInit( struct Client* client );


/**
 * \memberof Request
 * Delete a request and free the memory.
 * \param client Client
 */
void reqDel ( struct Client* client );


/**
 * \memberof Request
 * Parse a request. Triggered only if the request is complete!
 * \param id Client
 */
int reqParse( struct Client* client );



/**
 * \memberof Request
 * Tranform an C-String to the equivalent keyword
 * \param key Keyword as C-string
 * \return The equivalent keyword as an enum
 */
enum Keyword reqGetKeyword( char* key );


/**
 * \memberof Request
 * Test if the HTTP header is complete
 * \param id Client
 */
void reqTestCompletness( struct Client* client );


/**
 * \memberof Request
 * 
 * \param dstr
 */
void reqCalcRealFilename( struct Client* client );


/**
 * \memberof Request
 * Get the filetype of requested file.
 * \param id Client
 */
const char* reqGetFileType( struct Request* req );


#endif // REQUEST_H