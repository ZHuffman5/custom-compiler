typedef struct {
	void *next;
	int data;
} Node;

typedef struct {
	Node *head;
	int length;
} Lnlist;

Node *addNode(int, Lnlist*);
Node *insertNode(int, int, Lnlist*);
Node *replaceNode(int, int, Lnlist*);
void removeNode(int, Lnlist*);
void removeHead(Lnlist*);
int getNode(int, Lnlist*);
void listNodes(Lnlist*);