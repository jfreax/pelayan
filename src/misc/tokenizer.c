#include <stdlib.h>
#include <string.h>

#include "misc/tokenizer.h"
#include <stdio.h>


struct Tokenizer* tkInit( char* text, char token )
{
	struct Tokenizer* toc = calloc( 1, sizeof( struct Tokenizer ) );
// 	memset( toc, 0, sizeof( struct Tokenizer ) );
	
	toc->pos = 0;
	toc->text = text;
	toc->token = token;
	toc->oldToken = NULL;
	toc->firstNULL = 1;
	
	return toc;
}


char* tkGetNext( struct Tokenizer* tok )
{
// 	if ( tok->firstNULL ) {
// 		free( tok->oldToken );
// 		tok->oldToken = NULL;
// 	}
	
	char* str = &tok->text[tok->pos];
	char* nPos = strchr( str, tok->token );
	
	if ( !nPos ) {
		if ( tok->firstNULL ) {
			tok->firstNULL = 0;
			return str;
		} else {
// 			tkDel( tok );
			return NULL;
		}
	}
	
	int nSize = nPos - str + 1;
	if ( nSize > tok->reserved ) {
		tok->reserved = nSize;
		tok->oldToken = realloc( tok->oldToken, nSize * sizeof( char ) );
		memset( tok->oldToken, 0, nSize );
	}
	
	strncpy( tok->oldToken, str, nPos - str );
	tok->oldToken[nPos - str] = 0;
	tok->pos += nPos - str + 1;

	return tok->oldToken;
}


void tkDel( struct Tokenizer* tok )
{
	free( tok->oldToken );
	free( tok );
	
// 	tok->oldToken = NULL;
}

