#define MSG_LEN 101 // last char of len is taken up by \0

extern char* buffer;

void getInput();
void giveError(char*);
void match(char*);
void init();
void expression();	
// int readln(char*, int);
