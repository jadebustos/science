#include <conio.h>
#include "struct.h"

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*---------------------------------------------------------------
	FUNCION QUE MODIFICA PARAMETROS INICIALES
	     SEGUN INDICACION DEL USUARIO
---------------------------------------------------------------*/

char pet_dat(struct datos *ptparametros)

{

char res; /* RESPUESTA */

/* PETICION DE TAREA A REALIZAR */

res = leer_tecla ();

switch ( res )

	{       /* INICIO SWITCH */

	case 'C':   /* CIFRAS SIGNIFICATIVAS 1 - 16 */

		{
		do
			{
			gotoxy(27,3); /* POSICIONAR CURSOR */
			clreol(); /* BORRAR LINEA DESDE POS.ACTUAL
					HASTA EL FINAL */

			textbackground(LIGHTGRAY);
			cprintf("                 ");

			gotoxy(28,3); /* REPOSICIONAR CURSOR */
			cscanf("%d", &ptparametros->pre); /* PETICION DEL NUEVO DATO */

			textbackground(BLACK); /* RESTAURA COLOR DE FONDO */
			}

		while ( ptparametros->pre < 1 || ptparametros->pre > 16 );

		break;
		}

	case 'T':       /* PETICION DE LA TOLERANCIA */

		{
		gotoxy(27,5); /* POSICIONAR CURSOR */
		clreol(); /* BORRAR LINEA DESDE POS.ACTUAL HASTA EL FINAL */

		textbackground(LIGHTGRAY);
		cprintf("                 ");

		gotoxy(28,5); /* REPOSICIONAR CURSOR */
		cscanf("%lf", &ptparametros->tol); /* PETICION DEL NUEVO DATO */

		break;
		}

	case 'N':     /* PETICION DEL NUMERO MAXIMO DE ITERACIONES */

		{
		gotoxy(27,7); /* POSICIONAR CURSOR */
		clreol(); /* BORRAR LINEA DESDE POS.ACTUAL HASTA EL FINAL */

		textbackground(LIGHTGRAY);
		cprintf("                 ");

		gotoxy(28,7); /* REPOSICIONAR CURSOR */
		cscanf("%d", &ptparametros->ite); /* PETICION DEL NUEVO DATO */

		break;
		}

	case 'F':       /* PETICION DE LA FUERZA DE FRICCION */
		{
		gotoxy(27,9); /* POSICIONAR CURSOR */
		clreol(); /* BORRAR LINEA DESDE POS.ACTUAL HASTA EL FINAL */

		textbackground(LIGHTGRAY);
		cprintf("                 ");

		gotoxy(28,9); /* REPOSICIONAR CURSOR */
		cscanf("%lf", &ptparametros->fuerza); /* PETICION DEL NUEVO DATO */

		break;
		}

	case 'X':       /* PETICION DE COORDENADA X DEL FINAL DEL CANAL */
		{
		gotoxy(27,11); /* POSICIONAR CURSOR */
		clreol(); /* BORRAR LINEA DESDE POS.ACTUAL HASTA EL FINAL */

		textbackground(LIGHTGRAY);
		cprintf("                 ");

		gotoxy(28,11); /* REPOSICIONAR CURSOR */
		cscanf("%lf", &ptparametros->X); /* PETICION DEL NUEVO DATO */

		break;
		}

	case 'Y':       /* PETICION DEL INCREMENTO DE Y */
		{
		gotoxy(27,13); /* POSICIONAR CURSOR */
		clreol(); /* BORRAR LINEA DESDE POS.ACTUAL HASTA EL FINAL */

		textbackground(LIGHTGRAY);
		cprintf("                 ");

		gotoxy(28,13); /* REPOSICIONAR CURSOR */
		cscanf("%lf", &ptparametros->incr_y); /* PETICION DEL NUEVO DATO */

		break;
		}

	case 'R':       /* PETICION DEL NUMERO DE SEGMENTOS */
		{
		gotoxy(27,15); /* POSICIONAR CURSOR */
		clreol(); /* BORRAR LINEA DESDE POS.ACTUAL HASTA EL FINAL */

		textbackground(LIGHTGRAY);
		cprintf("                 ");

		gotoxy(28,15); /* REPOSICIONAR CURSOR */
		cscanf("%d", &ptparametros->N); /* PETICION DEL NUEVO DATO */

		break;
		}

	case 'V':       /* PETICION DE LA VELOCIDAD INICIAL */
		{
		gotoxy(27,17); /* POSICIONAR CURSOR */
		clreol(); /* BORRAR LINEA DESDE POS.ACTUAL HASTA EL FINAL */

		textbackground(LIGHTGRAY);
		cprintf("                 ");

		gotoxy(28,17); /* REPOSICIONAR CURSOR */
		cscanf("%lf", &ptparametros->velocidad_inicial); /* PETICION DEL
							NUEVO DATO */

		break;
		}

	case 'G':       /* PETICION DE LA GRAVEDAD EN pies/seg^2 */
		{
		gotoxy(27,19); /* POSICIONAR CURSOR */
		clreol(); /* BORRAR LINEA DESDE POS.ACTUAL HASTA EL FINAL */

		textbackground(LIGHTGRAY);
		cprintf("                 ");

		gotoxy(28,19); /* REPOSICIONAR CURSOR */
		cscanf("%lf", &ptparametros->gravedad); /* PETICION DEL NUEVO DATO */

		break;
		}

	}       /* FIN SWITCH */

/* REESTABLECE ATTRIBUTOS ORIGINALES DEL COLOR DEL TEXTO */

textbackground(BLACK);
textcolor(LIGHTGRAY);

return (res);
}
