#define MSG_LEN 101 // last char of len is taken up by \0

typedef struct {

	size_t index;
	char* look;

} LookBuffer; 

LookBuffer buffer;

void init();
void getInput();
int readln(char*, int);
