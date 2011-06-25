#ifndef DSTRING_H
#define DSTRING_H

struct DString
{
	int noDel;
	
	char* str;		/**< C-string data */ 
	int length;		/**< Length of the current string */ 
	int size;		/**< Reserved memory */ 
	
// 	char* delimeters;
// 	int deliLen;
	int lastFound;
	
	int isLastTok;
};


struct DString* dstInitCString( const char* str );
struct DString* dstInitCString2( const char* str );
struct DString* dstInit( const char* fmt, ... );
struct DString* dstInit2( const char* string );
void dstDel( struct DString* dstr );
void dstReset( struct DString* dstr );

struct DString* dstAppendCString( struct DString* dstr, const char* string );
struct DString* dstAppend( struct DString* dstr, const char* fmt, ... );

char dstGetLastChar( struct DString* dstr );

const char* dstTok( struct DString* dstr, const char* delimeters );
const char* dstTok2( struct DString* dstr, const char* delimeters );



#endif // DSTRING_H