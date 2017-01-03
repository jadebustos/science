#include <conio.h>
#include <stdio.h>

#define TAB 5 /* LUGAR DONDE SE VA A COLOCAR û (COORDENADA X) */

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

extern struct datos
	{

	int pre, /* PRECISION CON LA QUE SE MOSTRARAN LOS CALCULOS */
	    ite, /* NUMERO MAXIMO DE ITERACIONES */
	    N, /* NUMERO DE SEGMENTOS DEL CANAL */
	    newton_ite, /* NUMERO DE ITERACIONES EN EL METODO DE NEWTON */
	    broyden_ite; /* NUMERO DE ITERACIONES EN EL METODO DE BROYDEN */

	double tol, /* TOLERANCIA */
	       fuerza, /* FUERZA DE FRICCION*/
	       X, /* COORDENADA X DEL FINAL DEL CANAL */
	       incr_y, /* INCREMENTO DE Y */
	       velocidad_inicial, /* VELOCIDAD INICIAL */
	       gravedad; /* GRAVEDAD EN pies/seg^2 */
	};

char intr_var (int N, int short pagina, int short u_pagina, char tecla,
		double *vector, int pre)

{
int short altura = 2; /* ALTURA INICIAL */

char tcla = tecla; /* PULSACION DE TECLADO */

/* DISTINGUIMOS DOS CASOS QUE SON PRIMERA Y ULTIMA PAGINA, CUANDO ESTEMOS
   EN LA ULTIMA PAGINA ES POSIBLE QUE NO ESTEN IMPRESAS 20 VARIABLES, POR
   LO TANTO LA altura DE LA ULTIMA VARIABLE NO SERA 22 COMO EN CUALQUIER
   OTRA PAGINA */

do
	{       /* INICIO DO */

	if ( pagina == u_pagina )

		{       /* INICIO if */

		switch ( tcla )
			{       /* INICIO SWITCH ANIDADO */

			case 'k':       /* CURSOR IZQUIERDA */
			case 'h':       /* CURSOR ARRIBA */

				{       /* INICIO 'k', 'h' */

				/* SI ESTAMOS EN LA PRIMERA VARIABLE DE
				   ESTA PAGINA NO HACER NADA */

				if ( altura != 2 )
					{
					/* BORRA */

					gotoxy(TAB,altura--);
						cprintf(" ");

					/* IMPRIME NUEVO û */

					gotoxy(TAB,altura);
						cprintf("û");

					}
				break;
				}       /* FIN 'k'', 'h' */

			case 'm':       /* CURSOR DERECHA */

				{       /* INICIO 'm' */

				/* MODIFICACION DE UN DATO */

				/* POSICIONAR CURSOR Y BORRAR DE PANTALLA
				   DATO ANTERIOR */

				gotoxy(17,altura);
				textbackground(BLACK);
				clreol ();

				/* RECOGIDA DEL NUEVO DATO */

				textbackground(BLUE);
				gotoxy(17,altura);
				cprintf("                                    ");
				gotoxy(18,altura);
				cscanf("%lf",
					&vector[((u_pagina-1)*20+(altura-2))]);

				/* IMPRIMIR EL NUEVO DATO */

				gotoxy(17,altura);
				cprintf("                                    ");
				gotoxy(18,altura);
				cprintf("%.*lf", pre,
					vector[((u_pagina-1)*20+(altura-2))]);

				getch ();
				break;
				}       /* FIN 'm' */

			case 'p':       /* CURSOR ABAJO */

				{       /* INICIO 'p' */

				/* SI ESTAMOS EN LA ULTIMA VARIABLE DE ESTA
				   PAGINA NO HACER NADA */

				if ( altura != 1+(N-((u_pagina-1)*20)) )

					{
					/* BORRA */

					gotoxy(TAB,altura++);
						cprintf(" ");

					/* IMPRIME NUEVO û */

					gotoxy(TAB,altura);
						cprintf("û");
					}
				break;
				}       /* FIN 'p' */

			}       /* FIN SWITCH ANIDADO */

		}       /* FIN if */

	else    /* NO ESTAMOS EN LA ULTIMA PAGINA */

		{       /* PRINCIPIO else */

		switch ( tcla )
			{       /* INICIO SWITCH ANIDADO */

			case 'k':       /* CURSOR IZQUIERDA */
			case 'h':       /* CURSOR ARRIBA */

				{       /* INICIO 'k', 'h' */

				/* SI ESTAMOS EN LA PRIMERA VARIABLE DE
				   ESTA PAGINA NO HACER NADA */

				if ( altura != 2 )
					{
					/* BORRA */

					gotoxy(TAB,altura--);
						cprintf(" ");

					/* IMPRIME NUEVO û */

					gotoxy(TAB,altura);
						cprintf("û");

					}
				break;
				}       /* FIN 'k'', 'h' */

			case 'm':       /* CURSOR DERECHA */

				{       /* INICIO 'm' */

				/* MODIFICACION DE UN DATO */

				/* POSICIONAR CURSOR Y BORRAR DE PANTALLA
				   DATO ANTERIOR */

				gotoxy(17,altura);
				textbackground(BLACK);
				clreol ();

				/* RECOGIDA DEL NUEVO DATO */

				textbackground(BLUE);
				gotoxy(17,altura);
				cprintf("                                    ");
				gotoxy(18,altura);
				cscanf("%lf",
					&vector[((pagina-1)*20+(altura-2))]);

				/* IMPRIMIR EL NUEVO DATO */

				gotoxy(17,altura);
				cprintf("                                    ");
				gotoxy(18,altura);
				cprintf("%.*lf", pre,
					vector[((pagina-1)*20+(altura-2))]);

				getch ();
				break;
				}       /* FIN 'm' */

			case 'p':       /* CURSOR ABAJO */

				{       /* INICIO 'p' */

				/* SI ESTAMOS EN LA ULTIMA VARIABLE DE ESTA
				   PAGINA NO HACER NADA */

				if ( altura != 21 )

					{

					/* BORRA */

					gotoxy(TAB,altura++);
						cprintf(" ");

					/* IMPRIME NUEVO û */

					gotoxy(TAB,altura);
						cprintf("û");
					}
				break;

				}       /* FIN 'p' */

			}       /* FIN SWITCH ANIDADO */


		}       /* FINAL else */


	tcla = leer_tecla ();

	}       /* FIN DO */

while ( tcla == 'h' || tcla == 'm' || tcla == 'p' || tcla == 'k');

return (tcla);
}
