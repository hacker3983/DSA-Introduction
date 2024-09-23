#include <stdio.h>
#include "utility.h"

ssize_t binary_search(int* arr, int target, size_t n) {
	ssize_t index = 0;
	ssize_t left = 0, right = n-1;
	while(left <= right) {
		int mid = (left + right) / 2;
		// whenever the target value is greater than the value in the middle of the array then
		// we set the left index equal to the left half of the array
		//  whenever the target value is less than the middle of the array then
		//  we set the right index equal to the middle element's index-1
		//  otherwise we just return mid which is the found index
		if(target > arr[mid]) {
			left = mid+1;
		} else if(target < arr[mid]) {
			right = mid-1;
		} else {
			return mid;
		}
	}
	return -1;
}


int main() {
	int arr[] = {2, 3, 7, 7, 11, 15, 25};
	int queries[] = {11, 3, 15, 12, 2, 8};
	size_t n = sizeof(arr)/sizeof(int),
	       queries_count = sizeof(queries)/sizeof(int);
	printf("Array is: ");
	print_array(arr, n);
	for(size_t i=0;i<queries_count;i++) {
		ssize_t index = binary_search(arr, queries[i], n);
		printf("The value %d ", queries[i]);
		if(index == -1) {
			printf("was not found in the array\n");
			continue;
		}
		printf("was found at index %zu\n",
			index);
	}
	return 0;
}
