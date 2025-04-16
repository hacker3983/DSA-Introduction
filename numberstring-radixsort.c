#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RADIX_COUNT 10

void sort_numberstrings(char** strings, size_t string_count);
char* find_longeststring(char** strings, size_t string_count, size_t* max_len);
void radix_arraygroup_strings(char** buckets[RADIX_COUNT], size_t bucket_sizes[RADIX_COUNT],
	char** strings, size_t string_count, size_t string_index, size_t max_len);
void radix_arraymove_tostrings(char** buckets[RADIX_COUNT], size_t bucket_sizes[RADIX_COUNT],
	char** strings, size_t string_count);
void radix_arraydestroy(char** buckets[RADIX_COUNT], size_t bucket_sizes[RADIX_COUNT]);

char* find_longeststring(char** strings, size_t string_count, size_t* max_lenp) {
	char* longest_string = NULL;
	size_t max_len = 0;
	for(size_t i=0;i<string_count;i++) {
		size_t string_len = strlen(strings[i]);
		if(string_len > max_len) {
			longest_string = strings[i];
			max_len = string_len;
		}
	}
	*max_lenp = max_len;
	return longest_string;
}

void radix_arraygroup_strings(char** buckets[RADIX_COUNT], size_t bucket_sizes[RADIX_COUNT],
	char** strings, size_t string_count, size_t string_index, size_t max_len) {
	for(size_t i=0;i<string_count;i++) {
		char* string = strings[i];
		size_t string_len = strlen(string),
		       pad_len = max_len - string_len,
		       diff = max_len - string_index,
		       bucket_index = 0;
		printf("number: %s, pad_len: %zu, max_len: %zu, string_index: %zu\n",
			string, pad_len, max_len, string_index);
		if(diff <= string_len && string_len < max_len) {
			bucket_index = string[string_len-diff] - '0';
		} else if(string_len == max_len && string_index < string_len) {
			bucket_index = string[string_index] - '0';
		}
		size_t* radix_size = &bucket_sizes[bucket_index];
		char** new_ptr = realloc(buckets[bucket_index], ((*radix_size)+1) * sizeof(char*));
		if(!new_ptr) {
			break;
		}
		new_ptr[(*radix_size)++] = string;
		buckets[bucket_index] = new_ptr;
	}
}

void sort_numberstrings(char** strings, size_t string_count) {
	char** buckets[RADIX_COUNT] = {0};
	size_t bucket_sizes[RADIX_COUNT] = {0};
	size_t longest_stringlen = 0;
	char* longest_string = find_longeststring(strings, string_count, &longest_stringlen);
	for(size_t i=longest_stringlen-1;i>=0;) {
		radix_arraygroup_strings(buckets, bucket_sizes, strings, string_count, i, longest_stringlen);
		radix_arraymove_tostrings(buckets, bucket_sizes, strings, string_count);
		radix_arraydestroy(buckets, bucket_sizes);
		if(!i) {
			break;
		}
		i--;
	}
}
void radix_arraymove_tostrings(char** buckets[RADIX_COUNT], size_t bucket_sizes[RADIX_COUNT],
	char** strings, size_t string_count) {
	size_t string_index = 0;
	for(size_t i=0;i<RADIX_COUNT;i++) {
		if(!buckets[i]) {
			continue;
		}
		for(size_t j=0;j<bucket_sizes[i];j++) {
			strings[string_index++] = buckets[i][j];
		}
	}
}

void radix_arraydestroy(char** buckets[RADIX_COUNT], size_t bucket_sizes[RADIX_COUNT]) {
	for(size_t i=0;i<RADIX_COUNT;i++) {
		free(buckets[i]);
	}
	memset(buckets, 0, RADIX_COUNT * sizeof(char**));
	memset(bucket_sizes, 0, RADIX_COUNT * sizeof(size_t));
}

void print_array(char** numbers, size_t number_count) {
	printf("{\n");
	for(size_t i=0;i<number_count;i++) {
		printf("\t%s\n", numbers[i]);
	}
	printf("}\n");
}

int main() {
	char* numbers[] = {
		"123",
		"19",
		"72",
		"12",
		"20",
		"0",
		"0000000000",
		"01",
		"010",
		"1",
		"190000000000000000000000000",
		"456780"
	};
	size_t number_count = sizeof(numbers) / sizeof(char*);
	printf("Array before being sorted:\n");
	print_array(numbers, number_count);
	sort_numberstrings(numbers, number_count);
	printf("Array after being sorted:\n");
	print_array(numbers, number_count);
	return 0;
}
