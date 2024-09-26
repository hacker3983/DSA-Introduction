#include <stdio.h>
#include "utility.h"

int main() {
	char* fruit_names[] = {
		"Apple", "Banana",
		"Mango", "Kiwi",
		"Orange", "Strawberry",
		"Grape", "Pineapple",
		"Blueberry", "Raspberry",
		"Watermelon", "Peach",
		"Cherry", "Papaya",
		"Pear", "Plum",
		"Apricot", "Blackberry",
		"Pomegranate"
	},
	*removal_list[] = {
		"Apple", "Pear",
		"Apricot", "Lychee",
		"Tangerine", "Papaya",
		"Orange", "Jackfruit",
		"Guava", "Peach"
	};
	int fruit_prices[] = {
		100, 50,
		150, 250,
		238, 415,
		672, 891,
		103, 586,
		479, 234,
		321, 750,
		804, 672,
		129, 498,
		935, 356
	};
	size_t fruit_count = sizeof(fruit_names)/sizeof(char*),
	       removal_count = sizeof(removal_list)/sizeof(char*);
	hashmap_t hashmap = hashmap_create(30);
	printf("Hashmap displaying prices of fruits in a super market:\n");
	for(size_t i=0;i<fruit_count;i++) {
		hashmap_put(&hashmap, fruit_names[i], fruit_prices[i]);
	}
	hashmap_print(hashmap);
	printf("Hashmap after updating prices:\n");
	for(size_t i=0;i<fruit_count;i++) {
		hashmap_put(&hashmap, fruit_names[i], fruit_prices[i] * 2);
	}
	hashmap_print(hashmap);
	for(size_t i=0;i<removal_count;i++) {
		bool removal_status = hashmap_remove(&hashmap, removal_list[i]);
		printf("Removal status of \033[32m%s\033[0m from the hashmap: \033[31m%s\033[0m\n", removal_list[i],
				removal_status ? "True" : "False");
	}
	printf("Hashmap after removing fruits:\n");
	hashmap_print(hashmap);
	hashmap_destroy(&hashmap);
	return 0;
}
