CC = gcc
CFLAGS = -std=c89 -pedantic-errors -Wall -Werror

default: build

build: main.o linked_list.o
	gcc *.o

run: build
	./a.out

clean:
	rm -f *.o *.out

%.o: %.c
	$(CC) $(CFLAGS) $*.c -c -o $*.o
