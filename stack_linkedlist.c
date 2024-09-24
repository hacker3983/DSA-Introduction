#include "stack_linkedlist.h"

void stack_linkedlist_push(stack_linkedlist* stack, int value) {
	singly_linkedlist_insertfront(&stack->list, value);
	stack->size++;
}

bool stack_linkedlist_peek(stack_linkedlist stack, int* peeked_value) {
	if(!stack.list) {
		return false;	
	}
	*peeked_value = stack.list->value;
	return true;
}

bool stack_linkedlist_isempty(stack_linkedlist stack) {
	return (!stack.size || !stack.list);
}

bool stack_linkedlist_pop(stack_linkedlist* stack, int* popped_value) {
	if(stack_linkedlist_isempty(*stack)) {
		return false;
	}
	singly_llist *next = stack->list->next;
	if(next) {
		next->tail = stack->list->tail;
	}
	*popped_value = stack->list->value;
	free(stack->list);
	stack->list = next;
	stack->size--;
	return true;
}

size_t stack_linkedlist_size(stack_linkedlist stack) {
	return stack.size;
}
void stack_linkedlist_print(stack_linkedlist stack) {
	singly_linkedlist_print(stack.list);
}

void stack_linkedlist_destroy(stack_linkedlist* stack) {
	singly_linkedlist_destroy(&stack->list);
}
