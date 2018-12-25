CC=gcc

all: help.o log.o randomgen.o
	$(CC) random.c help.o log.o randomgen.o -o random

help:
	$(CC) -c help.c 

log:
	$(CC) -c log.c

randomgen:
	$(CC) -c randomgen.c

clean:
	rm -f *.o *~
