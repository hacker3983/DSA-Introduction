#include <stdio.h>
#include "utility.h"

void test_stack_list() {
	printf("\t\t\t\033[34mStack List\033[0m\n");
	printf("-------------------------------------------------------------\n");
	int push_list[] = {5, 1, 2, 4, 21, 3, 7, 10, 6};
	size_t push_count = sizeof(push_list)/sizeof(int);

	stack_list stack = {0};
	printf("Stack before popping values:\n");
	for(size_t i=0;i<push_count;i++) {
		stack_list_push(&stack, push_list[i]);
	}
	stack_list_print(stack);
	while(!stack_list_isempty(stack)) {
		int popped_value = 0;
		if(stack_list_pop(&stack, &popped_value)) {
			printf("Popped the value %d off the stack\n", popped_value);
		}
	}
	printf("Stack after popping values:\n");
	stack_list_print(stack);
	if(stack_list_isempty(stack)) {
		printf("The stack is empty after popping values\n");
	}
	puts("");

	printf("Stack after pushing values again in reverse order:\n");
	for(size_t i=push_count-1;i>0;i--) {
		stack_list_push(&stack, push_list[i]);
	}
	stack_list_push(&stack, push_list[0]);
	stack_list_print(stack);
	if(!stack_list_isempty(stack)) {
		printf("The stack is not empty again\n");
	}
	for(size_t i=0;i<stack_list_size(stack);i++) {
		int popped_value = 0;
		if(stack_list_pop(&stack, &popped_value)) {
			printf("Popped the value %d off the top of the stack\n", popped_value);
		}
	}
	printf("stack after popping values off the stack:\n");
	stack_list_print(stack);
	int peeked_value = 0;
	if(stack_list_peek(stack, &peeked_value)) {
		printf("The value at the top of the stack is %d\n", peeked_value);
	}
	stack_list_destroy(&stack);
	puts("");
}

void test_stack_linkedlist() {
	printf("\t\t\t\033[34mStack Linked List\033[0m\n");
	printf("-------------------------------------------------------------\n");
	int push_list[] = {12, 7, 29, 11, 30, 9, 10, 0, 69, 100, 70, 13, 15, 19};
	size_t push_count = sizeof(push_list)/sizeof(int);
	stack_linkedlist stack = {0};
	for(size_t i=0;i<push_count;i++) {
		stack_linkedlist_push(&stack, push_list[i]);
	}
	printf("Stack before popping values:\n");
	stack_linkedlist_print(stack);
	printf("Stack is empty: %s\n", stack_linkedlist_isempty(stack) ? "True" : "False");
	printf("The size of the linked list is: %zu\n", stack_linkedlist_size(stack));
	while(!stack_linkedlist_isempty(stack)) {
		int popped_value = 0;
		if(stack_linkedlist_pop(&stack, &popped_value)) {
			printf("Popped the value %d off the top of the stack\n", popped_value);
		}
	}
	printf("Stack after popping values:\n");
	stack_linkedlist_print(stack);
	printf("The size of the linked list is: %zu\n", stack_linkedlist_size(stack));
	printf("Stack is empty: %s\n", stack_linkedlist_isempty(stack) ? "True" : "False");
	puts("");

	printf("Stack after reinitializing it:\n");
	for(size_t i=0;i<push_count;i++) {
		stack_linkedlist_push(&stack, push_list[i]);
	}
	stack_linkedlist_print(stack);

	printf("stack after popping 5 values:\n");
	for(size_t i=0;i<5;i++) {
		int popped_value = 0;
		if(stack_linkedlist_pop(&stack, &popped_value)) {
			printf("Popped the value %d off the top of the stack\n", popped_value);
		}
	}
	stack_linkedlist_print(stack);
	int peeked_value = 0;
	if(stack_linkedlist_peek(stack, &peeked_value)) {
		printf("The value of the top of the stack is: %d\n", peeked_value);
	}
	printf("The size of the linked list is: %zu\n", stack_linkedlist_size(stack));
	printf("Stack is empty: %s\n", stack_linkedlist_isempty(stack) ? "True" : "False");
	stack_linkedlist_destroy(&stack);
}

int main() {
	test_stack_list();
	test_stack_linkedlist();
	return 0;
}
