#include <stdio.h>
#include <stdlib.h>

typedef struct NODE NODE;

struct NODE {
	enum {
		MAIN,
		NUM_LIT,
		ADD,
		MULS
	} token;
	union {
		struct MAIN { NODE *body; } MAIN;
		struct NUM_LIT { int num; } NUM_LIT;
		struct ADD { NODE *left; NODE *right; } ADD;
		struct MULS { NODE *left; NODE *right; } MULS;
	} data; 
};

NODE *create_node(NODE n) {
	NODE *new_node = malloc(sizeof(NODE));
	if (new_node)
		*new_node = n;
	return new_node;
}

#define CREATE_NODE(token, ...) create_node((NODE) {token, {.token=(struct token){__VA_ARGS__}}})

int main(int argc, char const *argv[])
{
	NODE *t = CREATE_NODE(MAIN, CREATE_NODE(NUM_LIT, 24));	
    NODE *val;
	val = t->data.MAIN.body;
	printf("worked... maybe,\nValue: %d\n", val->data.NUM_LIT.num);
	return 0;
}

