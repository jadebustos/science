#include <conio.h>
#include <stdio.h>

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

void rotulo_texto ( void )

{
clrscr (); /* BORRADO DE PANTALLA */

/* SELECCION DEL COLOR DEL TEXTO */

textcolor(YELLOW);

/* POSICIONAMIENTO E IMPRESION DEL TEXTO */

gotoxy(10,5);
	cprintf("PRACTICAS DE CALCULO NUMERICO II.");

/* SELECCION DEL COLOR DEL TEXTO */

textcolor(LIGHTGREEN);

/* POSICIONAMIENTO E IMPRESION DEL TEXTO */

gotoxy(15,8);
	cprintf("Grupo I        Ordenador 15");

gotoxy(15,11);
	cprintf("Jose Angel de Bustos Perez");


/* SELECCION DEL COLOR DEL TEXTO */

textcolor(LIGHTRED);

/* POSICIONAMIENTO E IMPRESION DEL TEXTO */

gotoxy(15,17);
	cprintf("2 - 2 - 96");

/* SELECCION DEL COLOR DEL TEXTO */

textcolor(LIGHTCYAN + BLINK);

/* POSICIONAMIENTO E IMPRESION DEL TEXTO */

gotoxy(25,20);
	cprintf("Pulsa una tecla para continuar.");

getch();

clrscr (); /* BORRADO DE PANTALLA */
}
