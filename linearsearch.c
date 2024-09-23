#include <stdio.h>
#include "utility.h"

ssize_t linear_search(int* arr, int target, size_t n) {
	for(size_t i=0;i<n;i++) {
		if(arr[i] == target) {
			return i;
		}
	}
	return -1;
}


int main() {
	int arr[] = {3, 7, 2, 9, 5},
	    queries[] = {9, 0, 1, 7, 3};
	size_t n = sizeof(arr)/sizeof(int),
	       query_count = sizeof(queries)/sizeof(int);
	printf("The array is:\n");
	print_array(arr, n);
	printf("Searching for the values: ");
	print_array(queries, query_count);
	for(size_t i=0;i<query_count;i++) {
		ssize_t index = linear_search(arr, queries[i], n);
		printf("The value %d ", queries[i]);
		if(index != -1) {
			printf("was found at index %zu\n", index); continue;
		}
		printf("was not found\n");
	}
	print_array(arr, n);
	return 0;
}
