#include <stdlib.h>

#define buffer_size 256

typedef enum {
	ERR, // 0 or null
	INT_LIT, 
	ALPHA_LIT,
	ADDOP,
	SIGNOP,
	MULLOP,
	DIVOP,
	COND_KEYWORD, // if statement
	RETURN_KEYWORD,
	INT_KEYWORD, 
	KEYWORD,
	EQ, // Equal Sign
	WS, // white space
	END_IDENT
} token_type;

typedef struct {
	token_type token;
	char *keyword_content;	
	int intVal;
} Token;

Token tokenlist[100];

int *init_buff_addr;
char *Buffer;
