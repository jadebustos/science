#include <conio.h>
#include "struct.h"

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*------------------------------------------------------------
	FUNCION QUE MUESTRA LOS PARAMETROS INICIALES
------------------------------------------------------------*/

void menu_dat(struct datos *ptparametros)

{
int i; /* CONTADOR */

/* IMPRESION DE LOS ROTULOS */

textcolor(WHITE);

gotoxy(1,3);
	cprintf("Cifras significativas: ");

gotoxy(1,5);
	cprintf("Tolerancia: ");

gotoxy(1,7);
	cprintf("Numero de iteraciones: ");

gotoxy(1,9);
	cprintf("Fuerza de friccion (æ): ");

gotoxy(1,11);
	cprintf("Coordenada X: ");

gotoxy(1,13);
	cprintf("Incr[y] :");

gotoxy(1,15);
	cprintf("Numero de segmentos (N): ");

gotoxy(1,17);
	cprintf("Velocidad inicial (v[0]): ");

gotoxy(1,19);
	cprintf("Gravedad (g): ");

gotoxy(10,24);
	cprintf("Ayuda");

/* RESALTO DE LAS LETRAS */

textcolor(LIGHTRED);

gotoxy(1,3);
	cprintf("C");

gotoxy(1,5);
	cprintf("T");

gotoxy(1,7);
	cprintf("N");

gotoxy(1,9);
	cprintf("F");

gotoxy(12,11);
	cprintf("X");

gotoxy(6,13);
	cprintf("y");

gotoxy(5,15);
	cprintf("r");

gotoxy(1,17);
	cprintf("V");

gotoxy(1,19);
	cprintf("G");

gotoxy(7,24);
	cprintf("F1");

/* IMPRESION DE LOS RECUADROS DE LOS ROTULOS */

textbackground(LIGHTGRAY);

for (i=3;i<=19;i+=2)
	{
	gotoxy(27,i);
		cprintf("                 ");
	}

/* IMPRESION DE LOS DATOS EN LOS RECUADROS */

textcolor(BLACK);

gotoxy(28,3);
	cprintf("%d", ptparametros->pre);

gotoxy(28,5);
	cprintf("%E", ptparametros->tol);

gotoxy(28,7);
	cprintf("%d", ptparametros->ite);

gotoxy(28,9);
	cprintf("%g", ptparametros->fuerza);

gotoxy(28,11);
	cprintf("%g", ptparametros->X);

gotoxy(28,13);
	cprintf("%g", ptparametros->incr_y);

gotoxy(28,15);
	cprintf("%d", ptparametros->N);

gotoxy(28,17);
	cprintf("%g", ptparametros->velocidad_inicial);

gotoxy(28,19);
	cprintf("%g", ptparametros->gravedad);


textbackground(BLACK); /* RESTAURAR COLOR DE FONDO */

}
