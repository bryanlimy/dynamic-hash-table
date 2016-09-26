all: hash-table.o main.c
	gcc -Wall -g -o hash-table main.c

hash-table.o: hash-table.h hash-table.c
	gcc -c hash-table.c

clean:
	rm *.o hash-table
