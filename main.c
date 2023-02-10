#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"

void init() {
	Buffer = (char *) malloc(buffer_size);
	init_buff_addr = (unsigned int *) Buffer;
}

void throwErr(char *err) {
	printf("\n%s\n", err);
	exit(0);
}

// Temp implementation
void loadBuffer(char *string) { 
	int index = 0;

	while (*string) {
		Buffer[index] = *string;
		string++;
		index++;
	} // end loop	
} // end loadBuffer()


// Reads next char in Buffer array in memory
// Returns initial pointed to char and then inc Buffer by 1 
char readNext() { 
	char c = *Buffer;
	Buffer++;
	return c;
} // end readNext()

void translateToken(token_type token_value) {
	switch (token_value) {
	case ERR:
		printf("ERR ");
		break;
	case INT_LIT:
		printf("INT_LIT ");
		break;
	case ALPHA_LIT:
		printf("ALPHA_LIT ");
		break;
	case ADDOP:
		printf("ADDOP ");
		break;
	case SIGNOP:
		printf("SIGNOP ");
		break;
	case MULLOP:
		printf("MULLOP ");
		break;
	case DIVOP:
		printf("DIVOP ");
		break;
	case COND_KEYWORD:
		printf("COND_KEYWORD ");
		break;
	case RETURN_KEYWORD:
		printf("RETURN_KEYWORD ");
		break;
	case INT_KEYWORD:
		printf("INT_KEYWORD ");
		break;
	case KEYWORD:
		printf("KEYWORD ");
		break;
	case EQ:
		printf("EQ ");
		break;
	case WS:
		printf("WS ");
		break;
	case END_IDENT:
		printf("END_IDENT ");
		break;
	default:
		printf("Error Finding Token... ");
		break;
	}
}

int getKeyword(char init_char, Token *token) {
	char buffer[buffer_size];
	char c = init_char;
	int index = 0;

	while (c >= 'a' && c <= 'z') {
		buffer[index++] = c;	
		c = readNext();
	}

	if (c != ' ') throwErr("Invalid Syntax After String Identifier...");

	token->keyword_content = buffer;

	if (strncmp(buffer, "return", 6) == 0) 
		return RETURN_KEYWORD;
	else if (strncmp(buffer, "int", 3) == 0) 
		return INT_KEYWORD;
	else if (strncmp(buffer, "if", 2) == 0)
		return COND_KEYWORD;
//	else
	return KEYWORD;
}

int getToken(char c) {
	switch (c) {
	case '0' ... '9':
		return INT_LIT;
	case 'a' ... 'z':
		return ALPHA_LIT;
	case ';':
		return END_IDENT;
	case ' ':
		return WS;
	case '=':
		return EQ;
	case '+':
		return ADDOP;
	case '-':
		return SIGNOP;
	case '*':
		return MULLOP;
	case '/':
		return DIVOP;
	default:
		return -1;
	}
}

void generateTokens(char *buffer) {
	Token tok;
	char c;
	int index;
	int val;

	c = readNext();
	index = 0;

	while (c) {
		val = getToken(c);

		if (val == ALPHA_LIT) 
			val = getKeyword(c, &tok);

		tok.token = val; 
		tokenlist[index++] = tok;

		c = readNext();
	} 
} 

int main(int argc, char const *argv[])
{
	init();

	char *statement = "int x = 5; if x + 5 =9; return 1;";
	loadBuffer(statement);

	printf("%s\n", Buffer);
	generateTokens(statement);

	int index = 0;
	while (tokenlist[index].token)
		translateToken(tokenlist[index++].token);

	printf("\n");
	return 0;
}
