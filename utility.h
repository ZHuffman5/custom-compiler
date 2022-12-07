#include <stdlib.h>
#define MSG_LEN 101 // last char of len is taken up by \0

extern char* buffer;
extern FILE* fp;
extern FILE* ofp;

int isAlpha(char);
void addop();
void getNext();
void getWord();
void giveError(char*);
void match(char*);
void init(const char *);
void expression();	
// int readln(char*, int);
