#include <stdlib.h>
#define MSG_LEN 101 // last char of len is taken up by \0

extern char* buffer;    // Gets allocated static memory chunk at prgm start
extern FILE* fp;        // Read File Pointer
extern FILE* ofp;       // Output File pointer

int isAlpha(char);
int isAddop(char);
void addop();
void getNext();
void getWord();
void giveError(char*);
void match(char*);
void init(const char *);
void expression();	
// int readln(char*, int);
