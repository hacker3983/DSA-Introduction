#include "stack_list.h"

void stack_list_push(stack_list* stack, int value) {
	list_t* list = &stack->list;
	if(!stack->init) {
		list->array = NULL;
		list->count = 0;
		list->init = false;
		stack->init = &list->init;
	}
	list_append(list, value);
}

bool stack_list_pop(stack_list* stack, int* popped_value) {
	if(stack_list_isempty(*stack)) {
		return false;
	}
	list_t list = stack->list;
	size_t new_size = (list.count > 0) ? list.count-1 : list.count;
	list_t new_list = {0};
	*popped_value = list.array[new_size];
	for(size_t i=0;i<new_size;i++) {
		list_append(&new_list, list.array[i]);
	}
	list_destroy(&stack->list);
	stack->list.array = new_list.array;
	stack->list.count = new_list.count;
	stack->list.init = true;
	stack->init = &stack->list.init;
	return true;
}

bool stack_list_peek(stack_list stack, int* peeked_value) {
	if(stack_list_isempty(stack)) {
		*peeked_value = 0;
		return false;
	}
	*peeked_value = stack.list.array[stack.list.count-1];
	return true;
}

bool stack_list_isempty(stack_list stack) {
	if(!stack.list.init || !stack.list.count || !stack.list.array) {
		return true;
	}
	return false;
}

size_t stack_list_size(stack_list stack) {
	if(!stack.list.init || !stack.list.array) {
		return 0;
	}
	return stack.list.count;
}

void stack_list_print(stack_list stack) {
	list_print(stack.list);
}

void stack_list_destroy(stack_list* stack) {
	stack->init = NULL;
	list_destroy(&stack->list);
}
