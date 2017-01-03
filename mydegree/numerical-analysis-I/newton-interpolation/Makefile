polinew: difdiv.o memoria.o polinomios.o internew.o polinew.o
	gcc -ansi difdiv.o memoria.o polinomios.o internew.o polinew.o -o polinew -lm

difdiv.o:
	gcc -c -ansi difdiv.c

memoria.o:
	gcc -c -ansi memoria.c

polinomios.o:
	gcc -c -ansi polinomios.c

internew.o:
	gcc -c -ansi internew.c

polinew.o:
	gcc -c -ansi polinew.c

clean:
	rm *.o
