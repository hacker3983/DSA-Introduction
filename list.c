#include "list.h"

list_t list_create(int x) {
	list_t list = {0};
	int* new_array = malloc(sizeof(int));
	if(new_array) {
		new_array[0] = x;
		list.array = new_array;
		list.count = 1;
		list.init = true;
	}
	return list;

}

void list_append(list_t* list, int x) {
	if(!list->init || !list->array) {
		list_t new_list = list_create(x);
		if(new_list.init) {
			list->array = new_list.array;
			list->count = 1;
			list->init = true;
		}
		return;
	}

	int* ptr_array = realloc(list->array,
				(list->count+1) * sizeof(int));
	if(!ptr_array) {
		return;
	}
	list->array = ptr_array;
	list->array[list->count++] = x;
}

bool list_findelement(list_t list, int x, size_t* result) {
	for(size_t i=0;i<list.count;i++) {
		if(list.array[i] == x) {
			*result = i;
			return true;
		}
	}
	return false;
}

void list_print(list_t list) {
	printf("[");
	for(size_t i=0;i<list.count;i++) {
		printf("\033[32m%d\033[0m", list.array[i]);
		if(i != list.count-1) printf(", ");
	}
	printf("]\n");
}

void list_destroy(list_t* list) {
	free(list->array); list->array = NULL;
	list->count = 0, list->init = false;
}
