#include <stdio.h>
#include "utility.h"

int main() {
	const char* keys[] = {
		"Charlotte", "Thomas",
		"Jens", "Peter",
		"Lisa", "Adele",
		"Michaela", "Bob",
		"Ashley", "William",
		"Parker", "Rob",
		"Pepper", "Banana",
		"Pineapple", "Watermelon",
		"Apple", "Mango",
		"Orange", "Strawberry",
		"Blueberry", "Peach",
		"Grapes", "Kiwi",
		"Watermelon", "Papaya"
	},
	*queries[] = {
		"Michaela", "Peter",
		"Jens", "Smith",
		"Alice", "Bob",
		"Alan", "John",
		"Watermelon", "Banana",
		"Pineapple", "Pepper",
		"Apple"
	},
	*removal_list[] = {
		"Alice", "John",
		"Jens", "Peter",
		"Watermelon", "Banana",
		"Pineapple", "Pepper",
		"Apple",
	};
	size_t key_count = sizeof(keys)/sizeof(char*),
	       query_count = sizeof(queries)/sizeof(char*),
	       removal_count = sizeof(removal_list)/sizeof(char*);
	hashset_t hashset = hashset_create(30);
	for(size_t i=0;i<key_count;i++) {
		hashset_add(&hashset, keys[i]);	
	}
	printf("The contents of the hashset are:\n");
	hashset_print(hashset);
	puts("");

	printf("Searching \033[32mhashset\033[0m for queries:\n");
	for(size_t i=0;i<query_count;i++) {
		bool found = hashset_contains(hashset,
				queries[i]);
		printf("\033[32m%s\033[0m found: \033[31m%s\033[0m\n", queries[i],
				found ? "True" : "False");
	}
	puts("");

	for(size_t i=0;i<removal_count;i++) {
		bool success = hashset_remove(&hashset, removal_list[i]);
		printf("Removal status of \033[32m%s\033[0m from the hashset: \033[31m%s\033[0m\n", removal_list[i], success ? "True" : "False");
	}
	puts("");
	printf("Hashset after removing keys:\n");
	hashset_print(hashset);
	hashset_destroy(&hashset);
	return 0;
}
