#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUCKET_SIZE 10
static long long* buckets[BUCKET_SIZE] = {0};
static size_t bucket_sizes[BUCKET_SIZE] = {0};

void find_maxnum(long long* arr, size_t size, long long* max_nump) {
	if(!arr || !size) {
		return;
	}
	long long max_num = arr[0];
	for(size_t i=1;i<size;i++) {
		if(arr[i] > max_num) {
			max_num = arr[i];
		}
	}
	*max_nump = max_num;
}

size_t get_numberlength(long long number) {
	size_t length = 1;
	while(number >= 10) {
		length++;
		number /= 10;
	}
	return length;
}

void print_buckets() {
	for(size_t i=0;i<BUCKET_SIZE;i++) {
		printf("bucket %zu: [", i);
		for(size_t j=0;j<bucket_sizes[i];j++) {
			printf("%lld", buckets[i][j]);
			if(j != bucket_sizes[i]-1) {
				printf(", ");
			}
		}
		printf("]\n");
	}
}

void buckets_destroy() {
	for(size_t i=0;i<BUCKET_SIZE;i++) {
		free(buckets[i]);
	}
	memset(buckets, 0, BUCKET_SIZE * sizeof(long long*));
	memset(bucket_sizes, 0, BUCKET_SIZE * sizeof(size_t));
}

void radix_sort(long long* arr, size_t size) {
	if(!arr || !size) {
		return;
	}
	long long max_num = 0;
	find_maxnum(arr, size, &max_num);
	size_t max_numlen = get_numberlength(max_num),
	       max_numidx = max_numlen-1;
	while(max_num) {
		for(size_t i=0;i<size;i++) {
			size_t num_len = get_numberlength(arr[i]),
			       number = arr[i],
			       num_indexpad = max_numlen - max_numidx,
			       divisor = (num_indexpad-1),
			       bucket_index = 0;
			if(num_len == max_numlen) {
				divisor = (max_numlen - max_numidx - 1);
			}
			for(size_t j=0;j<divisor;j++) {
				number /= 10;
			}
			bucket_index += number % 10;
			size_t *bucket_size = &bucket_sizes[bucket_index];
			long long* new_ptr = realloc(buckets[bucket_index], ((*bucket_size)+1) * sizeof(long long));
			if(!new_ptr) {
				break;
			}
			new_ptr[(*bucket_size)++] = arr[i];
			buckets[bucket_index] = new_ptr;
		}
		size_t arr_index = 0;
		for(size_t i=0;i<BUCKET_SIZE;i++) {
			for(size_t j=0;j<bucket_sizes[i];j++) {
				arr[arr_index++] = buckets[i][j];
			}
		}
		buckets_destroy();
		if(max_numidx) {
			max_numidx--;
		}
		max_num /= 10;
	}
}

void print_array(long long* arr, size_t size) {
	printf("[");
	for(size_t i=0;i<size;i++) {
		printf("%lld", arr[i]);
		if(i != size-1) {
			printf(", ");
		}
	}
	printf("]\n");
}

int main(int argc, char** argv) {
	long long arr[] = {19567, 2025, 2007, 9789145576, 1859, 1961, 1000000000, 459999, 16, 999019, 7, 35, 3, 19, 10, 2, 1};
	size_t size = sizeof(arr) / sizeof(long long);
	puts("Array before being sorted:");
	print_array(arr, size);
	radix_sort(arr, size);
	puts("Array after being sorted:");
	print_array(arr, size);
	return 0;
}
