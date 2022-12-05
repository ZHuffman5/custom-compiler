#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

int main(int argc, char const *argv[])
{
	init();
	printf("%d\n", buffer.index);
	return 0;
}