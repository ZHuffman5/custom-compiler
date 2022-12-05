#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

int main(int argc, char const *argv[])
{
	init();
	printf("%c\n", buffer.look);
	return 0;
}
