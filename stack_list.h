#ifndef _STACK_LIST_H
#define _STACK_LIST_H
#include "list.h"

typedef struct stack_list {
	list_t list;
	bool* init;
} stack_list;

void stack_list_push(stack_list* stack, int value);
bool stack_list_pop(stack_list* stack, int* popped_value);
bool stack_list_peek(stack_list stack, int* peeked_value);
bool stack_list_isempty(stack_list stack);
size_t stack_list_size(stack_list stack);
void stack_list_print(stack_list stack);
void stack_list_destroy(stack_list* stack);
#endif
