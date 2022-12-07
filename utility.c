#include <stdio.h>
#include <string.h>
#include <ctype.h>	// isdigit()
#include "utility.h"

char* buffer;
FILE* fpt;

void giveError(char *error) {
	printf("Error: %s\n", error);
	exit(-1);
}

int isAlpha(char look) {
	int ascii = (int) look;
	if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122))
		return 1;
	return 0; // else
}

// Grab next char from read file
// *note* buffer is not cleared, only first bit in memeory is changed
void getNext() {
	fread(buffer, sizeof(char), 1, fpt);
}

// Put a string ('a-z') into buffer
void getWord() {
	int index = 0;
	memset(buffer, 0, sizeof(buffer));
	getNext();
	if (!isAlpha(*buffer))
		giveError("Expected alpha char...");
	while (isAlpha(*buffer)) {
		index++;
		buffer++;
		getNext();
	}
	if (*buffer != ' ')
		giveError("Expected alpha char...");
	buffer -= index;
}

// Put a number into buffer (as char)
void getNumber() {
	int index = 0;
	memset(buffer, 0, sizeof(buffer));
	getNext();
	if (!isdigit(*buffer))
		giveError("Expected number...");
	while (isdigit(*buffer)) {
		index++;
		buffer++;
		getNext();
	}
	if (*buffer != ' ')
		giveError("Expected number...");
	buffer -= index;
}

// 
void match(char *input) {
	if (strcmp(input, buffer) != 0)
		giveError("Expected expression");
	getWord();
}

void expression() {

	getNumber();
	printf("%s\n", buffer);
	getWord();
	printf("%s\n", buffer);
}

// Setup program
void init(const char *filename) {
	buffer = (char *) malloc(MSG_LEN);
	if ((fpt = fopen(filename, "r")) == NULL)		// Open read file
		giveError("File \'%s\' not found...");

	// TODO: open write to asm file

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