#ifndef _DOUBLY_LINKEDLIST_H
#define _DOUBLY_LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct doubly_linkedlist {
	int data;
	struct doubly_linkedlist *prev,
				 *next,
				 *tail;
} doubly_llist;

doubly_llist* doubly_linkedlist_create(int data);
void doubly_linkedlist_append(doubly_llist** doubly_linkedlist, int data);
void doubly_linkedlist_insertfront(doubly_llist** doubly_linkedlist, int data);
void doubly_linkedlist_remove(doubly_llist** doubly_linkedlist, int data);
void doubly_linkedlist_print(doubly_llist* doubly_linkedlist);
void doubly_linkedlist_destroy(doubly_llist** doubly_linkedlist);
#endif
