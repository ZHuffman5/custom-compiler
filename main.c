#include <stdio.h>
#include "utility.h"


int main(int argc, char const *argv[])
{
	init(argv[1]);
	expression();
	fclose(fpt);
	return 0;
}
