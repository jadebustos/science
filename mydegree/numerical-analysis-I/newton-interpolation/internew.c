/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */                                                                            
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*									*/
/* dblPuntos    -> PUNTOS EN LOS QUE INTERPOLAMOS                       */
/* dblValor     -> VALOR EN DICHOS PUNTOS				*/
/* dblDD        -> DIFERENCIAS DIVIDIDAS				*/
/* dblPolinomio -> POLINOMIO INTERPOLADOR DE NEWTON			*/
/* intN         -> NUMERO DE PUNTOS					*/
/*									*/
/* ES NECESARIO QUE TODOS LOS ELEMENTOS DE dblPolinomio ESTEN           */
/* INICIALIZADOS A CERO                                                 */
/*									*/
/* dblAux       -> IREMOS ALMACENANDO LOS PRODUCTOS                     */
/*			(x-x_0)*...*(x-x_i)				*/
/* dblTmp       -> ALMACENAMIENTOS TEMPORALES                           */
/* dblPolGrado1 -> ALMACENAREMOS LOS POLINOMIOS x-x_i, 0 <= i < intN    */
/*									*/

#include <stdlib.h>

#include "memoria.h"
#include "polinomios.h"

#define BIEN 0
#define MAL  1
 
int intPolNewton(double *dblPuntos, double *dblValor, int intN, 
		double *dblDD, double *dblPolinomio)

{
int	i,
	j;

double	*dblAux,
	*dblTmp,
	*dblPolGrado1;

/* RESERVA DE MEMORIA */

dblAux = (double *)dblAsigMemVec(intN);

if ( dblAux == NULL )

	{
	return(MAL);	/* FIN */
	}

dblPolGrado1 = (double *)dblAsigMemVec(2);

if ( dblPolGrado1 == NULL )

	{
	free(dblAux);
	return(MAL);	/* FIN */
	}

dblTmp = (double *)dblAsigMemVec(intN);

if ( dblTmp == NULL )

	{
	free(dblAux);
	free(dblPolGrado1);

	return(MAL);	/* FIN */
	}

dblPolinomio[0] = dblValor[0]-(dblPuntos[0]*dblDD[1]);
dblPolinomio[1] = dblDD[1];

dblAux[1] = dblPolGrado1[1] = 1.;
dblAux[0] = -dblPuntos[0];

for(i=1;i<intN-1;i++)

	{	/* INICIO PRIMER for */

	dblPolGrado1[0] = -dblPuntos[i];

	MultPoli(dblPolGrado1, 1, dblAux, i, dblTmp);

	for(j=0;j<=i+1;j++)

		{	/* INICIO SEGUNDO for */

		dblPolinomio[j] += (dblDD[i+1]*dblTmp[j]);

		dblAux[j] = dblTmp[j];

		dblTmp[j] = .0; /* NECESARIO PARA MultPoli */

		}	/* FINAL SEGUNDO for */

	}	/* FINAL PRIMER for */

/* LIBERAR MEMORIA */

free(dblAux);
free(dblPolGrado1);
free(dblTmp);

return (BIEN);	/* FIN */ 
}
