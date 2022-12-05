#include <stdio.h>
#include "utility.h"

char look;

void getInput() {
	look = getchar();
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