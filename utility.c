#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

char* buffer;

void getInput() {
	int index = 0;
	memset(buffer, 0, sizeof(buffer));

	buffer[index] = getchar();
	while (buffer[index] != ' ') {
		index++;
		buffer[index] = getchar();
	}
	buffer[index] = '\0';	
}

void giveError(char *error) {
	printf("Error: %s", error);
	exit(-1);
}

void match(char *input) {
	if (strcmp(input, buffer) != 0)
		giveError("Expected expression");
	getInput();
}

void expression() {

	match("+");
	printf("did plus");
	match("0");
	printf("\ndid other thing!");

}

void init() {
	buffer = (char *) malloc(MSG_LEN);
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