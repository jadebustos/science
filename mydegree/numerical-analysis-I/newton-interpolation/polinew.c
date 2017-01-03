/*									*/
/* intN         -> NUMERO DE PUNTOS EN LOS QUE VAMOS A INTERPOLAR       */
/* dblPuntos    -> PUNTOS EN LOS QUE VAMOS A INTERPOLAR                 */
/* dblValor     -> VALOR EN DICHOS PUNTOS                               */
/* dblDD        -> DIFERENCIAS DIVIDIDAS NECESARIAS PARA EL POLINOMIO   */
/* dblPolinomio -> POLINOMIO INTERPOLADOR                               */
/*									*/ 

#include <stdio.h>
#include <stdlib.h>

#include "memoria.h"
#include "difdiv.h"
#include "internew.h"

#define BIEN 0
#define MAL  1

/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */                                                                            
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

int main (void)

{
int	i,
	intN;

double	*dblPuntos,
	*dblValor,
	*dblDD,
	*dblPolinomio;

printf("Numero de puntos: ");
scanf("%d", &intN);

/* RESERVA DE MEMORIA */

dblPuntos = (double *)dblAsigMemVec(intN);

if ( dblPuntos == NULL )
	{
	printf("Hubo un error en la asignacion de memoria.\n");

	return (MAL);
	}

dblValor = (double *)dblAsigMemVec(intN);

if ( dblValor == NULL )
	{
	printf("Hubo un error en la asignacion de memoria.\n");

	free(dblPuntos);
	return (MAL);
	}

dblDD = (double *)dblAsigMemVec(intN);

if ( dblDD == NULL )

	{
	printf("Hubo un error en la asignacion de memoria.\n");

	free(dblPuntos);
	free(dblValor);

	return (MAL);
	}

dblPolinomio = (double *)dblAsigMemVec(intN);

if ( dblPolinomio == NULL )

	{
	printf("Hubo un error en la asignacion de memoria.\n");

	free(dblPuntos);
	free(dblValor);
	free(dblDD);

	return(MAL);
	}

/* PETICION DE DATOS */

for(i=0;i<intN;i++)

	{
	double	tmp = .0;

	printf("x[%d] = ", i);
	scanf("%lf", &tmp);

	dblPuntos[i] = tmp;

	printf("f(x[%d]) = ", i);
	scanf("%lf", &tmp);

	dblValor[i] = tmp;
	}

/* CALCULAMOS LAS DIFERENCIAS DIVIDIDAS QUE INTERVIENEN EN EL POLINOMIO */

for(i=0;i<intN;i++)
	dblDD[i] = dblDifDiv(dblPuntos, dblValor, 0, i);

/* CALCULAMOS EL POLINOMIO INTERPOLADOR */

i = intPolNewton(dblPuntos, dblValor, intN, dblDD, dblPolinomio);

printf("El polinomio interpolador es:\n");

for(i=0;i<intN;i++)
	printf("Coeficiente de grado %d es %lf\n", i, dblPolinomio[i]);

/* LIBERAR MEMORIA */

free(dblPuntos);
free(dblValor);
free(dblDD);
free(dblPolinomio);

return (BIEN);
}
