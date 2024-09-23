#include <stdio.h>
#include "utility.h"

void test_singlylinked_list() {
	printf("\t\t\t\033[34mSingly linked list\033[0m\n");
	printf("----------------------------------------------------------------------\n");
	singly_llist *singly_linkedlist = NULL;
	int removal_list[] = {550, 670, 200, 90, 0};
	size_t removal_count = sizeof(removal_list)/sizeof(int);

	// print the linked list before and after adding elements to it
	printf("Singly linked list before appending elements:\n");
	singly_linkedlist_print(singly_linkedlist);
	int accumulator = 10;
	for(int i=0;i<500;i+=accumulator) {
		singly_linkedlist_append(&singly_linkedlist, i);
		accumulator += 10;
	}
	printf("Singly linked list after appending elements:\n");
	singly_linkedlist_print(singly_linkedlist);
	puts("");

	// remove each elements or nodes in the linked list that is in the removal list
	printf("Elements to be removed from singly linked list:\n");
	print_array(removal_list, removal_count);
	for(size_t i=0;i<removal_count;i++) {
		singly_linkedlist_remove(&singly_linkedlist, removal_list[i]);
	}

	// print the nodes in the singly linked list after removing the elements or nodes in the removal list
	printf("Singly linked list after removing those elements:\n");
	singly_linkedlist_print(singly_linkedlist);
	puts("");

	// insert a node to the front of the linked list
	int nums[] = {30, 40, 101, 222, 60, 3, 2, 1, 9, 12, 15};
	size_t n = sizeof(nums)/sizeof(int);

	printf("Elements to be inserted at the front of the linked list:\n");
	print_array(nums, n);
	for(size_t i=0;i<n;i++) {
		singly_linkedlist_insertfront(&singly_linkedlist, nums[i]);
	}
	printf("Singly linked list after inserting the elements to the front:\n");
	singly_linkedlist_print(singly_linkedlist);

	// Destroy / free the memory of the singly linked list back to the system
	singly_linkedlist_destroy(&singly_linkedlist);
}

void test_doublylinked_list() {
	printf("\t\t\t\033[34mDoubly linked list\033[0m\n");
	printf("----------------------------------------------------------------------\n");
	doubly_llist* doubly_linkedlist = NULL;
	int values[] = {30, 40, 101, 222, 60, 3, 2, 1, 9, 12, 15};
	size_t n = sizeof(values)/sizeof(int);

	// insert the values to the front of the doubly linked list and output the values
	printf("Doubly linked list after inserting values to the front:\n");
	for(size_t i=0;i<n;i++) {
		doubly_linkedlist_insertfront(&doubly_linkedlist, values[i]);
	}
	doubly_linkedlist_print(doubly_linkedlist);
	puts("");

	// print the doubly linked list after appending elements
	printf("Doubly linked list after appending to the end of the list:\n");
	size_t accumulator = 23;
	for(size_t i=91;i<900;i+=accumulator) {
		doubly_linkedlist_append(&doubly_linkedlist, i);
		accumulator += 23;
	}
	doubly_linkedlist_print(doubly_linkedlist);
	puts("");

	printf("Doubly linked list after removing a few elements from the list:\n");
	accumulator = 23;
	for(size_t i=91;i<900;i+=accumulator) {
		doubly_linkedlist_remove(&doubly_linkedlist, i);
		accumulator += 23;
	}
	doubly_linkedlist_print(doubly_linkedlist);
	doubly_linkedlist_destroy(&doubly_linkedlist);
}

int main() {
	test_singlylinked_list();
	puts("");
	test_doublylinked_list();
	return 0;
}
