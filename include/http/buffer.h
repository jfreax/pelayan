#ifndef BUFFER_H
#define BUFFER_H
#include <misc/dstring.h>

/**
 * Buffer structure to hold C-strings in different lines.
 */
struct Buffer
{
// 	int id;		/**< Client number */ 
	
	int size;	/**< Size of the current line */ 
	int rSize;	/**< Reserved size of the current line */ 

	int line;	/**< Current line number */ 
	int rLine;	/**< Reserved number of lines */
	
// 	int* lSizes;/**< Array of sizes for each line */ 

	struct DString** data;
// 	char** data;/**< Array of C-strings. One string per line. */ 
};


/**
 * \memberof Buffer
 * Initialize the buffer with empty data and malloc some memory.\n
 * \param id Client
 */
void bufInit( struct Buffer* buffer );


/**
 * \memberof Buffer
 * Delete the buffer and free all memory (hopefully).
 * \param id Client
 */
void bufDel( struct Buffer* buffer );


/**
 * \memberof Buffer
 * Reset all information
 * \param id Client
 */
void bufReset( struct Buffer* buffer );


/**
 * \memberof Buffer
 * Add text to the buffer. Recognize CRLF and add a new line.
 * \param id Client
 * \param text (Not nullterminated) C-string to add
 * \param size Size of the string
 */
void bufWrite( struct Buffer* buffer, char* text, int size );


/**
 * \memberof Buffer
 * Add a new line. \n
 * If two lines are empty, then call reqParse().
 * \return 0 No error
 * \return 1 Init buffer
 * \relates Buffer
 */
int bufNewline ( struct Buffer* buffer );


#endif // BUFFER_H