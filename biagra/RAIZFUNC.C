#include <math.h>

#include <biagra/struct.h>
#include <biagra/const.h>

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/*	B.I.A.G.R.A.	(c) 1998 Jose Angel de Bustos Perez		*/
/*			 <jadebustos@gmail.com>         		*/
/*									*/
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* raizfunc.c     Jose Angel de Bustos Perez                            */
/*                                                                      */
/* Funciones para calcular raices de funciones.                         */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/


/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* IMPORTANTE!!!                                                        */
/*                                                                      */
/*     1) El autor no se responsabiliza de los posibles bugs(si los     */
/*        hubiera) ni del mal uso de esta biblioteca.                   */
/*                                                                      */
/*     2) Esta biblioteca ha sido desarrollada y testeada bajo LiNUX.   */
/*                                                                      */ 
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula por el metodo de Newton una raiz de una          */
/* funcion.                                                             */
/*                                                                      */
/* La funcion devuelve:                                                 */
/*                                                                      */
/*         FALSE    No se calculo la raiz de la funcion en las          */
/*                  condiciones dadas(NMI y Tolerancia).                */
/*         DIV_CERO Division por Cero.                                  */
/*         TRUE     Se calculo la raiz de la funcion en las             */
/*                  condiciones dadas.                                  */
/*                                                                      */
/* Funcion es una funcion que almacena en ptdblRes el valor de la       */
/* funcion que se quiere calcular una raiz en el punto dblPunto, esta   */
/* funcion devuelve los siguientes codigos:                             */
/*                                                                      */
/*         DIV_CERO Hubo division por cero.                             */
/*         TRUE     No hubo division por cero.                          */
/*                                                                      */
/* Derivada es la una funcion que funciona igual que la anterior pero   */
/* con la derivada de la funcion anterior.                              */
/*                                                                      */
/*      B.I.A.G.R.A.        Jose Angel de Bustos Perez                  */
/*                                                                      */
/*	BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int NewtonFunc(DatosAprxFunc *ptstrDatos, 
	int (*Funcion)(double dblPunto, double *ptdblRes),
	int (*Derivada)(double dblPunto, double *ptdblRes))

{
int		i,
		intRes = TRUE,
		intNMIAbs = abs(ptstrDatos->intNMI);

double 	dblAprxNew   = .0,
	dblAprxOld   = (ptstrDatos->dblx0),
	dblValorFunc = .0,
	dblValorDeri = .0,
	dblTolAbs    = fabs(ptstrDatos->dblTol);

for(i=1;i<=intNMIAbs;i++)

	{	/* INICIO for */

	intRes = (*Funcion)(dblAprxOld, &dblValorFunc);

	if ( intRes == DIV_CERO )	/* DIVISION POR CERO */
		return (DIV_CERO);	/* FIN */

	intRes = (*Derivada)(dblAprxOld, &dblValorDeri);

	if (intRes == DIV_CERO )	/* DIVISION POR CERO */
		return (DIV_CERO);	/* FIN */

	if ( dblValorDeri == .0 )	/* DIVISION POR CERO */
		return (DIV_CERO);	/* FIN */ 

	/* NUEVA APROXIMACION */

	dblAprxNew = dblAprxOld - (dblValorFunc/dblValorDeri);

	/* CALCULO DEL ERROR */

	ptstrDatos->dblError = fabs(dblAprxOld-dblAprxNew);

	if ( (ptstrDatos->dblError) < dblTolAbs )
		{
		ptstrDatos->dblSolucion = dblAprxNew;

		return (TRUE);	/* FIN */
		}

	dblAprxOld = dblAprxNew;
					
	}	/* FINAL for */
	 	
return (FALSE); 	/* FIN */
}
