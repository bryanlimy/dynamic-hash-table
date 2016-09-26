#include "hash-table.h"

/**
 * Initialize hash table
 * @return pointer to hash table, NULL if failed
 */
hash_table *hash_init(int size) {
	printf("initializing hash table with size: %d\n", size);
	
	if (size <= 0) return NULL;

	// allocate hash table
	hash_table *table = malloc(sizeof(hash_table));
	if (table == NULL) return NULL;

	// allocate list of entries in hash table
	table->entries = malloc(sizeof(hash_entry*) * size);
	if (table->entries == NULL) return NULL;

	// initialize all entries
	for (int i = 0; i < size; i ++) table->entries[i] = NULL;

	table->size = size;
	table->num_entries = 0;

	return table;
}


/**
 * Hash function to calculate index in hash table
 */
int hash(hash_table *table, int key) {
	return key % table->size;
}


/**
 * Insert key and value into hash table
 *
 * @return index of the entry that is being inserted, -1 otherwise
 */
int hash_insert(hash_table *table, int key, char *value) {
	if (table == NULL) return -1;

	int i = hash(table, key);
	hash_entry *entry = table->entries[i];

	while (entry) {
		if (entry->key == key) {
			// entry with the same key value already exist
			free(entry->value);
			entry->value = malloc(strlen(value) * sizeof(char));
			if (entry->value == NULL) return -1;
			strcpy(entry->value, value);
			return i;
		}
		entry = entry->next;
	}

	// allocate entry
	hash_entry *new_entry = malloc(sizeof(hash_entry));
	if (new_entry == NULL) return -1;

	// set entry values
	new_entry->key = key;
	new_entry->value = malloc(strlen(value) * sizeof(char));
	if (entry->value == NULL) return -1;
	strcpy(entry->value, value);
	entry->next = table->entries[i];

	// insert entry at the beginning of the linked list
	table->entries[i] = entry;
	return i;
}


/**
 * Remove entry with key from hash table
 *
 * @return index of entry that is being removed, -1 if failed
 */
int hash_remove(hash_table *table, int key) {
	if (table == NULL) return -1;

	int i = hash(table, key);
	hash_entry *entry = table->entries[i];

	// find the entry within the linked list
	while (entry) {
		if (entry->key == key) break;
		entry = entry->next;
	}

	// update hash table
	table->entries[i] = entry->next;

	free(entry->value);
	free(entry);
	return i;
}


/**
 * Destroy and deallocate hash table
 *
 * @return 0 on success, -1 otherwise
 */
int hash_destroy(hash_table *table) {
	printf("destroying hash table with size: %d\n", table->size);

	if (table == NULL) return -1;

	for (int i = 0; i < table->size; i++) {
		hash_entry *entry = table->entries[i];

		while (entry) {
			hash_entry *temp = entry;
			
			free(temp->value);
			free(temp);

			entry = entry->next;
		}
	}
	return 0;
}
