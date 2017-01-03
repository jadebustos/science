integr: tres8.o simpson.o trapecio.o datos.o integr.o
	gcc -ansi -Wall tres8.o simpson.o trapecio.o datos.o integr.o -o integr -lm

integr.o:
	gcc -c -ansi -Wall integr.c

datos.o:
	gcc -c -ansi -Wall datos.c

trapecio.o:
	gcc -c -ansi -Wall trapecio.c

simpson.o:
	gcc -c -ansi -Wall simpson.c

tres8.o:
	gcc -c -ansi -Wall tres8.c

clean:
	rm *.o
