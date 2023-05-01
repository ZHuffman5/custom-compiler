#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

Node *addNode(int data, Lnlist *list) {
	Node *new = malloc(sizeof(Node));
	if (new == NULL)
		return NULL;	

	if (list->head)
		new->next =	list->head;

	new->data = data;
	list->head = new;
	list->length += 1;

	return new;
}

Node *insertNode(int data, int index, Lnlist *list) {
	Node *current;
	Node *new = malloc(sizeof(Node));
	if (new == NULL)
		return NULL;

	if (index > list->length || index < 0) {
		printf("Index out of bounds...\n");
		return NULL;	
	}

	current = list->head;
	for (int i=0; i<index-1; i++) 
		current = current->next;

	new->next = current->next;	// current is node before index
	current->next = new;

	new->data = data;
	list->length += 1;
	return new;
}

Node *replaceNode(int data, int index, Lnlist *list) {
	Node *current;
	Node *tbr;					// "to be replaced"
	Node *new = malloc(sizeof(Node));
	if (new == NULL)
		return NULL;

	if (index > list->length || index < 0) {
		printf("Index out of bounds...\n");
		return NULL;	
	}

	current = list->head;
	for (int i=0; i<index-1; i++) 
		current = current->next;

	tbr = current->next;		// current is node before index
	new->next = tbr->next;		 
	current->next = new;
	new->data = data;
	list->length += 1;

	free(tbr);					// cleaning up 
	tbr = NULL;
	return new;	
}

void removeNode(int index, Lnlist *list) {
	Node *current;
	Node *tbr;					// "to be removed"

	if (index > list->length || index < 0) {
		printf("Index out of bounds...\n");
		return;	
	}

	current = list->head;
	for (int i=0; i<index-1; i++) 
		current = current->next;

	tbr = current->next;		// current is node before index
	current->next = tbr->next;
	list->length -= 1;

	free(tbr);					// cleaning up 
	tbr = NULL;
}

void removeHead(Lnlist *list) {
	removeNode(0, list);
}

int getNode(int index, Lnlist *list) {
	Node *current = list->head;
	for (int i=0; i<index; i++)
		current = current->next;

	return current->data;
}

void listNodes(Lnlist *list) {
	Node *current = list->head;

	while (current != NULL) { 
		printf("%d->", current->data);
		current = current->next;
	}			
	printf("END\n");
}