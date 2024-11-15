#include <stdio.h>
#include <stdlib.h>

static int* find_minmax_value(int* arr, size_t length) {
	static int minmax_map[2] = {0, 0};
	if(!arr) {
		return minmax_map;
	}
	int minimum_value = arr[0], maximum_value = arr[0];
	for(size_t i=1;i<length;i++) {
		if(arr[i] < minimum_value) {
			minimum_value = arr[i];
		}
		if(arr[i] > maximum_value) {
			maximum_value = arr[i];
		}
	}
	minmax_map[0] = minimum_value, minmax_map[1] = maximum_value;
	return minmax_map;
}

void counting_sort(int* arr, size_t length) {
	int* min_max = find_minmax_value(arr, length),
	     minimum_value = min_max[0], maximum_value = min_max[1];
	size_t counting_arraylen = maximum_value - minimum_value + 1;
	int* counting_array = calloc(counting_arraylen, sizeof(int));
	for(size_t i=0;i<length;i++) {
		counting_array[arr[i] - minimum_value]++;
	}
	size_t new_index = 0;
	for(size_t i=0;i<counting_arraylen;i++) {
		for(size_t j=0;j<counting_array[i];j++) {
			arr[new_index++] = i + minimum_value;
		}
	}
	free(counting_array);
}

void print_array(int* arr, size_t length) {
	printf("[");
	for(size_t i=0;i<length;i++) {
		printf("%d", arr[i]);
		if(i != length-1) {
			printf(", ");
		}
	}
	printf("]\n");
}

int main() {
	int arr[] = {14, 5, 12, 13, 21, 8, 1, 3, 16, 2};
	size_t length = sizeof(arr) / sizeof(int);
	puts("Array before being sorted:");
	print_array(arr, length);
	counting_sort(arr, length);
	puts("Array after being sorted:");
	print_array(arr, length);
	return 0;
}
