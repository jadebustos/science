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
/* Funcion que utiliza le regla de los 3/8 compuesta para calcular el   */
/* valor de una intgral. Donde dblFuncion es una funcion que devuelve 	*/
/* el valor de la funcion, que se quiere calcular su integral, en el    */
/* punto dblX.                                                          */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void TresOctCompuesto(DatosIntgr *ptstrDatos, 
		double (*dblFuncion)(double dblX))

{
int	i,
	intNumInter;

double	dblPaso;

/* NECESITAMOS UN NUMERO IMPAR DE INTERVALOS */

if ( ((ptstrDatos->intNumIntervalos) % 2) == 0 )
	intNumInter = (ptstrDatos->intNumIntervalos)+1;

else
	intNumInter = (ptstrDatos->intNumIntervalos);

dblPaso = fabs(((ptstrDatos->dblFinal)-(ptstrDatos->dblInicio))
			/((double)intNumInter));

(ptstrDatos->dblResul38) = .0;

for(i=0;i<intNumInter;i++)
	(ptstrDatos->dblResul38) += (
	(*dblFuncion)((ptstrDatos->dblInicio)+(dblPaso*i))
				 +3*(
	(*dblFuncion)((ptstrDatos->dblInicio)+(dblPaso*(i+(1./3.))))+
	(*dblFuncion)((ptstrDatos->dblInicio)+(dblPaso*(i+(2./3.))))
				    )	
                                    );

for(i=1;i<=intNumInter;i++)
	(ptstrDatos->dblResul38) += (
		(*dblFuncion)((ptstrDatos->dblInicio)+(dblPaso*i))
		                    );
	
(ptstrDatos->dblResul38) *= ((3.*dblPaso)/24.);

return;
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* Funcion que calcula el error cometido por la regla de los 3/8 al     */
/* integrar en las condiciones de ptstrDatos. Donde dblDer4 es una      */
/* funcion que devuelve el valor de la cuarta derivada de la funcion    */
/* que estamos integrando en el punto dblX.                             */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void ErrorTresOct(DatosIntgr *ptstrDatos, double (*dblDer4)(double dblX))

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

/* NECESITAMOS UN NUMERO IMPAR DE INTERVALOS */

if ( ( (ptstrDatos->intNumIntervalos) % 2 ) == 0 )
	intNumInter = (ptstrDatos->intNumIntervalos)+1;

else
	intNumInter = (ptstrDatos->intNumIntervalos);

/* FIJAMOS EL PASO */

dblPaso = fabs(((ptstrDatos->dblFinal)-(ptstrDatos->dblInicio))
		/((double)intNumInter));

dblSubPaso = dblPaso/(1000.);

/* INICIALIZAMOS EL ERROR A CERO */

ptstrDatos->dblError38 = .0;

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

	(ptstrDatos->dblError38) += dblMax;

	}	/* FINAL PRIMER for */

(ptstrDatos->dblError38) *= ((3./80.)*pow(dblPaso,5));

return;
}
