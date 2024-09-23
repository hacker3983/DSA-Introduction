#include <stdio.h>
#include "doubly-linkedlist.h"

doubly_llist* doubly_linkedlist_create(int data) {
	doubly_llist *new_node = malloc(sizeof(doubly_llist));
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->tail = new_node;
	return new_node;
}

void doubly_linkedlist_insertfront(doubly_llist** doubly_linkedlist, int data) {
	doubly_llist* new_node = doubly_linkedlist_create(data);
	if(!(*doubly_linkedlist)) {
		*doubly_linkedlist = new_node;
		return;
	}
	new_node->next = (*doubly_linkedlist);
	new_node->tail = (*doubly_linkedlist)->tail;
	(*doubly_linkedlist)->prev = new_node;
	(*doubly_linkedlist) = new_node;
}

void doubly_linkedlist_append(doubly_llist** doubly_linkedlist, int data) {
	doubly_llist *new_node = doubly_linkedlist_create(data);
	if(!(*doubly_linkedlist)) {
		*doubly_linkedlist = new_node;
		return;
	}
	new_node->prev = (*doubly_linkedlist)->tail;
	(*doubly_linkedlist)->tail->next = new_node;
	(*doubly_linkedlist)->tail = new_node;
}

void doubly_linkedlist_remove(doubly_llist** doubly_linkedlist, int data) {
	doubly_llist *next = NULL,
			  *current = *doubly_linkedlist;
	if(!(*doubly_linkedlist)) {
		return;
	}
	if((*doubly_linkedlist)->data == data) {
		next = (*doubly_linkedlist)->next;
		next->prev = NULL;
		next->tail = (*doubly_linkedlist)->tail;
		free(*doubly_linkedlist);
		*doubly_linkedlist = next;
		return;
	}
	while(current->next) {
		next = current->next->next;
		if(current->next->data == data) {
			free(current->next);
			current->next = next;
			current->tail = current;
			if(next) {
				next->prev = current;
				next->tail = next;
			}
			break;
		}
		current = current->next;
	}
	current->tail = current;
}

void doubly_linkedlist_print(doubly_llist* doubly_linkedlist) {
	doubly_llist *prev = doubly_linkedlist->tail->prev;
	while(doubly_linkedlist) {
		printf("\033[32m%d\033[0m -> ", doubly_linkedlist->data);
		doubly_linkedlist = doubly_linkedlist->next;
	}
	printf("NULL\n");
	while(prev) {
		printf("\033[32m%d\033[0m <- ", prev->data);
		prev = prev->prev;
	}
	printf("NULL\n");
}

void doubly_linkedlist_destroy(doubly_llist** doubly_linkedlist) {
	doubly_llist* current = (*doubly_linkedlist),
		*next = NULL;
	while(current) {
		next = current->next;
		free(current);
		current = next;	
	}
	(*doubly_linkedlist) = NULL;
}
