#ifndef SERVER_H
#define SERVER_H

#include <poll.h>
#include "socket/client.h"


/**
 * Server struct - STUB!
 */
struct Server {
	int id;
	int maxThreads;
	
	struct Connections con;
	struct pollfd* fds;		/**< Arraystructure for poll() */ 
	int size;				/**< Number of total clients */ 
	int rSize;
	
	struct DString* buffer;
	
} servers[2];


/**
 * \memberof Server
 * Initialize the server. Set up some standardvalues. Create a new socket (fd=0) and get some space for #Connections und #Client
 */
int srvInit( struct Server* server, int master );


/**
 * \memberof Server
 * Run the server!
 */
int srvRun( struct Server* server );


/**
 * \memberof Server
 * Stop the server. Free some memory. Never called :(
 */
void srvStop( struct Server* server );


/**
 * \memberof Server
 * Accept a new client.
 */
int srvAccept( struct Server* server );


/**
 * \memberof Server
 * Send broadcast message to all blocked clients
 */
void srvBroadcast( struct Server* server );

#endif // SERVER_H