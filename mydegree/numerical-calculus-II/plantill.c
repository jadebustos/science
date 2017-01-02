#include <conio.h>

/*-----------------------------------------------------------------------------
     PLANTILLA DE LA PANTALLA EN LA PRIMERA PARTE DEL PROGRAMA, ENUNCIADO
     DEL PROBLEMA E INTRODUCCION DE LOS PARAMETROS GENERALES
-----------------------------------------------------------------------------*/


void plantilla (int short pagina, int short u_pagina)

{
/* BORRADO DE PANTALLA */

clrscr ();

/* SELECCION DEL COLOR DEL TEXTO */

textcolor(WHITE);

/* POSICIONAR E IMPRESION DE TEXTOS */

gotoxy (20,24);
	cprintf("Re P g");

gotoxy(30,24);
	cprintf("Av P g");

gotoxy(40,24);
	cprintf("Inicio");

gotoxy(50,24);
	cprintf("Fin");

/* POSICIONAR E IMPRIMIR PAGINA ACTUAL */

gotoxy(74,24);
	cprintf("%hd de %hd", pagina, u_pagina);


/* SELECCION DE COLOR DE TEXTO */

textcolor(LIGHTRED);

/* POSICIONAR E IMPRIMIR PAGINA ACTUAL */

gotoxy (70,24);
	cprintf("P g");

/* RESTAURAR COLOR DE TEXTO NORMAL */

textcolor(LIGHTGRAY);

}
