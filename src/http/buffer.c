#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "socket/client.h"
#include "http/buffer.h"
#include "http/request.h"



void bufInit( struct Buffer* buffer  )
{	
	buffer->line = -1;
	buffer->rLine = 16;
	buffer->data = malloc( (buffer->rLine+2) * sizeof( struct DString ) );
	for ( int i = 0; i < buffer->rLine; ++i ) {
		buffer->data[i] = dstInitCString( "" );
	}
	
	bufNewline( buffer );
}


void bufDel( struct Buffer* buffer )
{
	if ( !buffer->data )
		return;
	
	for ( int i = 0; i < buffer->rLine; ++i ) {
		dstDel( buffer->data[i] );
	}
	
	buffer->rLine = buffer->line = 0;
	
	free( buffer->data );
	buffer->data = 0;
	
	bufInit( buffer );
}


void bufReset( struct Buffer* buffer )
{
	if ( !buffer->data )
		return;
	
	/* TODO dont do this :( */
	bufDel( buffer );
	bufInit( buffer );
	return;
	
	for ( int i = 0; i < buffer->rLine; ++i ) {
		dstReset( buffer->data[i] );
		free ( buffer->data[i] );
	}
	
	buffer->line = -1;
	bufNewline( buffer );
}


void bufWrite( struct Buffer* buffer, char* text, int size )
{
	printf("buffer line: %d und rLine: %d\n", buffer->line, buffer->rLine );
// 	int oldSize = buffer->size;
// 	int lastFound = 0, lastBR = -2;
		
	text[size] = '\0';
	struct DString* nstr = dstInitCString( text );
	
	char* tok;
	printf("\n 4 \n");
	while ( (tok = dstTok2( nstr, "\r\n" )) ) {
		if ( !buffer->data[buffer->line] ) {
			dstInitCString( tok );
		} else {
			dstAppendCString( buffer->data[buffer->line], tok );
		}

		if ( !nstr->isLastTok ) {
			bufNewline( buffer );
		}
	}
	printf("\n 5 \n");
	dstDel( nstr );
}


int bufNewline( struct Buffer* buffer )
{
// 	int oldSize = buffer->size;
	
	buffer->line++;
	buffer->size = 0;
	buffer->rSize = 128;
	
	if ( buffer->line >= buffer->rLine ) {
		int oldR = buffer->rLine;
		buffer->rLine *= 2;
				
		buffer->data = realloc( buffer->data, ( buffer->rLine + 2 ) * sizeof( struct DString* ) );
		for( int i = oldR; i < buffer->rLine; ++i ) {
			buffer->data[i] = NULL;
		}
	}

	return 0;
}

