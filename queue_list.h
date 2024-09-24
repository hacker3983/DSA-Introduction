#ifndef _QUEUE_LIST_H
#define _QUEUE_LIST_H
#include "list.h"

typedef struct queue_list {
	list_t list;
} queue_list;

void queue_list_enqueue(queue_list* queue, int value);
bool queue_list_dequeue(queue_list* queue, int* removed_value);
bool queue_list_peek(queue_list queue, int* peeked_value);
bool queue_list_isempty(queue_list queue);
size_t queue_list_size(queue_list queue);
void queue_list_print(queue_list queue);
void queue_list_destroy(queue_list* queue);
#endif
