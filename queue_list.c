#include "queue_list.h"

void queue_list_enqueue(queue_list* queue, int value) {
	list_append(&queue->list, value);
}

bool queue_list_dequeue(queue_list* queue, int* removed_value) {
	if(queue_list_isempty(*queue)) {
		return false;
	};
	list_t new_list = {0};
	*removed_value = queue->list.array[0];
	for(size_t i=1;i<queue->list.count;i++) {
		list_append(&new_list, queue->list.array[i]);
	}
	list_destroy(&queue->list);
	queue->list.array = new_list.array;
	queue->list.count = new_list.count;
	queue->list.init = new_list.init;
	return true;
}

bool queue_list_peek(queue_list queue, int* peeked_value) {
	if(queue_list_isempty(queue)) {
		return false;
	}
	*peeked_value = queue.list.array[0];
	return true;
}

bool queue_list_isempty(queue_list queue) {
	if(!queue.list.init || !queue.list.array || !queue.list.count) {
		return true;
	}
	return false;
}

size_t queue_list_size(queue_list queue) {
	return queue.list.count;
}

void queue_list_print(queue_list queue) {
	list_print(queue.list);
}

void queue_list_destroy(queue_list* queue) {
	list_destroy(&queue->list);
}
