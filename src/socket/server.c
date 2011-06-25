#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/fcntl.h>
#include <poll.h>

#include <omp.h>

#include "intern/settings.h"
#include "socket/server.h"
#include "socket/client.h"
#include <socket/send.h>

int srvInit( struct Server* server, int master )
{
	server->maxThreads = omp_get_max_threads();

	/* TODO read settings from file! */
	if ( master ) {

		settings.sockID = socket( AF_INET, SOCK_STREAM, 0 );
		if ( settings.sockID < 0 ) {
			error_at_line( 0, 1, __FILE__, __LINE__, strerror( errno ), 0 );
			return 1;
		}

		settings.addr.sin_family = AF_INET;
		settings.addr.sin_port = htons( settings.port );
		settings.addr.sin_addr.s_addr = INADDR_ANY;

		settings.timeout = 100;
		settings.path = "./htdocs/";
		settings.standardfile = "index.html";
// 	settings.domain = "http://bigdaddy.ath.cx:8081";
		settings.domain = "localhost:8081";
		settings.bufferSize = 4096;

		socklen_t sockOpt = 1;
		setsockopt( settings.sockID, SOL_SOCKET, SO_REUSEADDR, &sockOpt, sizeof( sockOpt ) );

		if ( bind( settings.sockID, ( struct sockaddr * )&settings.addr, sizeof( settings.addr ) ) < 0 ) {
			error_at_line( 0, 1, __FILE__, __LINE__, strerror( errno ), 0 );
			return 1;
		}

		if ( listen( settings.sockID, 1024 ) < 0 ) {
			error_at_line( 0, 1, __FILE__, __LINE__, strerror( errno ), 0 );
			return 1;
		}
	}

	/* Init connections */
	int rSize = 256;
	memset( &server->con, 0, sizeof( struct Connections ) );
	server->con.size = 0;
	server->con.rSize = rSize;

	server->con.clients = calloc( server->con.rSize, sizeof( struct Client ) );
	for ( int k = 0; k < server->con.rSize; ++k ) {
		bufInit( &server->con.clients[k].buffer );
	}

	server->fds = malloc( rSize * sizeof( struct pollfd ) );
	memset( server->fds, 0, rSize * sizeof( struct pollfd ) );
	clAdd( server, settings.addr, settings.sockID );
	
	server->buffer = dstInitCString("");

	return 0;
}


int srvRun( struct Server* server )
{
	int size = 0;
	char buffer[BUFFER_SIZE];
	int x = 0;

// 	#pragma omp parallel shared(x)
	while ( 1 ) {
		x++;
		x %= 2;

		printf("Poll begin\n");
		for ( int i = 0; i < server->size; ++i ) {
			printf( "%d, \n", server->fds[i].fd );
// 			server->fds[i].events = POLLIN | POLLOUT;
		}
// 		server->fds[0].fd = settings.sockID;
		int ret = poll( server->fds, server->size, -1 );
		printf("\nPoll end\n");

		if ( server->fds[0].revents & POLLIN ) {
			if ( srvAccept( server ) || error_message_count != 0 )
				return 1;
		}

		for ( int i = 1; i < server->con.size; ++i ) {
// 			printf("For %d\n", server->con.clients[i].fd->fd);
			if ( server->con.clients[i].fd->revents & POLLIN ) {
				printf("\n -1 \n");
				size = read( server->con.clients[i].fd->fd, buffer, BUFFER_SIZE-1 );
				printf("\n 0 \n");

				if ( size <= 0 ) {
					clDelete( server, &server->con.clients[i] );
					printf("\n 1 \n");
					break;
				} else {

					write( 1, buffer, size );
					bufWrite( &server->con.clients[i].buffer, buffer, size );
					reqTestCompletness( &server->con.clients[i] );
				}

				int recret = receive( &server->con.clients[i] );
				if ( recret == 1 && server->con.clients[i].request.method == POST ) {
					clDelete( server->con.clients[i].server, &server->con.clients[i] );
					printf("BREAK\n");
					break;
				}

			} else if ( server->con.clients[i].fd->revents & POLLOUT ) {
				response( &server->con.clients[i] );
			} else if ( server->con.clients[i].fd->revents & POLLHUP ) {
				clDelete( server, &server->con.clients[i] );
				i = server->con.size; // exit for
			}
			if ( server->con.clients[i].fd->revents & POLLERR && server->con.clients[i].fd->fd != 0 ) {
				fprintf( stderr, "ERROR %d n %d\n", errno, server->con.clients[i].fd->fd );
// 				return 9;
			}
		}
	}
}


void srvStop( struct Server* server )
{

	for ( int i = 0; i < server->size; ++i ) {
		close( server->fds[i].fd );
	}

	close( settings.sockID );
	dstDel( server->buffer );

	/* TODO Speicher freigeben! */
}


int srvAccept( struct Server* server )
{
	int oldFlags = fcntl( settings.sockID, F_GETFL, O_NONBLOCK );
	fcntl( settings.sockID, F_SETFL, O_NONBLOCK | oldFlags );

	socklen_t sizeSock = sizeof( struct sockaddr_in );
	sizeSock = 0;
	int fd = -1;
	do {
		fd = accept( settings.sockID, ( struct sockaddr * ) & settings.addr, &sizeSock );

		if ( fd < 0 ) {
			if ( !( errno == EAGAIN  || errno == EWOULDBLOCK ) ) {
				error_at_line( 0, 1, __FILE__, __LINE__, strerror( errno ), 0 );
				return 1;
			}
		} else {
			clAdd( servers, settings.addr, fd );
		}
	} while ( fd > 0 );

	return 0;
}


void srvBroadcast( struct Server* server )
{
	printf("SEND BROADCAST!!!!!!!!\n");
	for ( int i = 1; i < server->con.size; ++i ) {
		if ( server->con.clients[i].isBlocked ) {
			struct Request* req = &server->con.clients[i].request;
			
			printf("Send to %d this: %s\n", server->con.clients[i].fd->fd, server->buffer->str );
			ssend( server->con.clients[i].fd->fd, server->buffer->str, server->buffer->length );
// 			ssend ( server->con.clients[i].fd->fd, "\r\n\r\n", 4 );
// 			clDelete( server->con.clients[i].server, &server->con.clients[i] );
		}	
// 		if ( server->con.clients[i].completeRequest )

	}
	for ( int i = 1; i < server->con.size; ++i ) {
		if ( server->con.clients[i].isBlocked ) {
			clDelete( server->con.clients[i].server, &server->con.clients[i] );
			i = 1; 
		}
	}
}

