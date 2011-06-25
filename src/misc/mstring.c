#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <math.h>

#include "misc/mstring.h"
#include "misc/tokenizer.h"


char mstGetLast( char* text )
{
	return text[strlen( text )-1];
}

char* dynprint( const char *fmt, ... )
{
	/* Guess we need no more than 100 bytes. */
	int n, size = 100;
	char *p;
	va_list ap;
	if (( p = malloc( size ) ) == NULL )
		return NULL;
	while ( 1 ) {
		/* Try to print in the allocated space. */
		va_start( ap, fmt );
		n = vsnprintf( p, size, fmt, ap );
		va_end( ap );
		/* If that worked, return the string. */
		if ( n > -1 && n < size )
			return p;
		/* Else try again with more space. */
		if ( n > -1 )  /* glibc 2.1 */
			size = n + 1; /* precisely what is needed */
		else           /* glibc 2.0 */
			size *= 2;  /* twice the old size */
		if (( p = realloc( p, size ) ) == NULL )
			return NULL;
	}
}


// char* dprintf( const char* sig, ... )
// {
// 	int len = strlen( sig );
//
// 	va_list parameter;
// 	va_start( parameter, len );
//
// 	char* buffer = NULL;
// 	char* tokBuf;
// 	char* ret = malloc( sizeof ( char ) );
//
// 	ret[0] = 0;
//
// 	int iBuffer = 0;
// 	int isBufferOwn = 0;
// 	int size = 1;
//
// 	struct Tokenizer* tok = tkInit( sig, '%' );
// 	while( tokBuf = tkGetNext( tok ) ) {
//
// 		switch ( tokBuf[0] ) {
// 			case 's':
// 				buffer = va_arg( parameter, char* );
// 				size += strlen( buffer );
//
// 				tokBuf = tokBuf+1;
// 				break;
// 			case 'd':
// 				iBuffer = va_arg( parameter, int );
// 				buffer = malloc( 12 * sizeof( char ) );
// 				sprintf( buffer, "%d\0", iBuffer );
//
// 				tokBuf = tokBuf+1;
// 				break;
// 			default:
// 				buffer = NULL;
// 				break;
// 		}
//
// 		if ( buffer ) {
// 			size += strlen( buffer );
// 		}
// 		size += strlen( tokBuf );
// 		ret = realloc( ret, size * sizeof( char ) );
// 		if ( buffer ) {
// 			strcat( ret, buffer );
// 		}
// 		strcat( ret, tokBuf );
//
// 		if ( isBufferOwn )
// 			free( buffer );
//
// 	}
//
// 	tkDel( tok );
// 	va_end( parameter );
//
// 	return ret;
// }
