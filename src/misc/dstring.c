#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "misc/dstring.h"



struct DString* dstInitCString( const char* str )
{
	struct DString* ret = malloc( sizeof( struct DString ) );
	
	ret->length = strlen( str );
	ret->size = 64 + ret->length;
	ret->str = malloc( (ret->size+2) * sizeof( char ) );
	strcpy( ret->str, str );
	
	ret->noDel = 0;
	ret->lastFound = 0;
		
	return ret;
}


struct DString* dstInitCString2( const char* str )
{
	struct DString* ret = malloc( sizeof( struct DString ) );
	
	ret->size = ret->length = strlen( str );
	ret->size--;
	ret->str = str;
	
	ret->noDel = 1;
	ret->lastFound = 0;
		
	return ret;
}


struct DString* dstInit( const char* fmt, ... ) {
	struct DString* ret = malloc( sizeof( struct DString ) );
	ret->noDel = 0;
	ret->size = 64;
	ret->lastFound = 0;
	ret->isLastTok = 0;

	if ( ( ret->str = malloc( ret->size ) ) == NULL ) {
		return NULL;
	}
	
	int n;
	while ( 1 ) {
		va_list ap;
		va_start( ap, fmt );
		n = vsnprintf( ret->str, ret->size, fmt, ap );
		va_end( ap );
		
		/* If that worked, return the string. */
		if ( n > -1 && n < ret->size ) {
			ret->length = strlen( ret->str );
			return ret;
		}
		
		/* Else try again with more space. */
		if ( n > -1 ) {
			ret->size = n + 1;
		} else {
			return NULL;
		}
		
		if ( ( ret->str = realloc( ret->str, ret->size ) ) == NULL ) {
			return NULL;
		}
	}
}


struct DString* dstInit2( const char* string )
{
	struct DString* ret = malloc( sizeof( struct DString ) );
	ret->str = string;
	ret->noDel = 1;	
	ret->length = strlen( string );
	ret->lastFound = 0;
		
	return ret;
}


void dstDel( struct DString* dstr )
{
	if ( !dstr )
		return;
	
	if ( !dstr->noDel ) {
		free( dstr->str );
	}
	dstr->str = NULL;
	
	free( dstr );
	dstr = NULL;
	
	dstInit( dstr );
}


void dstReset( struct DString* dstr )
{
	if ( !dstr )
		return;
	
	if ( dstr->str && dstr->length ) {
// 		memset( dstr->str, 0, dstr->size );
		dstr->str[0] = 0;
	}
	dstr->length = 0;

	dstr->lastFound = 0;
	dstr->isLastTok = 0;
}


struct DString* dstAppendCString( struct DString* dstr, const char* string )
{
	int curSpace = dstr->size - dstr->length -1;
	int nLen = strlen( string );
	
	if ( curSpace < nLen ) {
		dstr->size *= 2;
		dstr->str = realloc( dstr->str, dstr->size+1 );
	}
	
	strcpy( dstr->str+dstr->length, string );
	dstr->length += nLen;
	
	return dstr;
}


struct DString* dstAppend( struct DString* dstr, const char* fmt, ... )
{
	int curSpace = dstr->size - dstr->length -1;
	
	int n;
	while ( 1 ) {
		char* curStr = dstr->str + dstr->length;
		
		va_list ap;
		va_start( ap, fmt );
		n = vsnprintf( curStr, curSpace, fmt, ap );
		va_end( ap );
		
		/* If that worked, return the string. */
		if ( n > -1 && n < curSpace ) {
			dstr->length += n;
			return dstr;
		}
		
		/* Else try again with more space. */
		if ( n > -1 ) {
			dstr->size += n;
			curSpace = n + 1;
		} else {
			return NULL;
		}
		
		if ( ( dstr->str = realloc( dstr->str, dstr->size + curSpace +1 ) ) == NULL ) {
			return NULL;
		}
	}
}


char dstGetLastChar( struct DString* dstr )
{
	return dstr->str[dstr->length-1];
}


const char* dstTok( struct DString* dstr, const char* delimeters )
{
	char* string = dstr->str + dstr->lastFound;
	for( int i = 0; i < (dstr->length - dstr->lastFound); ++i ) {
		for( int k = 0; delimeters[k]; ++k ) {
			if( string[i] == delimeters[k] ) {
				string[i] = 0;
				dstr->lastFound += i+1;
				
				return string;
			}
		}
		
	}
	
	if ( dstr->lastFound < dstr->length ) {
		dstr->lastFound = dstr->length;
		return string;
	}
	
	return NULL;
}


const char* dstTok2( struct DString* dstr, const char* delimeters )
{
	int founded = 0, oldFounded;
	char* string = dstr->str + dstr->lastFound;
	for( int i = 0; i < (dstr->length - dstr->lastFound); ++i ) {
		oldFounded = founded;
		int k = 0;
		for( ; delimeters[k]; ++k ) {
			if( string[i] == delimeters[k] ) {
				string[i] = 0;
				
				++founded;
			}
		}
		
		if ( founded == oldFounded )
			founded = oldFounded = 0;
		
		if ( founded == k ) {
			dstr->lastFound += i+1;
			dstr->isLastTok = 0;
			return string;
		}
	}
	
	if ( dstr->lastFound < dstr->length ) {
		dstr->isLastTok = 1;
		dstr->lastFound = dstr->length;
		return string;
	}
	
	return NULL;
}