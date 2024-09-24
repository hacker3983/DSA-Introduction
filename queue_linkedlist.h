#ifndef _QUEUE_LINKEDLIST_H
#define _QUEUE_LINKEDLIST_H
#include "singly-linkedlist.h"

typedef struct queue_linkedlist {
	singly_llist* list;
	size_t size;
} queue_linkedlist;

void queue_linkedlist_enqueue(queue_linkedlist* queue, int value);
bool queue_linkedlist_dequeue(queue_linkedlist* queue, int* removed_value);
size_t queue_linkedlist_size(queue_linkedlist queue);
bool queue_linkedlist_isempty(queue_linkedlist queue);
bool queue_linkedlist_peek(queue_linkedlist queue, int* peeked_value);
void queue_linkedlist_print(queue_linkedlist queue);
void queue_linkedlist_destroy(queue_linkedlist* queue);
#endif
