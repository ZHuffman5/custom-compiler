#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

int main(int argc, char const *argv[])
{
	char *msg = (char *) malloc(msg_len);
	readln(msg, msg_len);
	printf("%s\n",msg);
	return 0;
}