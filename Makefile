CC = gcc
CFLAGS = -g -Wall

all:
	$(CC) $(CFLAGS) -c heap.c
	$(CC) $(CFLAGS) -c prontoSocorro.c
	$(CC) $(CFLAGS) -c heap_heap_upa.c
	$(CC) heap_heap_upa.o heap.o prontoSocorro.o -o heap_heap_upa 

clean:
	-rm *.o heap_heap_upa