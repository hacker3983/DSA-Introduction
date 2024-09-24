#include <stdio.h>
#include "utility.h"

void print_mergelist(list_t* merge_list, size_t merge_count);

void append_subarray(list_t** subarrays, list_t* subarray, size_t* subarray_count) {
	list_t *new_arraylist = NULL;
	if(!(*subarrays)) {
		new_arraylist = malloc(sizeof(list_t));
		*subarray_count = 0;
	} else {
		new_arraylist = realloc(*subarrays,
					((*subarray_count)+1) * sizeof(list_t));
	}
	if(new_arraylist) {
		new_arraylist[(*subarray_count)].array = subarray->array;
		new_arraylist[(*subarray_count)++].count = subarray->count;
		*subarrays = new_arraylist;
	}
}

void mergesort_split(int* arr, size_t length, list_t** subarrays, size_t* subarray_count) {
	if(length <= 1) {
		return;
	}
	size_t mid = length / 2;
	list_t* left_subarray = calloc(1, sizeof(list_t)), *right_subarray = calloc(1, sizeof(list_t));
	for(size_t i=0;i<length;i++) {
		if(i < mid) {
			list_append(left_subarray, arr[i]);
			continue;
		}
		list_append(right_subarray, arr[i]);
	}
	append_subarray(subarrays, left_subarray, subarray_count);
	append_subarray(subarrays, right_subarray, subarray_count);
	mergesort_split(left_subarray->array, left_subarray->count, subarrays, subarray_count);
	mergesort_split(right_subarray->array, right_subarray->count, subarrays, subarray_count);
	free(left_subarray); left_subarray = NULL;
	free(right_subarray); right_subarray = NULL;
}

list_t mergesort_combine(list_t left_subarray, list_t right_subarray) {
	list_t new_mergelist = {0};
	size_t right_index = 0, insertion_index = 0;
	int left_value = 0, right_value = 0;
	for(size_t left_index=0;left_index<left_subarray.count;left_index++) {
		left_value = left_subarray.array[left_index];
		if(right_index < right_subarray.count) {
			right_value = right_subarray.array[right_index];
			bool found = list_findelement(new_mergelist, right_value, &insertion_index);
			if(left_value > right_value && !found) {
				list_append(&new_mergelist, right_value);
				right_index++;
			}
		}
		bool found = list_findelement(new_mergelist, left_value, &insertion_index);
		if(!found) {
			list_append(&new_mergelist, left_value);
		}
	}
	for(;right_index<right_subarray.count;right_index++) {
		right_value = right_subarray.array[right_index];
		bool found = list_findelement(new_mergelist, right_value, &insertion_index);
		if(!found) {
			list_append(&new_mergelist, right_value);
		}
	}
	return new_mergelist;
}

list_t mergesort_merge(list_t** merge_list, size_t *merge_count) {
	list_t new_mergelist = {0}, old_mergelist = {0};
	size_t j = 0;
	for(size_t i=(*merge_count)-1;i>0;i--) {
		old_mergelist = new_mergelist;
		new_mergelist = mergesort_combine(old_mergelist, (*merge_list)[i]);
		list_destroy(&old_mergelist);
		old_mergelist = new_mergelist;
		j++;
	}
	old_mergelist = new_mergelist;
	new_mergelist = mergesort_combine(old_mergelist, (*merge_list)[0]);
	list_destroy(&old_mergelist);
	return new_mergelist;
}

void mergesort(int* arr, size_t length, int sort_order) {
	if(length <= 1) {
		return;
	}
	size_t merge_count = 0;
	list_t *merge_list = NULL;
	mergesort_split(arr, length, &merge_list, &merge_count);
	list_t sorted_list = mergesort_merge(&merge_list, &merge_count);
	if(sort_order == SORT_ASCENDING) {
		for(size_t i=0;i<sorted_list.count;i++) {
			arr[i] = sorted_list.array[i];
		}
	} else {
		size_t j = 0;
		for(size_t i=sorted_list.count-1;i>j;i--) {
			swap(&arr[i], &arr[j]);
			j++;
		}
	}
	list_destroy(&sorted_list);
}

void print_mergelist(list_t* merge_list, size_t merge_count) {
	printf("[");
	for(size_t i=0;i<merge_count;i++) {
		printf("[");
		for(size_t j=0;j<merge_list[i].count;j++) {
			printf("%d", merge_list[i].array[j]);
			if(j != merge_list[i].count-1) printf(", ");
		}
		printf("]");
		if(i != merge_count-1) {
			printf(", ");
		}
	}
	printf("]\n");
}

int main() {
	int arr[] = {6, 7, 1, 3, 2, 9, 5, 21, 11, 67}/*{12, 8, 9, 3, 11, 5, 4}{3, 2, 1}*/;
	size_t n = sizeof(arr)/sizeof(int);
	
	// Sort in Ascending order
	print_algotype_sortorder("Merge", SORT_ASCENDING, false);
	print_array(arr, n);
	print_algotype_sortorder("Merge", SORT_ASCENDING, true);
	mergesort(arr, n, SORT_ASCENDING);
	print_array(arr, n);
	puts("");

	// Sort in Descending order
	print_algotype_sortorder("Merge", SORT_DESCENDING, false);
	print_array(arr, n);
	print_algotype_sortorder("Merge", SORT_DESCENDING, true);
	mergesort(arr, n, SORT_DESCENDING);
	print_array(arr, n);
	return 0;
}
