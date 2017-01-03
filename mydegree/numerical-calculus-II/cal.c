#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

#define NEWTON '1'
#define BROYDEN '2'
#define AMBOS '3'

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

main ()

{

/*--------------------------------------------------------------------------
	    INICIO DE LA ZONA DE DECLARACION DE VARIABLES
--------------------------------------------------------------------------*/

int i;          /* CONTADOR */

/* DECLARACION DE LA VARIABLE DE ESTRUCTURA QUE VAMOS A UTILIZAR
   PARA MANEJAR LOS DATOS DEL PROBLEMA */

struct datos parametros;

/* ITERACIONES EN LAS QUE SE RESOLVERA EL PROBLEMA CON EL METODO DE NEWTON */

int newton_ite;

/* ITERACIONES EN LAS QUE SE RESOLVERA EL PROBLEMA CON EL METODO DE BROYDEN */

int broyden_ite;

/* PUNTERO PARA RECIBIR UNA ZONA ASIGNADA DE MEMORIA, DEPENDIENDO DEL
   NUMERO DE SEGMENTOS DEL CANAL, SE UTILIZARA PARA GUARDAR LA
   APROXIMACION INICIAL A LA SOLUCION */

double *vector;

/* PUNTEROS DONDE SE VAN A ALMACENAR LOS ERRORES COMETIDOS */

double *error_new,
       *error_broy;

char respuesta = 'C'; /* INDICA SI CONTINUAMOS O TERMINAMOS */

/*--------------------------------------------------------------------------
		FIN DE LA ZONA DE DECLARACION DE VARIABLES
--------------------------------------------------------------------------*/


/* INICIALIZACION DE LA VARIABLE DE ESTRUCTURA */

parametros.pre = 6;
parametros.ite = 25;
parametros.N = 20;
parametros.newton_ite = 0;
parametros.broyden_ite = 0;

parametros.tol = 1e-2;
parametros.fuerza = 0.;
parametros.X = 2.;
parametros.incr_y = 0.2;
parametros.velocidad_inicial = 0.;
parametros.gravedad = 32.2;

/* ASIGNACION INICIAL DE MEMORIA */

vector = (double *)calloc(parametros.N, sizeof(double) );

/* ASIGNACION INICIAL A LOS PRIMEROS 20 VALORES DE vector */

for (i=1;i<=(parametros.N);i++)
	{
	vector[i-1] = i/(20.);
	}

system ("rotulo"); /* ROTULO DE PRESENTACION */

while ( respuesta == 'C' )

	{       /* INICIO WHILE */

	/* ESTA VARIABLE SE UTILIZARA PARA INICIALIZAR A CERO LA ZONA
	   DE MEMORIA QUE SE UTILIZARA SI SE AMPLIA EL NUMERO DE SEGMENTOS
	   DEL CANAL, YA QUE LA FUNCION realloc NO INICIALIZA LA ZONA A
	   CERO */

	int control = (parametros.N);

	/* CONTENDRA EL METODO QUE VAMOS A UTILIZAR */

	char metodo;

	clrscr (); /* BORRAR PANTALLA */

	/* ENUNCIADO DEL PROBLEMA Y PARAMETROS GENERALES DEL PROBLEMA */

	menu (&parametros);

	/* ASIGNACION DE MEMORIA PARA error_new Y error_broy */

	error_new = (double *)calloc(parametros.ite,sizeof(double));

	/* SI HAY ERROR EN LA ASIGNACION DE MEMORIA SAL FUERA */

	if ( error_new == NULL )

		{
		errores_mem ();
		exit (1);
		}

	error_broy = (double *)calloc(parametros.ite,sizeof(double));

	/* SI HAY ERROR EN LA SIGNACION DE MEMORIA SAL FUERA */

	if ( error_broy == NULL )

		{
		errores_mem ();
		exit (1);
		}

	/* REDIMENSION DE vector SEGUN LOS NUEVOS PARAMETROS DE N */

	if ( (parametros.N) != control )

		{       /* PRINCIPIO DEL if DE LA REDIMENSION */

		vector = (double *)realloc(vector,(parametros.N)*sizeof(double) );

		/* SI HUBO ERROR EN LA REDIMENSION SAL FUERA DEL PROGRAMA */

		if ( vector == NULL )
			{
			errores_mem();
			exit (1);
			}

		/* INICIALIZACION DE LA NUEVA ZONA A CERO */

		if ( (parametros.N) > control)

			{

			for(i=control;i<(parametros.N);i++)

				{
				vector[i] = 0.;
				}
			}

		}       /* FIN DEL if DE LA REDIMENSION */

	/* INTRODUCCION DEL VECTOR DE APROXIMACION INICIAL */

	menu_variables(parametros.N, vector, parametros.pre);

	/* REESTABLECER ATRIBUTOS ORIGINALES DEL COLOR EN MODO TEXTO */

	textbackground(BLACK);
	textcolor(LIGHTGRAY);

	/* ELECCION DEL METODO */

	metodo = plan_met();

	/* RESOLVER EL PROBLEMA CON EL METODO ELEGIDO POR EL USUARIO */

	empezar(metodo, &parametros, vector, error_new, error_broy,
		&newton_ite, &broyden_ite);

	/* LIBERA LA MEMORIA ASIGNADA A error_new Y A error_broy */

	free(error_new);
	free(error_broy);

	respuesta = opciones ();

	}       /* FIN WHILE */

clrscr ();

}
