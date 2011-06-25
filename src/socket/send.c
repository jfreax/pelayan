#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

#include "socket/send.h"


void ssend( int fd, char* str, int len )
{
	(void)signal(SIGPIPE, SIG_IGN);
	
	printf( "SEND START!!!!!!!!!!\n");
// 	printf( "%s | id %d\n", str, fd );
// 	printf( "SEND END!!!!!!!!!!\n");
// 	printf("SENNND: %s\n", str );
// 	write( 1, str, len );
	int ret = write( fd, str, len );
	if ( ret <= 0 ) {
		fprintf( stderr, "Can note write to fd %d. Errno: %d -> %s\n", fd, errno, strerror(errno) );
	}
}
