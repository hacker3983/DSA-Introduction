#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#define COUNTING_ARRAY_CHUNKSIZE 1000
bool counting_sortcompar(int a, int b, int sort_order) {
	return (sort_order == SORT_ASCENDING) ? a <= b : a >= b;
}
void counting_sort(int* arr, size_t n, int sort_order) {
	int maximum_value = arr[0];
	int* counting_array = calloc(COUNTING_ARRAY_CHUNKSIZE, sizeof(int));
	int counting_array_length = COUNTING_ARRAY_CHUNKSIZE;
	for(size_t i=0;i<n;i++) {
		while(counting_array_length <= arr[i]) {
			int prev_counting_length = counting_array_length;
			counting_array_length += COUNTING_ARRAY_CHUNKSIZE;
			counting_array = realloc(counting_array, counting_array_length * sizeof(int));
			memset(counting_array + prev_counting_length, 0,
					counting_array_length - prev_counting_length);
		}
		if(arr[i] > maximum_value) {
			maximum_value = arr[i];
		}
		counting_array[arr[i]]++;
	}
	size_t j = 0;
	if(sort_order == SORT_ASCENDING) {
		for(int i=0;i<=maximum_value ;i++) {
			if(counting_array[i] > 0) {
				for(int k=0;k<counting_array[i];k++) {
					arr[j++] = i;
				}
				printf("The value %d occurs %d %s in the array\n", i, counting_array[i],
					(counting_array[i] > 1) ? "times" : "time");
			}
		}
	} else {
		for(int i=maximum_value;i>=0;i--) {
			if(counting_array[i] > 0) {
				for(int k=0;k<counting_array[i];k++) {
					arr[j++] = i;
				}
				printf("The value %d occurs %d %s in the array\n", i, counting_array[i],
					(counting_array[i] > 1) ? "times" : "time");
			}
		}
	}
	free(counting_array); counting_array = NULL;
}


int main() {
	int arr[] = {2, 3, 0, 2, 3, 2, 20, 39, 21, 21, 66, 77, 89, 90, 19};
	size_t n = sizeof(arr)/sizeof(int);
	int sort_order = SORT_ASCENDING;
	// Sort the array in ascending order
	print_algotype_sortorder("Counting", sort_order, false);
	print_array(arr, n);
	counting_sort(arr, n, sort_order);
	print_algotype_sortorder("Counting", sort_order, true);
	print_array(arr, n);
	puts("");


	sort_order = SORT_DESCENDING;
	// Sort the array in descending order
	print_algotype_sortorder("Counting", sort_order, false);
	print_array(arr, n);
	counting_sort(arr, n, sort_order);
	print_algotype_sortorder("Counting", sort_order, true);
	print_array(arr, n);
	return 0;
}
