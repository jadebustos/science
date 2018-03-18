CC=gcc
CFLAGS=-Wall
NAME=main

main: descrip.o iodat.o mem.o Mod2.o tablaes.o main.o
	$(CC) $(CFLAGS) descrip.o iodat.o mem.o Mod2.o tablaes.o main.o -o $(NAME)
	make clean

descrip.o:
	$(CC) $(CFLAGS) -c descrip.c

iodat.o:
	$(CC) $(CFLAGS) -c iodat.c

mem.o:
	$(CC) $(CFLAGS) -c mem.c

Mod2.o:
	$(CC) $(CFLAGS) -c Mod2.c

tablaes.o:
	$(CC) $(CFLAGS) -c tablaes.c

main.o:
	$(CC) $(CFLAGS) -c main.c

clean:
	rm *.o
