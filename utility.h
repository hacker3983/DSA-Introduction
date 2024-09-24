#ifndef _UTILITY_H
#define _UTILITY_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "singly-linkedlist.h"
#include "doubly-linkedlist.h"
#include "stack_list.h"
#include "stack_linkedlist.h"

enum sort_orders {
	SORT_ASCENDING,
	SORT_DESCENDING
};
void swap(int* a, int* b);
char* eval_sortorder(int sort_order) {
	return (sort_order == SORT_ASCENDING) ? "ascending" :
		"descending";
}
void print_array(int *array, size_t n);
void print_algotype_sortorder(const char* algoname, int sort_type, bool sorted);

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b, *b = temp;
}

void print_algotype_sortorder(const char* algoname, int sort_order, bool sorted) {
	char* sorted_msg = "before";
	if(sorted) {
		sorted_msg = "after";	
	}
	printf("Array %s \033[34m%s Sorting\033[0m in \033[32m%s order\033[0m:\n", sorted_msg, algoname, eval_sortorder(sort_order));
}

void print_array(int* array, size_t n) {
	printf("[");
	for(size_t i=0;i<n;i++) {
		printf("\033[32m%d\033[0m", array[i]);
		if(i != n-1) {
			printf(", ");
		}
	}
	printf("]\n");
}
#endif
