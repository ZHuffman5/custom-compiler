#define MSG_LEN 101 // last char of len is taken up by \0

char* buffer;
size_t initialBufferAddr;

void getInput();
void init();
void bufferReturn();
// int readln(char*, int);
