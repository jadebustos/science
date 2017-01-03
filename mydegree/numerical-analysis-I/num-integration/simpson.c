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
/* Funcion que utiliza le regla de simpson compuesta para calcular el   */
/* valor de una intgral. Donde dblFuncion es una funcion que devuelve 	*/
/* el valor de la funcion, que se quiere calcular su integral, en el    */
/* punto dblX.                                                          */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void SimpsonCompuesto(DatosIntgr *ptstrDatos, 
		double (*dblFuncion)(double dblX))

{
int	i,
	intNumInter;

double	dblPaso;

/* NECESITAMOS UN NUMERO PAR DE INTERVALOS */

if ( ((ptstrDatos->intNumIntervalos) % 2) == 0 )
	intNumInter = (ptstrDatos->intNumIntervalos);

else
	intNumInter = (ptstrDatos->intNumIntervalos)+1;

dblPaso = fabs(((ptstrDatos->dblFinal)-(ptstrDatos->dblInicio))
			/(intNumInter));

(ptstrDatos->dblResulS) = (*dblFuncion)(ptstrDatos->dblInicio);
(ptstrDatos->dblResulS) += (*dblFuncion)(ptstrDatos->dblFinal);

for(i=2;i<=(intNumInter/2);i++)
	(ptstrDatos->dblResulS) += (2*((*dblFuncion)
		((ptstrDatos->dblInicio)+(2*dblPaso*(i-1)))));

for(i=1;i<=(intNumInter/2);i++)
	(ptstrDatos->dblResulS) += (4*((*dblFuncion)
		((ptstrDatos->dblInicio)+(dblPaso*(2*i-1)))));
	
(ptstrDatos->dblResulS) *= dblPaso/3.;

return;
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* Funcion que calcula el error cometido por la regla de simpson al     */
/* integrar en las condiciones de ptstrDatos. Donde dblDer4 es una      */
/* funcion que devuelve el valor de la cuarta derivada de la funcion    */
/* que estamos integrando en el punto dblX.                             */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void ErrorSimpson(DatosIntgr *ptstrDatos, double (*dblDer4)(double dblX))

{
int	i,
	intNumInter;

double 	dblPaso, 
	dblSubPaso,
	dblA,		/* EXTREMO INFERIOR DEL SUBINTERVALO */
	dblB,		/* EXTREMO SUPERIOR DEL SUBINTERVALO */
	dblPunto,	/* PUNTO EN EL QUE EVALUAREMOS LA DERIVADA */
	dblAux = .0,
	dblMax = .0;	/* MAXIMO DE LA DERIVADA EN EL SUBINTERVALO */

/* NECESITAMOS UN NUMERO PAR DE INTERVALOS */

if ( ( (ptstrDatos->intNumIntervalos) % 2 ) == 0 )
	intNumInter = (ptstrDatos->intNumIntervalos);

else
	intNumInter = (ptstrDatos->intNumIntervalos)+1;

/* FIJAMOS EL PASO */

dblPaso = fabs(((ptstrDatos->dblFinal)-(ptstrDatos->dblInicio))
		/((double)intNumInter));

dblSubPaso = dblPaso/(1000.);

/* INICIALIZAMOS EL ERROR A CERO */

ptstrDatos->dblErrorS = .0;

/* INICIALIZAMOS LOS EXTREMOS DEL SUBINTERVALO */

dblA = (ptstrDatos->dblInicio);
dblB = dblA+dblPaso;

for(i=0;i<intNumInter;i++)

	{	/* INICIO PRIMER for */

	dblMax = .0;

	for(dblPunto = dblA;dblPunto<=dblB;dblPunto += dblSubPaso)

		{	/* INICIO SEGUNDO for */

		dblAux = fabs((*dblDer4)(dblPunto));

		if ( dblAux > dblMax )
			dblMax = dblAux;
			
		}	/* FINAL SEGUNDO for */

	/* NUEVO SUBINTERVALO */

	dblA = dblB;
	dblB += dblPaso;

	/* ALMACENAMOS EL MAXIMO EN EL SUBINTERVALO */

	(ptstrDatos->dblErrorS) += dblMax;

	}	/* FINAL PRIMER for */

(ptstrDatos->dblErrorS) /= 90.;
(ptstrDatos->dblErrorS) *= pow(dblPaso,5);

return;
}
