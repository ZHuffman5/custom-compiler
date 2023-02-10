// Theme is "ayu"
#include <stdio.h>
#include <stdlib.h>
//#include "defs.h"

typedef struct Thing Thing;

struct Thing {
	struct OTHER { int item; } OTHER;
	int x;
};

#define tostr(x) #x

int main(int argc, char const *argv[])
{
	Thing t;
//	struct OTHER x = {22};
	t.OTHER.item = 24; 
	t.x = 69;
	//Thing t = {(other){.item=69}, 15};
	printf("bruh: %d and %d", t.OTHER, t.x);	
	int y = 69;
	char *z = tostr(21);
	#error "TF YOU DOIN"
	printf("\nString: %s and %s", tostr(y), z);
	return 0;


	ast_new((AST){AST_NUMBER, {.AST_NUMBER=(struct AST_NUMBER){  }}})
}