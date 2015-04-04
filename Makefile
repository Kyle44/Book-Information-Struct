CC=gcc
CFLAGS=-I
DEPS=book_info_heap.h

all: main5.c book_info_heap.h book_info_heap.c
	$(CC) -o main5 -m32 -g main5.c book_info_heap.c
test: test1.c book_info_heap.h book_info_heap.c
	$(CC) -o test1 -m32 -g test1.c book_info_heap.c
clean:
	rm -f *~ *# *.o
