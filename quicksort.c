#include <stdio.h>
#include <stdbool.h>
#include "utility.h"

bool quicksort_compar(int a, int b, int sort_type) {
	return (sort_type == SORT_ASCENDING) ?
		a <= b : a >= b;
}

ssize_t partition_array(int* arr, ssize_t start_index,
	ssize_t end_index, int sort_type) {
	int pivot_element = arr[end_index];
	ssize_t new_pivot_index = start_index;
	for(ssize_t i=start_index;i<end_index;i++) {
		if(quicksort_compar(arr[i],
			pivot_element, sort_type)) {
			swap(&arr[new_pivot_index++], &arr[i]);
		}
	}
	// swap the old pivot with the new pivot and return
	// the new pivot index
	swap(&arr[new_pivot_index], &arr[end_index]);
	return new_pivot_index;
}

void quicksort(int* arr, ssize_t start_index,
	ssize_t end_index, int sort_type) {
	if(start_index < end_index) {
		ssize_t pivot_index = partition_array(arr, start_index, end_index, sort_type);

		// Sort the elements to the left side of the pivot
		quicksort(arr, start_index, pivot_index-1, sort_type);

		// sort the elements to the right side of the pivot
		quicksort(arr, pivot_index+1, end_index, sort_type);
	}
}

int main() {
	int arr[] = {11, 9, 12, 7, 3};
	ssize_t n = sizeof(arr)/sizeof(int);
	
	// Sort the array in ascending order
	print_algotype_sortorder("Quick", SORT_ASCENDING, false);
	print_array(arr, n);
	quicksort(arr, 0, n-1, SORT_ASCENDING);
	print_algotype_sortorder("Quick", SORT_ASCENDING, true);
	print_array(arr, n);
	puts("");

	// Sort the array in descending order
	print_algotype_sortorder("Quick", SORT_DESCENDING, false);
	print_array(arr, n);
	quicksort(arr, 0, n-1, SORT_DESCENDING);
	print_algotype_sortorder("Quick", SORT_DESCENDING, true);
	print_array(arr, n);
	return 0;
}
