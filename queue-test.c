#include <stdio.h>
#include "utility.h"

void test_queue_list() {
	printf("\t\t\t\033[34mQueue List\033[0m\n");
	printf("-------------------------------------------------------\n");
	queue_list queue = {0};
	int enqueue_list[] = {14, 17, 70, 83, 34, 85, 57, 27, 97, 92};
	size_t enqueue_count = sizeof(enqueue_list)/sizeof(int);
	printf("Queue before initialization:\n");
	queue_list_print(queue);
	printf("Queue is empty: %s\n", queue_list_isempty(queue) ? "True" : "False");
	printf("Queue after initialization:\n");
	for(size_t i=0;i<enqueue_count;i++) {
		queue_list_enqueue(&queue, enqueue_list[i]);
	}
	queue_list_print(queue);
	printf("Sizeof queue: %zu\n", queue_list_size(queue));
	printf("Queue is empty: %s\n", queue_list_isempty(queue) ? "True" : "False");
	int peeked_value = 0;
	if(queue_list_peek(queue, &peeked_value)) {
		printf("Peeked value in queue is %d\n", peeked_value);
	}

	for(size_t i=0;i<enqueue_count/2;i++) {
		int removed_value =  0;
		if(queue_list_dequeue(&queue, &removed_value)) {
			printf("Dequeued value %d from the queue\n", removed_value);
		}
	}
	printf("Queue after dequeuing values:\n");	
	queue_list_print(queue);
	queue_list_destroy(&queue);
	puts("");
}

void test_queue_linkedlist() {
	printf("\t\t\t\033[34mQueue Linked List\033[0m\n");
	printf("------------------------------------------------------\n");
	int enqueue_list[] = {1, 32, 9, 28, 82, 27, 75, 57, 10, 55};
	size_t enqueue_count = sizeof(enqueue_list)/sizeof(int);
	queue_linkedlist queue = {0};

	printf("Queue before initialization:\n");
	queue_linkedlist_print(queue);
	printf("Queue is empty: %s\n", queue_linkedlist_isempty(queue) ? "True" : "False");
	printf("Queue after initialization:\n");
	for(size_t i=0;i<enqueue_count;i++) {
		queue_linkedlist_enqueue(&queue, enqueue_list[i]);
	}
	queue_linkedlist_print(queue);
	printf("Sizeof queue: %zu\n", queue_linkedlist_size(queue));
	printf("Queue is empty: %s\n", queue_linkedlist_isempty(queue) ? "True" : "False");
	int peeked_value = 0;
	if(queue_linkedlist_peek(queue, &peeked_value)) {
		printf("Peeked value in queue is %d\n", peeked_value);
	}

	for(size_t i=0;i<3;i++) {
		int removed_value =  0;
		if(queue_linkedlist_dequeue(&queue, &removed_value)) {
			printf("Dequeued value %d from the queue\n", removed_value);
		}
	}
	printf("Queue after dequeuing values:\n");	
	queue_linkedlist_print(queue);
	queue_linkedlist_destroy(&queue);
}

int main() {
	test_queue_list();
	test_queue_linkedlist();
	return 0;
}
