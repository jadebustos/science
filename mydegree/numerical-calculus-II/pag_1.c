#include <conio.h>

/*----------------------------------------------------------------------------
		PAGINA 1 DEL ENUNCIADO DEL PROBLEMA
----------------------------------------------------------------------------*/

void pagina_1 (void)

{

/* ARRAYS CON EL TEXTO A IMPRIMIR */

char texto_1[] = {
		 " El problema que vamos a tratar de resolver utilizando los"
		 " metodos de Newton y Broyden es el siguiente."
		 };

char texto_2[] = {
		 "Para calcular la forma de un canal de descarga de flujo "
		 "gravitacional que\n\rminimice el tiempo de transito de "
		 "particulas granulares descargadas, C.Chiarella, W.Charlton"
		 ", y A.W.Roberts resolvieron las siguientes ecuaciones por el"
		 " metodo de Newton:"
		 };

char texto_3[] = {
		 "(1) f[n](é(1),...,é(N)) = "
		 };

char texto_4[] = {
		 "= ( (sen é[n+1])/v[n+1] )*(1-æ*w[n+1]) - ( (sen é[n])/v[n] )*"
		 "(1-æ*w[n]) = 0"
		 };

char texto_5[] = {
		 "para cada n = 1,2,...,N-1"
		 };

char texto_6[] = {
		 "(2) f[N](é(1),...,é(N)) = "
		 "Incr[y]*{Sum(i=1,N)( tan é(i) )} - X = 0"
		 };

/* ELECCION DEL COLOR DEL TEXTO */

textcolor(LIGHTGREEN);

gotoxy(5,6);
cprintf("Problema:");

/* ELECCION DEL COLOR DEL TEXTO */

textcolor(WHITE);

gotoxy(5,3);
cprintf("%s", texto_1);

gotoxy(5,8);
cprintf("%s", texto_2);

gotoxy(5,13);
cprintf("%s", texto_3);

gotoxy(5,15);
cprintf("%s", texto_4);

gotoxy(5,17);
cprintf("%s", texto_5);

gotoxy(5,19);
cprintf("%s", texto_6);

}
