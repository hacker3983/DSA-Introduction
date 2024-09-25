#include "hashset.h"

hashset_t hashset_create(size_t size) {
	hashset_t hashset = {0};
	hashset.buckets = calloc(size, sizeof(bucket_t));
	hashset.size = size;
	return hashset;
}

size_t hashset_hash(hashset_t hashset, const char* key) {
	size_t xored_sum = 0;
	for(size_t i=0;i<strlen(key);i++) {
		xored_sum += 13 + 7 * (key[i] ^ 2);
	}
	return xored_sum % hashset.size;
}

bool hashset_add(hashset_t* hashset, const char* key) {
	size_t hashcode = hashset_hash(*hashset, key);
	if(hashset_contains(*hashset, key)) {
		return false;
	}
	char** keys = NULL;
	bucket_t* bucket = &hashset->buckets[hashcode];
	if(!bucket->key_count || !bucket->keys) {
		keys = malloc(sizeof(char*));
	} else {
		keys = realloc(bucket->keys,
			(bucket->key_count+1) * sizeof(char*));
	}
	if(!keys) {
		return false;
	}
	keys[bucket->key_count] = calloc(strlen(key)+1,
					sizeof(char));
	strcpy(keys[bucket->key_count], key);
	bucket->keys = keys;
	bucket->key_count++;
	return true;
}

bool hashset_remove(hashset_t* hashset, const char* key) {
	if(!hashset_contains(*hashset, key)) {
		return false;
	}
	size_t hashcode = hashset_hash(*hashset, key),
	       removal_index = 0;
	bucket_t* bucket = &hashset->buckets[hashcode];
	for(size_t i=0;i<bucket->key_count;i++) {
		if(strcmp(bucket->keys[i], key) == 0) {
			removal_index = i; break;
		}
	}
	free(bucket->keys[removal_index]);
	bucket->keys[removal_index] = NULL;
	bucket->key_count--;
	char** new_keys = (bucket->key_count) ?
		malloc((bucket->key_count) * sizeof(char*)) :
		NULL;
	if(new_keys) {
		for(size_t i=0, j=0;i<bucket->key_count+1;i++) {
			if(i != removal_index) {
				new_keys[j++] = bucket->keys[i];
			}
		}
	}
	free(bucket->keys);
	bucket->keys = new_keys;
	return true;
}

bool hashset_contains(hashset_t hashset, const char* key) {
	size_t hashcode = hashset_hash(hashset, key);
	bucket_t* buckets = hashset.buckets;
	if(!hashset.size || !buckets || !buckets[hashcode].keys) {
		return false;
	}
	for(size_t i=0;i<buckets[hashcode].key_count;i++) {
		if(buckets[hashcode].keys && strcmp(buckets[hashcode].keys[i], key) == 0) {
			return true;
		}
	}
	return false;
}

void print_strings(char** strings, size_t string_count) {
	printf("[");
	for(size_t i=0;i<string_count;i++) {
		printf("\033[31m\"%s\"\033[0m", strings[i]);
		if(i != string_count-1) {
			printf(", ");
		}
	}
	printf("]");
}

void hashset_print(hashset_t hashset) {
	printf("[\n");
	for(size_t i=0;i<hashset.size;i++) {
		printf("\t\033[32m%zu\033[0m:", i);
		print_strings(hashset.buckets[i].keys,
				hashset.buckets[i].key_count);
		if(i != hashset.size-1) {
			printf(",");
		}
		printf("\n");
	}
	printf("]\n");
}

void hashset_destroy(hashset_t* hashset) {
	for(size_t i=0;i<hashset->size;i++) {
		for(size_t j=0;j<hashset->buckets[i].key_count;j++) {
			free(hashset->buckets[i].keys[j]);
			hashset->buckets[i].keys[j] = NULL;
		}
		free(hashset->buckets[i].keys);
		hashset->buckets[i].keys = NULL;
	}
	free(hashset->buckets); hashset->buckets = NULL;
	hashset->size = 0;
}
