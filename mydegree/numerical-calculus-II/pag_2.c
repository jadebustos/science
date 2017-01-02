#include <conio.h>

/*----------------------------------------------------------------------------
		PAGINA 2 DEL ENUNCIADO DEL PROBLEMA
----------------------------------------------------------------------------*/


void pagina_2  ( void )

{

/* ARRAYS CON EL TEXTO A IMPRIMIR */

char texto_1[] = {
		 "(a) (v[n])^2 = (v[0])^2 +2*g*n*Incr[y]-2*æ*Incr[y]*"
		 "{Sum(j=1,n) (1/(cos é(j)))}"
		 };

char texto_2[] = {
		 "para cada n=1,2,...,N, y "
		 };

char texto_3[] = {
		 "(b) w[n] = -Incr[y]*v[n]*"
		 "{Sum(i=1,N) (1/( (v[i])^3* cos é(i) ))}"
		 };

char texto_4[] = {
		 "para cada n=1,2,..,N."
		 };

char texto_5[] = {
		 "La constante v[0] es la velocidad inicial del material "
		 "granular, X es la\n\rcoordenada x del final del canal, "
		 "æ es la fuerza de friccion, N es el numero de segmentos "
		 "del canal y g es la constante gravitacional.La variable é(i)"
		 " es el\n\r angulo de i-esimo segmento del canal a partir de "
		 "la vertical, y v[i] es la\n\rvelocidad de las particulas "
		 "en el i-esimo segmento del canal."
		 };

/* ELECCION DEL COLOR DEL TEXTO */

textcolor(WHITE);

gotoxy(1,3);
cprintf("donde");

gotoxy(2,5);
cprintf("%s", texto_1);

gotoxy(2,7);
cprintf("%s", texto_2);

gotoxy(2,9);
cprintf("%s", texto_3);

gotoxy(2,11);
cprintf("%s", texto_4);

gotoxy(5,14);
cprintf("%s", texto_5);

}
