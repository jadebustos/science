/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*----------------------------------------------------------------------------
  FUNCION QUE SACA A DISCO LA SOLUCION DEL PROBLEMA ENCONTRADO, SI LO
  HEMOS RESUELTO MEDIANTE EL METODO DE NEWTON LO SACA AL FICHERO
  newton.sol, SI LO HEMOS RESUELTO MEDIANTE EL METODO DE BROYDEN LO
  SACA AL FICHERO broyden.sol.
---------------------------------------------------------------------------*/

#include <stdio.h>
#include "struct.h"

#define NEWTON 1
#define BROYDEN 2

void salida_a_disco(struct datos *ptparametros,	double *solucion, 
                    int iteraciones, int metodo, 
		    double *aprox_inicial, double error)

{
int i;  /* CONTADOR */

FILE *fpt;    /* PUNTERO A LA ESTRUCTURA INTERNA "FILE" */

switch(metodo)

	{       /* INICIO SWITCH */

	case NEWTON:

		{       /* INICIO "NEWTON"  */

		/* ABRIMOS EL ARCHIVO PARA A¥ADIR LOS NUEVOS DATOS */

		fpt = fopen("newton.sol", "a");

		fprintf(fpt,"\nResultados obtenidos mediante el metodo"
				" de Newton.\n\n");

		fprintf(fpt,"Se ha resuelto en %d iteraciones, con un error de "
			"%.*E.\n\n",
			iteraciones, ptparametros->pre, error);

		fprintf(fpt,"N = %d\tTolerancia = %.*E.\n\n", ptparametros->N, 
			ptparametros->pre, ptparametros->tol);

		fprintf(fpt,"X = %.*g\tFuerza = %.*g.\n\n", ptparametros->pre, 
			ptparametros->X, ptparametros->pre, 
			ptparametros->fuerza);

		fprintf(fpt,"Gravedad = %.*g Pies/(seg^2)\tIncr_y = %.*g.\n\n"
				, ptparametros->pre, ptparametros->gravedad, 
				ptparametros->pre, ptparametros->incr_y);

		fprintf(fpt,"Velocidad inicial = %.*g.\n\n",
				ptparametros->pre, 
				ptparametros->velocidad_inicial);

		/* IMPRIMIR LA APROXIMACION INICIAL */

		fprintf(fpt,"La aproximacion inicial es:\n\n");

		for(i=0;i<(ptparametros->N);i++)

			{       /* INICIO FOR i */

			fprintf(fpt,"é(%d) = %.*g radianes.\n", i+1, 
				ptparametros->pre, aprox_inicial[i]);

			}       /* FINAL FOR i */
		
		fprintf(fpt,"\n\nLas soluciones obtenidas son las siguientes:\n\n");

	       /* IMPRIMIR EN FICHERO LAS SOLUCIONES OBTENIDAS */

		for(i=0;i<(ptparametros->N);i++)

			{       /* INICIO FOR i */

			fprintf(fpt,"é(%d) = %.*g radianes.\n", i+1, 
				ptparametros->pre, solucion[i]);

			}       /* FINAL FOR i */

		/* CERRAMOS EL FICHERO newton.sol */

		fclose(fpt);
		
		break;
		}       /* INICIO "NEWTON" */

	case BROYDEN:

		{       /* INICIO "BROYDEN" */

		/* ABRIMOS EL ARCHIVO PARA A¥ADIR LOS NUEVOS DATOS */

		fpt = fopen("broyden.sol", "a");

		fprintf(fpt,"\nResultados obtenidos mediante el metodo"
				" de Broyden.\n\n");

		fprintf(fpt,"Se ha resuelto en %d iteraciones, con un error de "
			"%.*E.\n\n", iteraciones, 
			ptparametros->pre, error);

		fprintf(fpt,"N = %d\tTolerancia = %.*E.\n\n", ptparametros->N, 
			ptparametros->pre, ptparametros->tol);

		fprintf(fpt,"X = %.*g\tFuerza = %.*g.\n\n", ptparametros->pre, 
			ptparametros->X, ptparametros->pre, 
			ptparametros->fuerza);

		fprintf(fpt,"Gravedad = %.*g Pies/(seg^2)\tIncr_y = %.*g.\n\n",
			ptparametros->pre, ptparametros->gravedad, 
			ptparametros->pre, ptparametros->incr_y);

		fprintf(fpt,"Velocidad inicial = %.*g.\n\n",
			ptparametros->pre, ptparametros->velocidad_inicial);
		
		/* IMPRIMIR LA APROXIMACION INICIAL */

		fprintf(fpt,"La aproximacion inicial es:\n\n");

		for(i=0;i<(ptparametros->N);i++)

			{       /* INICIO FOR i */

			fprintf(fpt,"é(%d) = %.*g radianes.\n", i+1, 
				ptparametros->pre, aprox_inicial[i]);

			}       /* FINAL FOR i */

		fprintf(fpt,"\n\nLas soluciones obtenidas son las siguientes:\n\n");

		/* IMPRIMIR EN FICHERO LAS SOLUCIONES OBTENIDAS */

		for(i=0;i<(ptparametros->N);i++)

			{       /* INICIO FOR i */

			fprintf(fpt,"é(%d) = %.*g radianes.\n", i+1, 
				ptparametros->pre, solucion[i]);

			}       /* FINAL FOR i */

		/* CERRAMOS EL FICHERO broyden.sol */

		fclose(fpt);

		break;

		}       /* FIN "BROYDEN" */

	}       /* FIN SWITCH */


return;
}
