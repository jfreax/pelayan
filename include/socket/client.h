#ifndef CLIENT_H
#define CLIENT_H

#include <netinet/in.h>
#include <poll.h>

#include "http/buffer.h"
#include "http/request.h"
#include "http/response.h"
#include "intern/gzip.h"

#define BUFFER_SIZE 1000

struct Server;

/**
 * Save all information about one client.
 */
struct Client
{
	int clientID;
	int fdID;
		
	struct Server* server;
	struct pollfd* fd;
	
	struct sockaddr_in addr;	/**< Adressinformation */ 
	struct Buffer buffer;		/**< Buffer of all incoming messages */ 
	struct Compress cprBuffer;	/**<  */ 
	struct Request request;		/**<  */ 
	struct Response response;	/**<  */
	
	int isBlocked;
		
	int completeRequest;
};

/**
 * Store all #Client and the filedescriptor.
 * Only one instance per server!
 */
struct Connections
{
	int size;		/**< Number of total clients */ 
	int rSize;		/**< Reserved memory */ 
	
	struct Client* clients;	/**< */ 
};


/**
 * \memberof Client
 * Add a new client.
 * \param addr_ 
 * \param fd_ filedescriptor
 * \param conID connection id
 */
void clAdd( struct Server* server, struct sockaddr_in addr_, int fd_ );


/**
 * \memberof Client
 * Delete the client with the specified id.
 * \param id Client number
 * \param conID connection id
 */
void clDelete( struct Server* server, struct Client* client );


/**
 * \memberof Client
 * Remove the last element in the list.\n
 * Does not call #clDelete!
 * \param conID connection id
 */
void clPop( struct Server* server );


/**
 * \memberof Client
 * Check if we need more size to store the client or if we have too much reserved.
 * \param conID connection id
 * \return 0 No changes
 * \return 1 Changed the buffersize
 */
int clAdjustSize( struct Server* server );


#endif // CLIENT_H
