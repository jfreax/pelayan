#ifndef FILETYPE_H
#define FILETYPE_H

/**
 * All information about the filetypes. File-end, the categorie and the mime-type.
 * Only one instance per server!
 */
struct Filetype
{
	int categories;
	int* aTypes;
	char** allCats;
	char** allTypes;
	
} filetypes;


void ftInit();

void ftAdd( char* categorie, char* type );
int ftAddCategorie ( char* categorie );

const char* ftGetCat( const char* type );


#endif // FILETYPE_H