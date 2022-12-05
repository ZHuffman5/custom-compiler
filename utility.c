#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

char* buffer;
size_t initialBufferAddr;

inline char *bufferReturn() {
	buffer -= ((size_t)buffer-initialBufferAddr); 
	return buffer;
} // returns buffer to beginning of string

void getInput() {
	*buffer = getchar();
	while (*buffer != ' ' && ((size_t)buffer-initialBufferAddr) < MSG_LEN) {
		buffer++;
		*buffer = getchar();
	}	
}

void init() {
	buffer = (char *) malloc(MSG_LEN);
	initialBufferAddr = (size_t) buffer;
	getInput();
}

/*
int readln(char *buffer, int size) {
	char c;
	int i = 0;

	while (i < size-1) {
		c = getchar();
		if (c == EOF || c == '\n') 
			break;
		buffer[i] = c;
		i++;
	} // end of while
	buffer[i] = '\0';
	return size;
}

// */