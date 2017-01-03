#include <conio.h>

#define NEWTON 1
#define BROYDEN 2

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*----------------------------------------------------------------------------
	PLANTILLA DE LA PANTALLA PARA LA PETICION DE LAS VARIABLES
----------------------------------------------------------------------------*/

void plan_sol (int short pagina, int short u_pagina, int N, double *vector_n,
		int pre, int ite, int metodo, double *pterror)

{

int i; /* CONTADOR */

/* BORRADO DE PANTALLA */

clrscr ();

/* SELECCION DEL COLOR DEL TEXTO */

textcolor(LIGHTGREEN);

switch (metodo)
	{       /* INICIO SWITCH */

	case NEWTON:
		{
		gotoxy(4,24);
		cprintf("NEWTON");
		break;
		}

	case BROYDEN:
		{
		gotoxy(4,24);
		cprintf("BROYDEN");
		break;
		}

	}       /* FIN SWITCH */

/* SELECCION DEL COLOR DEL TEXTO */

textcolor(WHITE);

/* POSICIONAR E IMPRESION DE TEXTOS */

gotoxy (20,24);
	cprintf("Re P g");

gotoxy(29,24);
	cprintf("Av P g");

gotoxy(38,24);
	cprintf("Inicio");

gotoxy(47,24);
	cprintf("Fin");

/* POSICIONAR E IMPRIMIR PAGINA ACTUAL */

gotoxy(68,24);
	cprintf("%hd de %hd", pagina, u_pagina);

/* SELECCION DE COLOR DE TEXTO */

textcolor(LIGHTBLUE);

/* POSICIONAR E IMPRIMIR PAGINA ACTUAL */

gotoxy (64,24);
	cprintf("P g");

/* IMPRESION DE RECORDATORIO */

textbackground(BLUE);
textcolor(WHITE);

gotoxy(4,1);
cprintf("                                                 ");

gotoxy(5,1);
cprintf("Problema resuelto en %d iteraciones.", ite);

/* IMPRESION DE LOS RECUADROS DE LAS VARIABLES */

/* SI NO ESTAMOS EN LA ULTIMA PAGINA MUESTRA 20 VARIABLES */

if ( pagina != u_pagina )
	{
	for (i=2;i<22;i++) /* IMPRIMIR RECUADRO */
		{
		textcolor(YELLOW);      /* COLOR DEL TEXTO */

		gotoxy(4,i);
		cprintf("                                                 ");

		/* IMPRIMIR VARIABLES */

		gotoxy(8,i);
		cprintf("é(%d)", (pagina-1)*20+(i-1));

		/* IMPRIMIR SIGNOS DE IGUALDAD */

		gotoxy(16,i);
		cprintf("=");

		/* IMPRIMIR VARIABLES */

		textcolor(LIGHTGREEN);  /* COLOR DEL TEXTO */

		gotoxy(18,i);
		cprintf("%.*lf", pre, vector_n[((pagina-1)*20+(i-2))] );

		}

	/* MUESTRA EL ERROR COMETIDO */

	textcolor(WHITE);

	gotoxy(4,i);
	cprintf("                                                 ");
	gotoxy(4,i);
	cprintf(" Error: %.*E", pre, *pterror);

	}

/* SI ESTAMOS EN LA ULTIMA PAGINA MUESTRA LAS VARIABLES QUE QUEDEN */

else
	{       /* IMPRIMIR RECUADROS */

	for (i=2;i <= ( N-((pagina-1)*20) ) +1 ;i++)

		{       /* INICIO FOR i */

		textcolor(YELLOW);      /* COLOR DEL TEXTO */

		gotoxy(4,i);
		cprintf("                                                 ");

		/* IMPRIMIR VARIABLES */

		gotoxy(8,i);
		cprintf("é(%d)",(pagina-1)*20+(i-1));

		/* IMPRIMIR SIGNOS DE IGUALDAD */

		gotoxy(16,i);
		cprintf("=");

		/* IMPRIMIR VARIABLES */

		textcolor(LIGHTGREEN);  /* COLOR DEL TEXTO */

		gotoxy(18,i);
		cprintf("%.*lf", pre,vector_n[((pagina-1)*20+(i-2))] );

		}       /* FIN FOR i */

	/* MUESTRA EL ERROR COMETIDO */

	textcolor(WHITE);

	gotoxy(4,i);
	cprintf("                                                 ");
	gotoxy(4,i);
	cprintf(" Error: %.*E", pre, *pterror);

	}


/* SELECCION DEL COLOR DE FONDO */

textbackground(BLACK);

/* RESTAURAR COLOR DE TEXTO NORMAL */

textcolor(LIGHTGRAY);
}
