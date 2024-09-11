#include <stdio.h>
#include <stdbool.h>
#include "utility.h"

bool insertion_sortcompar(int a, int b, int sort_type) {
	bool comparison_result = 0;
	switch(sort_type) {
		case SORT_ASCENDING: comparison_result = (a > b); break;
		case SORT_DESCENDING: comparison_result = (a < b); break;
	}
	return comparison_result;
}

void insertion_sort(int* arr, size_t n, int sort_type) {
	for(size_t i=0;i<n-1;i++) {
		if(insertion_sortcompar(arr[i], arr[i+1], sort_type)) {
			size_t j = i+1;
			while(j > 0 && insertion_sortcompar(arr[j-1], arr[j], sort_type)) {
				printf("Swapping value: %d, with %d\n", arr[j], arr[j-1]);
				swap(&arr[j], &arr[j-1]);
				j--;
			}
		}  
	}
}


int main() {
	int arr[] = {7, 12, 9, 11, 3};
	size_t n = sizeof(arr)/sizeof(int);
	
	// Sort the array in ascending order
	print_algotype_sortorder("Insertion", SORT_ASCENDING, false);
	print_array(arr, n);
	insertion_sort(arr, n, SORT_ASCENDING);
	print_algotype_sortorder("Insertion", SORT_ASCENDING, true);
	print_array(arr, n);
	puts("");
	
	print_algotype_sortorder("Insertion", SORT_DESCENDING, false);
	print_array(arr, n);
	insertion_sort(arr, n, SORT_DESCENDING);
	print_algotype_sortorder("Insertion", SORT_DESCENDING, true);
	print_array(arr, n);
	return 0;
}
