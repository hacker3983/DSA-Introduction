#ifndef _SINGLY_LINKEDLIST_H
#define _SINGLY_LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct singly_linkedlist {
	int value;
	struct singly_linkedlist *next, *tail;
} singly_llist;

singly_llist* singly_linkedlist_create(int value);
void singly_linkedlist_insertfront(singly_llist** singly_linkedlist, int value);
void singly_linkedlist_append(singly_llist** singly_linkedlist, int value);
void singly_linkedlist_remove(singly_llist** singly_linkedlist, int value);
void singly_linkedlist_print(singly_llist* singly_linkedlist);
void singly_linkedlist_destroy(singly_llist** singly_linkedlist);
#endif
