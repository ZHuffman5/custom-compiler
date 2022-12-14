#include <stdio.h>
#include <string.h>
#include <ctype.h>	// isdigit()
#include "utility.h"

char* buffer;
FILE* fp;
FILE* ofp;

// Output error and stop program execution
void giveError(char *error) {
	printf("Error: %s\n", error);
	exit(-1);	// exit code of -1
}

// Check if char is a-z or A-Z char
// return 1 if true, 0 if false
int isAlpha(char look) {
	int ascii = (int) look;		// convert char to ascii code
	if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122))
		return 1;
	return 0; // else
}

// Checks if char is an addop operation char
int isAddop(char look) {
	if (look == '+' || look == '-')
		return 1;
	return 0; // else
}

// Grab next char from read file
// *note* buffer is not cleared, only first bit in buffer memory chunk is changed
void getNext() {
	fread(buffer, sizeof(char), 1, fp);
}

// Put a string ('a-z') into buffer
void getWord() {
	int index = 0;
	memset(buffer, 0, sizeof(buffer));
	getNext();
	if (!isAlpha(*buffer))		// error catching for debug purposes
		giveError("Expected alpha char...");
	while (isAlpha(*buffer)) {
		index++;
		buffer++;
		getNext();
	}
	if (*buffer != ' ')		// error catching for debug purposes
		giveError("Expected alpha char...");
	buffer -= index;		// reset memory position pointed at to beginning of buffer block
}

// Put a number into buffer (as char)
void getNumber() {
	int index = 0;
	memset(buffer, 0, sizeof(buffer));
	getNext();
	if (!isdigit(*buffer))
		giveError("Expected number...");
	else if (*buffer == '+' || *buffer == '-')
		addop();
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

// parse and translate a addop or signop
void addop() {

}

void factor() {

}

void expression() {	
	while (isAddop(*look)) {
		switch (*look) {
			case '+': 
				add();
				break;
			case '-':
				sub();
				break;
			default:
				break;
		}// end switch			
	}// end while
	factor();	
}

// Setup program
void init(const char *filename) {
	buffer = (char *) malloc(MSG_LEN);
	if ((fp = fopen(filename, "rb")) == NULL)		// Open read file
		giveError("File \'%s\' not found...");

	if ((ofp = fopen("wb")) == NULL)					// Open output file
		giveError("Failed creating output asm file...");
	getNext();
}

// Old input reader
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
