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

hash_table *init(int size);

int hash(int key);

int insert(hash_table *table, key, value);

int remove(hash_table *table, key);

int detroy(hash_table *table);