#ifndef TOKENIZER_H
#define TOKENIZER_H

/**
 * Split a C-string.
 */
struct Tokenizer
{
	char* text;
	char* oldToken;
	char token;
	int pos;
	
	int reserved;
	
	int firstNULL;
};


struct Tokenizer* tkInit( char* text, char token );
char* tkGetNext( struct Tokenizer* tok );
void tkDel( struct Tokenizer* tok );

#endif // TOKENIZER_H