#ifndef _STACK_LINKEDLIST_H
#define _STACK_LINKEDLIST_H
#include "singly-linkedlist.h"

typedef struct stack_linkedlist {
	singly_llist* list;
	size_t size;
} stack_linkedlist;

void stack_linkedlist_push(stack_linkedlist* stack, int value);
bool stack_linkedlist_peek(stack_linkedlist stack, int* peeked_value);
bool stack_linkedlist_isempty(stack_linkedlist stack);
bool stack_linkedlist_pop(stack_linkedlist* stack, int* popped_value);
size_t stack_linkedlist_size(stack_linkedlist stack);
void stack_linkedlist_print(stack_linkedlist stack);
void stack_linkedlist_destroy(stack_linkedlist* stack);
#endif
