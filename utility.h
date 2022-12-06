#define MSG_LEN 101 // last char of len is taken up by \0

extern char* buffer;
extern size_t initialBufferAddr;

void getInput();
void init();
char *bufferReturn();
// int readln(char*, int);
