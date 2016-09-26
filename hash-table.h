#include <string.h>
#include <stdlib.h>

/**
 * Hash table entry structure
 */
typedef struct hash_entry {
	int key;
	char *value;
	struct hash_entry *next;
} hash_entry;

/**
 * Hash table structure
 */
typedef struct hash_table {
	int size;
	int num_entries;
	hash_entry **entries;
} hash_table;

hash_table *hash_init(int size);

int hash_hash(hash_table *table, int key);

int hash_insert(hash_table *table, int key, char *value);

int hash_remove(hash_table *table, int key);

int hash_destroy(hash_table *table);