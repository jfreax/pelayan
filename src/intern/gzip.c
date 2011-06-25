#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "http/buffer.h"
#include "intern/gzip.h"
#include <socket/client.h>
#include <stdlib.h>


#if defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(__CYGWIN__)
#  include <fcntl.h>
#  include <io.h>
#  define SET_BINARY_MODE(file) setmode(fileno(file), O_BINARY)
#else
#  define SET_BINARY_MODE(file)
#endif


struct Compress* cprInit( struct Compress* cpr, FILE* file )
{
	cpr->source = file;
	cpr->out = malloc( CHUNK );

	/* allocate deflate state */
	cpr->strm.zalloc = Z_NULL;
	cpr->strm.zfree = Z_NULL;
	cpr->strm.opaque = Z_NULL;
	int ret = deflateInit2( &cpr->strm, Z_DEFAULT_COMPRESSION, Z_DEFLATED, 15, 5, Z_DEFAULT_STRATEGY );
	if ( ret != Z_OK ) {
		return 0;
	}

	cpr->done = 0;
	return cpr;
}


int cprGetNext( struct Compress* cpr )
{
	int ret, flush;
	unsigned have;
	unsigned char in[CHUNK];
// 	unsigned char out[CHUNK];
	
	
// // 	/* OLD */
// 	if ( cpr->done >= con.clients[id].response.fileSize )
// 		return 0;
// // 
// // 	
// // 	uLong uncomprLen = CHUNK * sizeof( int );;
// // 
// 	have = fread( in, 1, CHUNK, cpr->source );
// // 	
// 	cpr->done += have;
// 		printf("Test: %d und %d\n", cpr->done, con.clients[id].response.fileSize );
// 		
// 	int x = gzwrite ( cpr->file, &in, have );
// // 	int x = gzputs( cpr->file, in );
// 	
// // 	gzflush( con.clients[id].cprBuffer.file, Z_NO_FLUSH );
// // 	 char * test = gzgets ( cpr->file, cpr->out, CHUNK);
// 	
// 	 printf("TESTDATA: %s\n", test);
// // 				int test = lseek( con.fds[id].fd, 0 , SEEK_END );
// // 			int size = lseek(con.fds[id].fd, 0L, SEEK_CUR);
// // 			lseek( con.fds[id].fd, 0 , 0 );
// 	
// // 	gzseek( cpr->file, 0 , SEEK_END );
// // 	int size = gztell( cpr->file );
// // 	int size = gzoffset( cpr->file );
// // 	gzrewind( cpr->file );
// 	
// 	
// // 		printf("Lala: %d\n", test);
// // 	return size;
// // 	
// // 	/* OLD END */
// 	
// // 	gzclose( cpr->file );
// // 	gzflush( cpr->file, Z_FULL_FLUSH );
// // 	cpr->file = gzdopen ( con.fds[id].fd, "wb");
// // 	
// // 
// // 	
// // 	compress OF(( cpr->out, &uncomprLen, in, CHUNK));
// // 	
// // 	return uncomprLen;


	/* STOP */
	
	cpr->strm.avail_in = fread( in, 1, CHUNK, cpr->source );
	if ( ferror( cpr->source ) ) {
		( void )deflateEnd( &cpr->strm );
// 			return Z_ERRNO;
		return 0;
	}
	flush = feof( cpr->source ) ? Z_FINISH : Z_NO_FLUSH;
	cpr->strm.next_in = in;

	cpr->strm.avail_out = CHUNK;
	cpr->strm.next_out = cpr->out;

	ret = deflate( &cpr->strm, flush );  /* no bad return value */
	if ( ret == Z_STREAM_ERROR )
		return 0;

	have = CHUNK - cpr->strm.avail_out;

	return have;
// 	return Z_OK;
}


void cprDel( struct Compress* cpr )
{
	deflateEnd( &cpr->strm );
	free( cpr->out );
	
// 	gzclose( cpr->file );
}


void zerr( int ret )
{
	fputs( "zpipe: ", stderr );
	switch ( ret ) {
	case Z_ERRNO:
		if ( ferror( stdin ) )
			fputs( "error reading stdin\n", stderr );
		if ( ferror( stdout ) )
			fputs( "error writing stdout\n", stderr );
		break;
	case Z_STREAM_ERROR:
		fputs( "invalid compression level\n", stderr );
		break;
	case Z_DATA_ERROR:
		fputs( "invalid or incomplete deflate data\n", stderr );
		break;
	case Z_MEM_ERROR:
		fputs( "out of memory\n", stderr );
		break;
	case Z_VERSION_ERROR:
		fputs( "zlib version mismatch!\n", stderr );
	}
}

