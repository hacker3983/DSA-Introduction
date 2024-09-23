#include <stdio.h>
#include "singly-linkedlist.h"

singly_llist* singly_linkedlist_create(int value) {
	singly_llist* new_node = malloc(sizeof(singly_llist));
	new_node->value = value;
	new_node->tail = new_node;
	new_node->next = NULL;
	return new_node;
}

void singly_linkedlist_insertfront(singly_llist** singly_linkedlist, int value) {
	singly_llist* new_node = singly_linkedlist_create(value);
	if(!(*singly_linkedlist)) {
		(*singly_linkedlist) = new_node;
		return;
	}
	new_node->next = (*singly_linkedlist);
	new_node->tail = (*singly_linkedlist)->tail;
	(*singly_linkedlist) = new_node;
}

void singly_linkedlist_append(singly_llist** singly_linkedlist, int value) {
	singly_llist *new_node = singly_linkedlist_create(value);
	if(!(*singly_linkedlist)) {
		(*singly_linkedlist) = new_node;
		return;
	}
	(*singly_linkedlist)->tail->next = new_node;
	(*singly_linkedlist)->tail = new_node;
}

void singly_linkedlist_remove(singly_llist** singly_linkedlist, int value) {
	singly_llist* ref = *singly_linkedlist,
		*next = NULL, *temp = NULL;
	if(ref && ref->value == value) {
		next = ref->next;
		free(ref); ref = NULL;
		(*singly_linkedlist) = next;
		return;
	}
	while(ref->next) {
		if(ref->next->value == value) {
			temp = ref->next,
			next = ref->next->next;
			ref->next = next;
			free(temp); temp = NULL;
			break;
		}
		ref = ref->next;
	}
}
void singly_linkedlist_print(singly_llist* singly_linkedlist) {
	while(singly_linkedlist) {
		printf("\033[32m%d\033[0m", singly_linkedlist->value);
		printf(" -> ");
		singly_linkedlist = singly_linkedlist->next;
	}
	printf("NULL\n");
}

void singly_linkedlist_destroy(singly_llist** singly_linkedlist) {
	singly_llist* temp = *singly_linkedlist;
	while(temp) {
		singly_llist* next = temp->next;
		free(temp);
		temp = next;
	}
	(*singly_linkedlist) = NULL;
}
