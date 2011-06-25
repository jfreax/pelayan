#ifndef GZIP_H
#define GZIP_H

#include <http/buffer.h>
#include "zlib.h"

#define CHUNK 16384

/**
 * Compresses data in gzip format.
 */
struct Compress {
	unsigned char* out;
	
	z_stream strm;
// 	struct Buffer out;
	
	FILE *source;
	gzFile file;
	int done;
};


/**
 * \memberof Compress
 * Initialize all ressources for a new compress object
 * \param id Client
 */
struct Compress* cprInit( struct Compress* cpr, FILE* file );



/**
 * \memberof Compress
 * Destructor of a Compress object.
 * \param id Client
 */
void cprDel( struct Compress* cpr );


/**
 * \memberof Compress
 * Decompress from file until stream ends or EOF.
 * \return returns Z_OK on success, Z_MEM_ERROR if memory could not be
 * allocated for processing, Z_DATA_ERROR if the deflate data is
 * invalid or incomplete, Z_VERSION_ERROR if the version of zlib.h and
 * the version of the library linked do not match, or Z_ERRNO if there
 * is an error reading or writing the files.
 */
int cprGetNext( struct Compress* cpr );


/**
 * \memberof Compress
 * Print the error of a zlib error code
 * \param ret zlib error code
 */
void cprError( int ret );

#endif // GZIP_H

