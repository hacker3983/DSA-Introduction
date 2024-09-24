#ifndef _LIST_H
#define _LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list {
	int* array;
	size_t count;
	bool init;
} list_t;

list_t list_create(int x);
void list_append(list_t* list, int x);
bool list_findelement(list_t list, int x, size_t* result);
void list_print(list_t list);
void list_destroy(list_t* list);
#endif
