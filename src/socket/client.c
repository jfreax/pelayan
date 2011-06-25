#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "socket/client.h"
#include <socket/server.h>


void clAdd( struct Server* server, struct sockaddr_in addr_, int fd_ )
{

	fprintf( stdout, "New client (%d) - Total: %d - Thread: %d\n", fd_, server->con.size + 1, server->id );

	clAdjustSize( server );

	server->con.clients[server->con.size].addr = addr_;
	server->con.clients[server->con.size].completeRequest = 0;

	server->fds[server->size].fd = fd_;
	server->fds[server->size].events = POLLIN;

	reqInit( &server->con.clients[server->con.size] );
	resInit( &server->con.clients[server->con.size] );

// 	bufReset( &server->con.clients[server->con.size].buffer );
// 	bufDel( &server->con.clients[server->con.size].buffer );
	bufInit( &server->con.clients[server->con.size].buffer );
	server->con.clients[server->con.size].isBlocked = 0;

	server->con.clients[server->con.size].clientID = server->con.size;
	server->con.clients[server->con.size].server = server;
	server->con.clients[server->con.size].fd = &server->fds[server->size];
	server->con.clients[server->con.size].fdID = server->size;

	server->con.size++;
	server->size++;
}


void clDelete( struct Server* server, struct Client* client )
{
	if ( !server->con.size )
		return;
	
	fprintf( stdout, "Remove client (%d) - Total: %d - Thread: %d.............................................\n", client->fd->fd, server->con.size, server->id );

	int id = client->clientID;
	int fdID = client->fd->fd;
	close( fdID );

	/* Delete/Reset extern */
// 	bufReset( &client->buffer );
	bufDel ( &client->buffer );

	resDel( client );
	reqDel( client );
	cprDel( &client->cprBuffer );

	int oldFdID = client->fdID;

	if ( client->clientID != server->con.size - 1 ) {
		memcpy( client, &server->con.clients[server->con.size - 1], sizeof( struct Client ) );
		memcpy( &client->buffer, &server->con.clients[server->con.size - 1].buffer, sizeof( struct Buffer ) );

		client->buffer.data = server->con.clients[server->con.size - 1].buffer.data;
		client->clientID = id;
	}


	if ( oldFdID != server->size - 1 ) {
		memcpy( &server->fds[oldFdID], &server->fds[server->size-1], sizeof( struct pollfd ) );

		for ( int i = 0; i < server->con.size; ++i ) {
			if ( server->con.clients[i].fdID == server->size - 1 ) {
				server->con.clients[i].fdID = oldFdID;
				server->con.clients[i].fd = &server->fds[oldFdID];
			}
		}
	}

	clPop( server );
}


void clPop( struct Server* server )
{
	memset( &server->fds[server->size-1], 0, sizeof( struct pollfd ) );
// 	memset( &server->con[server->size-1], 0, sizeof( struct Client ) );
	
	server->con.size--;
	server->size--;
}


int clAdjustSize( struct Server* server )
{
	struct Connections* con = &server->con;
	int changed = 0, oldrSize = server->con.rSize;

	/* Grow size */
	if ( con->size >= con->rSize ) {
		server->rSize = con->rSize *= 2;
		changed = 1;
	} else if ( con->size < con->rSize / 4 && con->rSize > 8 ) {
// 		con.rSize /= 2;
// 		changed = 2;
	}

	if ( changed ) {

		if ( changed == 2 ) {
			for ( int i = con->rSize + 1; i < oldrSize; ++i ) {
				bufDel( &con->clients[i].buffer );
			}
		}

		con->clients = realloc( con->clients, ( con->rSize + 1 ) * sizeof( struct Client ) );
		server->fds = realloc( server->fds, ( ( con->rSize - oldrSize ) ) * sizeof( struct pollfd ) );

		memset( con->clients + con->size, 0, ( con->rSize - con->size ) * sizeof( struct Client ) );
		server->rSize += ( con->rSize - oldrSize );
		memset( server->fds + server->size, 0, ( server->rSize - server->size ) * sizeof( struct pollfd ) );

		if ( changed == 1 ) {
			for ( int i = oldrSize; i <= con->rSize; ++i ) {
				bufInit( &con->clients[i].buffer );
			}
		}

		return 1;
	}

	return 0;
}

