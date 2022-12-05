#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

LookBuffer buffer;

void init() {
	buffer.look = (char *) malloc(MSG_LEN);
	getInput();
}

void getInput() {
	buffer.look = getchar();
	buffer.index = 1;
}

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