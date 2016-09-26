#include <stdio.h>
#include "./hash-table.h"

int main(int argc, char **argv) {

	if (argc != 2) {
		printf("Usage: ./hash_table <size of table>\n");
		return -1;
	}

	int size = (int) strtol(argv[1], (char**) NULL, 10);
	
	hash_table *table = hash_init(size);

	hash_destroy(table);

	return 0;
}