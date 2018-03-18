CC=gcc
CFLAGS=-Wall
NAME=main

main: descrip.o iodat.o mem.o check.o Mod2.o matriz.o sindromes.o main.o
	$(CC) $(CFLAGS) descrip.o iodat.o mem.o check.o Mod2.o matriz.o sindromes.o main.o -o $(NAME)
	make clean

descrip.o:
	$(CC) $(CFLAGS) -c descrip.c

iodat.o:
	$(CC) $(CFLAGS) -c iodat.c

mem.o:
	$(CC) $(CFLAGS) -c mem.c

check.o:
	$(CC) $(CFLAGS) -c check.c

Mod2.o:
	$(CC) $(CFLAGS) -c Mod2.c

matriz.o:
	$(CC) $(CFLAGS) -c matriz.c 

sindromes.o:
	$(CC) $(CFLAGS) -c sindromes.c

main.o:
	$(CC) $(CFLAGS) -c main.c

clean:
	rm *.o
