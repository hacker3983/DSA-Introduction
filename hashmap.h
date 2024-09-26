#ifndef _HASHMAP_H
#define _HASHMAP_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct hashmap_node {
	char* key;
	int value;
	struct hashmap_node *next, *tail;
} hashmap_node;

hashmap_node* hashmap_create_hashnode(const char* key, int value);
void hashmap_print_hashnode(hashmap_node* hashnode);

typedef struct hashmap {
	hashmap_node** buckets;
	size_t size;
} hashmap_t;

hashmap_t hashmap_create(size_t size);
size_t hashmap_hash(hashmap_t hashmap, const char* key);
bool hashmap_put(hashmap_t* hashmap, const char* key, int value);
bool hashmap_get(hashmap_t hashmap, const char* key, int* ret_value);
bool hashmap_remove(hashmap_t* hashmap, const char* key);
void hashmap_print(hashmap_t hashmap);
void hashmap_destroy(hashmap_t* hashmap);
#endif
