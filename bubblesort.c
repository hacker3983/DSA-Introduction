#include <stdio.h>
#include <stdbool.h>
#include "utility.h"

bool bubblesort_compar(int a, int b, int sort_order) {
	return (sort_order == SORT_ASCENDING) ? a > b :
		a < b;
}


void bubbleSortOptimized(int* arr, size_t n, int sort_order) {
	size_t swap_count = 0;
	for(size_t i=0;i<n;i++) {
		int swapped = 0;
		for(size_t j=0;j<n-i-1;j++) {
			if(bubblesort_compar(arr[j], arr[j+1], sort_order)) {
				swap_count++;
				swap(&arr[j], &arr[j+1]);
				printf("Swap_count: %zu\n",
					swap_count);
				swapped = 1;
			}
		}
		printf("i: %zu\n", i);
		if(!swapped) {
			break;
		}
	}
}

void bubbleSortUnoptimized(int* arr, size_t n, int sort_order) {
	for(size_t i=0;i<n;i++) {
		for(size_t j=0;j<n-1;j++) {
			if(bubblesort_compar(arr[j], arr[j+1], sort_order)) {
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

int main() {
	int arr[] = {64, 34, 25, 12, 22, 11, 90, 5};
	size_t n = sizeof(arr)/sizeof(int);
	
	// Sort the array in ascending order
	print_algotype_sortorder("Bubble", SORT_ASCENDING, false);
	print_array(arr, n);
	bubbleSortOptimized(arr, n, SORT_ASCENDING);
	print_algotype_sortorder("Bubble", SORT_ASCENDING, true);
	print_array(arr, n);
puts("");

	// Sort the array in descending order
	print_algotype_sortorder("Bubble", SORT_DESCENDING, false);
	print_array(arr, n);
	bubbleSortOptimized(arr, n, SORT_DESCENDING);
	print_algotype_sortorder("Bubble", SORT_DESCENDING, true);
	print_array(arr, n);
	return 0;
}
