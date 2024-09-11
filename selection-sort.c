#include <stdio.h>
#include "utility.h"

bool selection_sortcompar(int a, int b, int sort_order) {
	return (sort_order == SORT_ASCENDING) ? a < b : a > b;
}

void selection_sort(int* arr, size_t n, int sort_order) {
	for(size_t i=0;i<n;i++) {
		int min_index = i;
		for(size_t j=i+1;j<n;j++) {
			if(selection_sortcompar(arr[j], arr[min_index], sort_order)) {
				min_index = j;
			}
		}
		swap(&arr[i], &arr[min_index]);
	}
}

int main() {
	int arr[] = {4, 2, 4, 1};
	size_t n = sizeof(arr)/sizeof(int);
	// Sort in ascending order
	print_algotype_sortorder("Selection", SORT_ASCENDING, false);
	print_array(arr, n);
	selection_sort(arr, n, SORT_ASCENDING);
	print_algotype_sortorder("Selection", SORT_ASCENDING, true);
	print_array(arr, n);
	puts("");

	// Sort in descending order
	print_algotype_sortorder("Selection", SORT_DESCENDING, false);
	print_array(arr, n);
	selection_sort(arr, n, SORT_DESCENDING);
	print_algotype_sortorder("Selection", SORT_DESCENDING, true);
	print_array(arr, n);
	return 0;
}
