#include "hashmap.h"

hashmap_node* hashmap_create_hashnode(const char* key, int value) {
	hashmap_node* new_node = calloc(1, sizeof(hashmap_node));
	size_t node_keylength = strlen(key)+1;
	// Allocate memory to store the key within the new hash node
	char *node_key = malloc(node_keylength * sizeof(char));
	if(!node_key) {
		return NULL;
	}
	strncpy(node_key, key, node_keylength);

	// Place the key and the value within the new hash node
	new_node->key = node_key, new_node->value = value;
	new_node->tail = new_node;
	return new_node;
}

void hashmap_print_hashnode(hashmap_node* hashnode) {
	printf("{");
	while(hashnode) {
		printf("\033[31m\%s\"\033[0m: \033[32m%d\033[0m",
			hashnode->key, hashnode->value);
		if(hashnode->next) printf(", ");
		hashnode = hashnode->next;
	}
	printf("}");
}

hashmap_t hashmap_create(size_t size) {
	hashmap_t new_hashmap = {0};
	new_hashmap.buckets = calloc(size, sizeof(hashmap_node*));
	new_hashmap.size = size;
	return new_hashmap;
}

size_t hashmap_hash(hashmap_t hashmap, const char* key) {
	size_t hashcode = 0, key_length = strlen(key);
	for(size_t i=0;i<key_length;i++) {
		hashcode += key[i] + (21 ^ 7);
	}
	return hashcode % hashmap.size;
}

bool hashmap_put(hashmap_t* hashmap, const char* key, int value) {
	if(!hashmap->buckets || !hashmap->size) {
		return false;
	}
	size_t hashcode = hashmap_hash(*hashmap, key);
	bool contains_key = hashmap_get(*hashmap, key, NULL);
	hashmap_node** bucket = &hashmap->buckets[hashcode],
		*temp = (*bucket);
	hashmap_node* new_node = NULL;
	if(!contains_key) {
		new_node = hashmap_create_hashnode(key, value);
		if(!new_node) {
			return false;
		}
	}
	if(!(*bucket)) {
		(*bucket) = new_node;
	} else if(!contains_key) {
		(*bucket)->tail->next = new_node;
		(*bucket)->tail = new_node;
	}
	while(temp && contains_key) {
		if(strcmp(temp->key, key) == 0) {
			temp->value = value;
			return true;
		}
		temp = temp->next;
	}
	return true;
}

bool hashmap_get(hashmap_t hashmap, const char* key, int* ret_value) {
	if(!hashmap.size || !hashmap.buckets) {
		return false;
	}
	size_t hashcode = hashmap_hash(hashmap, key);
	hashmap_node *bucket = hashmap.buckets[hashcode];
	while(bucket) {
		if(strcmp(bucket->key, key) == 0) {
			if(ret_value) {
				*ret_value = bucket->value;
			}
			return true;
		}
		bucket = bucket->next;
	}
	return false;
}

bool hashmap_remove(hashmap_t* hashmap, const char* key) {
	if(!hashmap->buckets || !hashmap->size) {
		return false;
	}
	size_t hashcode = hashmap_hash(*hashmap, key);
	hashmap_node **bucket = &hashmap->buckets[hashcode],
		*current = *bucket, *next = NULL, *tail = NULL;
	if(!(*bucket)) {
		return false; 
	}
	if(strcmp(current->key, key) == 0) {
		next = (*bucket)->next;
		free(*bucket);
		*bucket = next;
		return true;
	}
	while(current->next) {
		next = current->next;
		if(strcmp(current->next->key, key) == 0) {
			next = next->next;
			free(current->next->key);
			free(current->next);
			current->next = next;
			if(!next) {
				(*bucket)->tail = (*bucket);
			}
			return true;
		}
		current = current->next;
	}
	return false;
}

void hashmap_print(hashmap_t hashmap) {
	printf("[\n");
	for(size_t i=0;i<hashmap.size;i++) {
		printf("\t\033[32m%zu\033[0m: ", i);
		hashmap_print_hashnode(hashmap.buckets[i]);
		if(i != hashmap.size-1) printf(",");
		printf("\n");
	}
	printf("]\n");
}

void hashmap_destroy(hashmap_t* hashmap) {
	hashmap_node *current = NULL, *next = NULL;
	for(size_t i=0;i<hashmap->size;i++) {
		current = hashmap->buckets[i];
		while(current) {
			free(current->key); current->key = NULL;
			next = current->next;
			free(current);
			current = next;
		}
		hashmap->buckets[i] = NULL;
	}
	free(hashmap->buckets);
	hashmap->buckets = NULL;
	hashmap->size = 0;
}
