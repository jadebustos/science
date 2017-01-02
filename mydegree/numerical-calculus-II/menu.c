#include <ctype.h>
#include "struct.h"

/*--------------------------------------------------------------------------
	 FUNCION MEDIANTE LA CUAL NOS MOVEMOS POR LA PRIMERA PARTE
	 DEL PROGRAMA, ENUNCIADO DEL PROBLEMA Y INTRODUCCION DE LOS
	 PARAMETROS GENERALES DE ESTE
--------------------------------------------------------------------------*/

void menu (struct datos *ptparametros)

{
int short pagina = 1, /* PAGINA EN LA CUAL ESTAMOS ACTUALMENTE */
	  p_pagina = 1, /* PRIMERA PAGINA */
	  u_pagina = 3; /* ULTIMA PAGINA */

char tecla; /* PULSACION DE TECLADO */

/* HAY TRES PAGINAS, SI pagina ES IGUAL A 4 TERMINA ESTA PARTE DEL
   PROGRAMA Y PASAMOS DIRECTAMENTE A INTRODUCIR LOS VALORES DE LAS
   VARIABLES */

do
	{       /* INICIO DO */

	plantilla (pagina, u_pagina);

	switch ( pagina )

		{       /* INICIO SWITCH */
		case 1:
			{
			pagina_1();
			tecla = leer_tecla ();
			break;
			}

		case 2:
			{
			pagina_2();
			tecla = leer_tecla ();
			break;
			}

		case 3:
			{
			do
				{
				plantilla(pagina, u_pagina);

				menu_dat(ptparametros);

				tecla = pet_dat(ptparametros);

				/* AYUDA */

				if ( tecla == ';' )
					{
					nav_ayuda ();
					}

				/* SI SE HA MODIFICADO UN DATO DE LOS
				   EXISTENTES QUEDA UN ECO QUE HACE QUE SE
				   REPITA EL BUCLE UNA VEZ MAS DE LO
				   NECESARIO ESTA CONDICION ABSORVE EL ECO */

				if ( isupper ( tecla ) != 0 )
					getch ();
				}

			while ( islower ( tecla ) == 0 );

/* NO UTILIZAMOS islower PUES DESPUES DE PULSAR UNA MAYUSCULA QUEDA UN ECO
   CUYO CODIGO ASCII ES 13 Y REPITE EL BUCLE UNA VEZ MAS DE LO DESEADO */

/* SI tecla NO ES UNA MINUSCULA (CARACTER DE CONTROL) REPETIRA
   LA EJECUCION DEL BUCLE */

			break;
			}

		}       /* FIN SCHITCH */

	/* LECTURA DE UN CARACTER DE CONTROL PARA SABER A DONDE IR */

	while ( islower ( tecla ) == 0 )
		{
		tecla = leer_tecla();
		}

	/* SI tecla NO ES UN CARACTER EN MINUSCULA
	   NO SE HA PULSADO UNA TECLA DE CONTROL */

	/* OBTENCION DE LA NUEVA PAGINA A PARTIR DE tecla */

	pagina = navegar (p_pagina, u_pagina, pagina, tecla);

	}       /* FIN DO */

while ( pagina != 4 );

}
