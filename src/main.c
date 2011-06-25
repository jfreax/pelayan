#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include <error.h>
#include <string.h>

#include "main.h"
#include "intern/help.h"
#include "intern/settings.h"
#include "filetype.h"
#include "socket/server.h"
#include "socket/client.h"
// #include <misc/mstring.h>

#include <omp.h>

#include "intern/gzip.h"
#include <misc/dstring.h>

#define DEBUG

#ifdef DEBUG
	#define LOG
#endif

int main( int argc, char **argv )
{
	printf( "Number of threads: %d\n", omp_get_max_threads() );

	/* Parse commandline arguments */
	if ( argc == 1 ) {
		printHelp();
		return 0;
	}

	settings.port = 0;
	int opt;
	while (( opt = getopt( argc, argv, "hp:" ) ) != -1 ) {
		switch ( opt ) {
		case 'p':
			settings.port = atoi( optarg );
			break;
		case 'h':
			printHelp();
			return 0;
		default:
			break;

		}
	}

	if ( argc > 1 && !settings.port ) {
		exit( EXIT_FAILURE );
	}
	
	ftInit();
	ftAdd( "text", "html" );
	ftAdd( "text", "txt" );
	ftAdd( "text", "css" );
	ftAdd( "text", "js" );
	ftAdd( "image", "jpg" );
	ftAdd( "image", "png" );
	ftAdd( "application", "pdf" );
	
	
	servers[0].id = 1;
// 	servers[1].id = 2;
	
	srvInit( &servers[0], 1 );
// 	srvInit( &servers[1], 0 );

	int x = 0;
// 	#pragma omp parallel shared(x) 
// 	{
	srvRun( &servers[x++] );
// 	srvRun( &servers[x] );
// 	}
// 	
// 	if ( srvInit() || srvRun() || error_message_count != 0 )
// 		failure();
	
	srvStop( &servers[0] );
// 	srvStop( &servers[1] );


	return EXIT_SUCCESS;
}


void failure()
{
	printf( "Fehler: %s\n", strerror(errno) );
	error( EXIT_FAILURE, 0, "%u errors found", error_message_count );
}


// void writeLog( int id, char* text, int lvl )
// {
// 	for ( int i = 0; i < lvl; ++i ) {
// 		fprintf ( stderr, "\t" );
// 	}
// 	fprintf ( stderr, "(%d) %s", id, text );
// }



