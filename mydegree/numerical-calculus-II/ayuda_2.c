#include <conio.h>

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*-----------------------------------------------------------------------------
	PAGINA SEGUNDA DE LA AYUDA DEL MENU DE PETICION DE DATOS
-----------------------------------------------------------------------------*/

void ayuda_2 (void)

{
/* ARRAYS CON EL TEXTO A IMPRIMIR */

char incr_y[] = {
	"Incremento de la varialble y."
		};

char segmentos[] = 	{
	"Dimension del espacio en el que vamos a trabajar."
			};

char velocidad[] = 	{
	"Velocidad inicial del material granular."
			};

char gravedad[] =	{
	"Constante gravitacional, dada en pies/(seg)^2."
			};

/* SELECCION DEL COLOR DEL TEXTO */

textcolor(WHITE);

/* POSICIONAMIENTO E IMPRESION DE LOS ARRAYS */

gotoxy(1,6);
	cprintf("%s", incr_y);

gotoxy(1,10);
	cprintf("%s", segmentos);

gotoxy(1,14);
	cprintf("%s", velocidad);

gotoxy(1,18);
	cprintf("%s", gravedad);

/* IMPRESION DE ESC */

gotoxy(10,24);
	cprintf("Esc");

/* SELECCION DEL COLOR DEL TEXTO */

textcolor(LIGHTRED);

/* POSICIONAMIENTO E IMPRESION DE ROTULOS */

gotoxy(1,4);
	cprintf("'Y' Incr[y]:");

gotoxy(1,8);
	cprintf("'R' Numero de segmentos[N]:");

gotoxy(1,12);
	cprintf("'V' Velocidad inicial (v[0]):");

gotoxy(1,16);
	cprintf("'G' Gravedad (g):");

/* REESTABLECER COLOR DE TEXTO NORMAL */

textcolor(LIGHTGRAY);

}
