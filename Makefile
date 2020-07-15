CC = gcc

all: rref

rref: driver.o fraction.o vector.o matrix.o
	$(CC) $^ -o $@

driver.o: driver.c fraction.h vector.h matrix.h
	$(CC) -c driver.c -o $@

fraction.o: fraction.c fraction.h
	$(CC) -c fraction.c -o $@

vector.o: vector.c vector.h fraction.h
	$(CC) -c vector.c -o $@

matrix.o: matrix.c matrix.h vector.h fraction.h
	$(CC) -c matrix.c -o $@

.PHONY: clean
clean:
	rm rref *.o
