#include "queue_linkedlist.h"

void queue_linkedlist_enqueue(queue_linkedlist* queue, int value) {
	singly_linkedlist_append(&queue->list, value);
	queue->size++;
}

bool queue_linkedlist_dequeue(queue_linkedlist* queue, int* removed_value) {
	if(!queue->list || !queue->size) {
		return false;
	}
	singly_llist* next = queue->list->next;
	next->tail = queue->list->tail;
	*removed_value = queue->list->value;
	free(queue->list);
	queue->list = next;
	queue->size--;
	return true;
}
size_t queue_linkedlist_size(queue_linkedlist queue) {
	return queue.size;
}

bool queue_linkedlist_isempty(queue_linkedlist queue) {
	if(!queue.list || !queue.size) {
		return true;
	}
	return false;
}
bool queue_linkedlist_peek(queue_linkedlist queue, int* peeked_value) {
	if(!queue.list) {
		return false;	
	}
	*peeked_value = queue.list->value;
	return true;
}

void queue_linkedlist_print(queue_linkedlist queue) {
	singly_linkedlist_print(queue.list);
}

void queue_linkedlist_destroy(queue_linkedlist* queue) {
	singly_linkedlist_destroy(&queue->list);
}
