#include <math.h>

#include "datos.h"

/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */                                                                            
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* Funcion que la regla del trapecio compuesta para estimar el valor de */
/* una integral. Donde dblFuncion es una funcion que devuelve el valor	*/
/* de la funcion, que se quiere calcular su integral, en el punto dblX. */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void TrapecioCompuesto(DatosIntgr *ptstrDatos, 
		double (*dblFuncion)(double dblX))

{
int	i;

double	dblPaso = fabs(((ptstrDatos->dblFinal)-(ptstrDatos->dblInicio))
			/((double)(ptstrDatos->intNumIntervalos)));

(ptstrDatos->dblResulT) = (*dblFuncion)(ptstrDatos->dblInicio);
(ptstrDatos->dblResulT) += (*dblFuncion)(ptstrDatos->dblFinal);

for(i=1;i<(ptstrDatos->intNumIntervalos);i++)
	(ptstrDatos->dblResulT) += (2*((*dblFuncion)((ptstrDatos->dblInicio)+
			(i*dblPaso))));

(ptstrDatos->dblResulT) *= dblPaso/2.;

return;
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* Funcion que calcula el error cometido por la regla del trapecio al   */
/* integrar en las condiciones de ptstrDatos. Donde dblDer2 es una      */
/* funcion que devuelve el valor de la segunda derivada de la funcion   */
/* que estamos integrando en el punto dblX.                             */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void ErrorTrapecio(DatosIntgr *ptstrDatos, double (*dblDer2)(double dblX))

{
int	i;

double 	dblPaso = fabs(((ptstrDatos->dblFinal)-(ptstrDatos->dblInicio))
			/((double)(ptstrDatos->intNumIntervalos))),
	dblSubPaso = dblPaso/(1000.),
	dblA,		/* EXTREMO INFERIOR DEL SUBINTERVALO */
	dblB,		/* EXTREMO SUPERIOR DEL SUBINTERVALO */
	dblPunto,	/* PUNTO EN EL QUE EVALUAREMOS LA DERIVADA */
	dblAux = .0,
	dblMax = .0;	/* MAXIMO DE LA DERIVADA EN EL SUBINTERVALO */

/* INICIALIZAMOS EL ERROR A CERO */

ptstrDatos->dblErrorT = .0;

/* INICIALIZAMOS LOS EXTREMOS DEL SUBINTERVALO */

dblA = (ptstrDatos->dblInicio);
dblB = dblA+dblPaso;

for(i=0;i<(ptstrDatos->intNumIntervalos);i++)

	{	/* INICIO PRIMER for */

	dblMax = .0;

	for(dblPunto = dblA;dblPunto<=dblB;dblPunto += dblSubPaso)

		{	/* INICIO SEGUNDO for */

		dblAux = fabs((*dblDer2)(dblPunto));

		if ( dblAux > dblMax )
			dblMax = dblAux;
			
		}	/* FINAL SEGUNDO for */

	/* NUEVO SUBINTERVALO */

	dblA = dblB;
	dblB += dblPaso;

	/* ALMACENAMOS EL MAXIMO EN EL SUBINTERVALO */

	(ptstrDatos->dblErrorT) += dblMax;

	}	/* FINAL PRIMER for */

(ptstrDatos->dblErrorT) /= 12.;
(ptstrDatos->dblErrorT) *= pow(dblPaso,3);

return;
}
