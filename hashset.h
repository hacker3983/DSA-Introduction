#ifndef _HASHSET_H
#define _HASHSET_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct bucket {
	char** keys;
	size_t key_count;
} bucket_t;

typedef struct hashset {
	bucket_t* buckets;
	size_t size;
} hashset_t;

hashset_t hashset_create(size_t size);
size_t hashset_hash(hashset_t hashset, const char* key);
bool hashset_add(hashset_t* hashset, const char* key);
bool hashset_remove(hashset_t* hashset, const char* key);
bool hashset_contains(hashset_t hashset, const char* key);
void hashset_print(hashset_t hashset);
void hashset_destroy(hashset_t* hashset);
#endif
