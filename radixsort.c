#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

#define RADIX_LENGTH 10

typedef struct bucket_list {
	int* list;
	size_t length;
} bucket_t;

// Append a new element to the bucket list
void append_element_tobucket(bucket_t* buckets,
	int element, size_t bucket_index) {
	// Allocate memory to store new items or elements within the bucket list
	if(!buckets[bucket_index].list
		|| !buckets[bucket_index].length) {
		buckets[bucket_index].list = malloc(sizeof(int));
	} else {
		int* new_ptr = realloc(buckets[bucket_index].list, (buckets[bucket_index].length + 1) * sizeof(int));
		if(new_ptr) {
			buckets[bucket_index].list = new_ptr;
		}
	}
	size_t* length = &buckets[bucket_index].length;
	buckets[bucket_index].list[(*length)++]
		= element;
}

void destroy_bucket(bucket_t* buckets, size_t bucket_index) {
	free(buckets[bucket_index].list);
	buckets[bucket_index].list = NULL;
	buckets[bucket_index].length = 0;
}

void print_buckets(bucket_t* buckets, size_t bucket_count) {
	for(size_t i=0;i<bucket_count;i++) {
		printf("Bucket list #%ld: ", i);
		print_array(buckets[i].list, buckets[i].length);
	}
}

int find_max(int* arr, size_t length) {
	int maximum_value = arr[length-1];
	for(size_t i=0;i<length-1;i++) {
		if(arr[i] > maximum_value) {
			maximum_value = arr[i];
		}
	}
	return maximum_value;
}

void move_radixarray_toarr(bucket_t* radix_array, int* arr, size_t radix_length) {
	size_t k=0;
	for(size_t i=0;i<radix_length;i++) {
		for(size_t j=0;j<radix_array[i].length;j++) {
			arr[k++] = radix_array[i].list[j];
		}
		destroy_bucket(radix_array, i);
	}
}

void radixsort(int* arr, size_t length, int sort_order) {
	bucket_t radix_array[RADIX_LENGTH] = {0};
	int factor = 0;
	int maximum_value = find_max(arr, length);
	while(maximum_value) {
		for(size_t i=0;i<length;i++) {
			int current_number = arr[i];
			if(factor > 0) {
				current_number /= 10 * factor;
			}
    		    	int radix_value = current_number % 10;
			append_element_tobucket(radix_array, arr[i], radix_value);
		}
		print_buckets(radix_array, RADIX_LENGTH);
		// Move the elements from each bucket into the original array
		move_radixarray_toarr(radix_array, arr, RADIX_LENGTH);
		maximum_value /= 10;
		factor++;
	}
	if(sort_order == SORT_ASCENDING) {
		return;
	}
	// reverse the array so that it is sorted in descending order
	size_t j=0;
	for(size_t i=length-1;i>j;i--) {
		swap(&arr[j++], &arr[i]);	
	}
}

int main(int argc, char** argv) {
	int arr[] = {33, 45, 40, 39, 25, 99, 17, 67, 17, 39, 24}/*{1, 0}{9, 7, 2, 0, 6, 3, 1}*/;
	size_t length = sizeof(arr)/sizeof(int);
	print_algotype_sortorder("Radix", SORT_ASCENDING, false);
	print_array(arr, length);
	radixsort(arr, length, SORT_ASCENDING);
	print_algotype_sortorder("Radix", SORT_ASCENDING, true);
	print_array(arr, length);
	puts("");

	print_algotype_sortorder("Radix", SORT_DESCENDING, false);
	print_array(arr, length);
	radixsort(arr, length, SORT_DESCENDING);
	print_algotype_sortorder("Radix", SORT_DESCENDING, true);
	print_array(arr, length);
	return 0;
}
