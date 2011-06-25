#include <string.h>
#include "filetype.h"
#include <stdlib.h>
#include <stdio.h>
#include <misc/tokenizer.h>


void ftInit()
{
	filetypes.categories = 0;
// 	int* aTypes = 0;
	filetypes.allCats = malloc( 20 * sizeof( char* ) );
	filetypes.allTypes = malloc( 50 * sizeof( char* ) );
	
	memset( filetypes.allCats, 0, 20 * sizeof( char* ) );
	memset( filetypes.allTypes, 0, 50 * sizeof( char* ) );
}


void ftAdd( char* categorie, char* type )
{
	/* search for categorie */
	int catExits = -1;
	for ( int i = 0; i < filetypes.categories; ++i ) {
		if ( !strcmp( filetypes.allCats[i], categorie ) ) {
			catExits = i;
			i = 1000; /* end for */
		}
	}

	if ( catExits == -1 ) {
		catExits = ftAddCategorie( categorie );
	}

	/* Type plus one space */
	char* buffer = malloc( (strlen( type )+1) * sizeof( char ) );
	strcpy( buffer, type );
	
	memcpy( buffer, type, strlen( type ) + 1 );
	buffer[strlen( type )] = ' ';

	/* Get memory to add type to categorie */
	int curLen = strlen( filetypes.allTypes[catExits] );
	filetypes.allTypes[catExits] = realloc( filetypes.allTypes[catExits], curLen + strlen( type ) + 2 );
	memset( filetypes.allTypes[catExits]+curLen, 0, strlen( type ) + 2 );

	/* Copy type into cat. */
	memcpy( &filetypes.allTypes[catExits][curLen], buffer, strlen( type ) + 1 );

	free( buffer );
}


int ftAddCategorie( char* categorie )
{
	filetypes.allCats[filetypes.categories] = malloc( (strlen( categorie )+1) * sizeof( char ) );
	strcpy( filetypes.allCats[filetypes.categories], categorie );
	filetypes.allTypes[filetypes.categories] = malloc( sizeof( char ) );
	filetypes.allTypes[filetypes.categories][0] = 0;

	return filetypes.categories++;
}


const char* ftGetCat( const char* type )
{
	for ( int i = 0; i < filetypes.categories; ++i ) {
		struct Tokenizer* tok = tkInit( filetypes.allTypes[i], ' ' );
		char* str = NULL;
		
		while( (str = tkGetNext( tok )) ) {
			if ( !strcmp( str, type ) ) {
				tkDel( tok );
				return filetypes.allCats[i];
			}
		}
		
		tkDel( tok );
	}
	
	return 0;
}
