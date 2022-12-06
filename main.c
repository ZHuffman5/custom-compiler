#include <stdio.h>
#include <stdlib.h>
#include "utility.h"



int main(int argc, char const *argv[])
{
	init();
	printf("%s\n", bufferReturn());
	return 0;
}
