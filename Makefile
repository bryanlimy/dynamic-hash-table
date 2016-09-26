all: hash-table.h hash-table.c main.c
	gcc -Wall -g -o hash-table main.c hash-table.h hash-table.c

clean:
	rm hash-table
