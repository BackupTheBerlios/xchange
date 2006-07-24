#ifndef __TABELA_H
#define __TABELA_H

enum tbl_special
{
	LINEFEED=1,
	NEXTMSG=2,
	//TODO: Include the others....
};

/**
 * \brief An element of table.
 * \field text means the real text in a visual encoding
 * \field binary means how it is actually encoded in the binary file
 * 
 * In order to support any text encoding, textsize and binsize must
 * hold the size in bytes of text and binary fields.
 */
typedef struct tbl_entry
{
	char* text;
	int binary;
	int binsize;
	int textsize;
	enum tbl_special special; //> special entry
	//int textlength needed?
} Tbl_Entry;	

/**
 *
 * 
 * 
 */
typedef enum tbl_format
{
	THINGY = 1,
	HEXPOSURE = 2,
	TABULAR = 3,
} Tbl_Format;

/**
 * \brief A table that binds a binary encoding to a computer string ("visual") encoding
 * 
 * \field filename: table file name (full or relative path)
 * \field fhandle: table file handler to file manipulation
 * \field entries: the table elements (see Table_Entry)
 */
typedef struct table
{
	char *filename;
	FILE *fhandle;
	Tbl_Format format;
	Tbl_Entry *entries;
	// ENCODING?
} Table;

Table *tbl_load (char * filename);
int tbl_unload (Table &t);
char* tbl_getEntry (int index);
int tbl_getIndex (char *entry);
char* tbl_translate (int binary[]);
int* tbl_translate (char* string);

#endif // __TABELA_H
