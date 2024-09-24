#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool binarysearch(char** strings, size_t string_count, char* query, size_t* index) {
	if(!string_count) {
		return false;
	}
	size_t left = 0, right = string_count-1;
	size_t left2 = 0;
	while(left <= right) {
		size_t mid = (left + right) / 2,
		       string_length = strlen(strings[mid]);
		printf("left: %zu, mid: %zu, right: %zu\n", left, mid, right);
		if(strcmp(strings[mid], query) == 0) {
			*index = mid;
			return true;
		} else if(left2 < string_count && strcmp(strings[left2], query) == 0) {
			*index = left2;
			return true;
		}
		if(strcmp(strings[mid], query) > 0) {
			left = mid+1;
		} else if(strcmp(strings[mid], query) < 0) {
			if(mid) {
				right = mid-1;
			}
		}
		left2++;
		if(left2 >= string_count) {
			break;
		}
	}
	while(left2 < string_count) {
		if(strcmp(strings[left2], query) == 0) {
			*index = left2;
			return true;
		}
		left2++;
	}
	return false;
}

void print_strings(char** strings, size_t string_count) {
	printf("[");
	for(size_t i=0;i<string_count;i++) {
		printf("%s", strings[i]);
		if(i != string_count-1) {
			printf(", ");
		}
	}
	printf("]\n");
}

int main() {
	char* strings[] = {
		"Pete", "Jones",
		"Lisa", "Bob",
		"Siri", "Ashley",
		"Peter", "Parker",
		"Washington", "DC",
		"George", "Bush"
	};
	char* query = "Ashley";
	size_t string_count = sizeof(strings)/sizeof(char*);
	size_t index = 0;
	printf("Array:\n");
	print_strings(strings, string_count);
	if(binarysearch(strings, string_count, query, &index)) {
		printf("The value %s was found at index %zu in the array\n", query, index);
	} else {
		printf("The value %s was not found in the array\n", query);
	}
	return 0;
}
