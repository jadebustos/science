#include <math.h>
#include <stdlib.h>

#include <biagra/struct.h>
#include <biagra/polinomios.h>
#include <biagra/const.h>
#include <biagra/resmem.h>

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
/* polinomios.c     Jose Angel de Bustos Perez                          */
/*                                                                      */
/* Funciones para el tratamiento de polinomios.                         */
/*                                                                      */
/* Los polinomios se almacenaran en un puntero double de la siguiente   */
/* manera:                                                              */
/*                                                                      */
/* Dado un polinomio de grado n - 1 tendra n coeficientes, si lo        */
/* almacenamos en un puntero double polinomio (double *polinomio)       */
/* para el cual se habra reservado memoria para n elementos, entonces   */
/* en el elemento i-esimo del puntero estara el coeficiente i(recordar  */
/* que el coeficiente i es el que acompaña al monomio de grado i), de   */
/* tal forma que:                                                       */
/*                                                                      */
/* *(polinomio) = polinomio[0] = termino independiente                  */
/* *(polinomio + (n-1)) = polinomio[n-1] = coeficiente de x^(n-1)       */
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
/* Funcion que calcula el valor del polinomio ptstrPoli en el punto     */
/* dblPunto, la funcion devuelve dicho valor.                           */
/*                                                                      */
/*      B.I.A.G.R.A.        Jose Angel de Bustos Perez                  */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

double dblEvaluarPolinomio(Polinomio *ptstrPoli, double dblPunto)

{
double 	dblRes = .0;

int		i = 0,
		intGradoAbs = abs(ptstrPoli->intGrado);

if ( dblPunto == .0 )
	return (ptstrPoli->dblCoefi[0]);

switch (intGradoAbs)

{	/* INICIO switch */

case 0:		/* POLINOMIOS DE GRADO CERO */

	{	/* INICIO case 0: */
	
	break;
	}	/* FINAL case 0: */

default:	/* POLINOMIOS DE GRADO MAYOR O IGUAL QUE UNO */

	{ 	/* INICO default */

	dblRes = dblPunto*(ptstrPoli->dblCoefi[intGradoAbs]);
	
	for(i=intGradoAbs-1;i>=1;i--)

		{	/* INICIO for */

		dblRes += (ptstrPoli->dblCoefi[i]);
		dblRes *= dblPunto;
		
		}	/* FINAL for */
		
	break;
	}	/* FINAL default */
	
}	/* FINAL switch */

dblRes += ptstrPoli->dblCoefi[0];

return (dblRes);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula la derivada N-esima de ptstrPolinomio y la       */
/* almacena en ptstrDerivada.                                           */
/*                                                                      */
/* La funcion devuelve los siguientes codigos:							*/
/*																		*/
/*	ERR_AMEM -> Hubo un error en la asignacion de memoria.				*/
/*	TRUE     -> Se calculo con exito la derivada.						*/
/*																		*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez						*/
/*																		*/
/*	BIbliotecA de proGRamacion cientificA.								*/
/* 																		*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int DerivadaPolinomio(Polinomio *ptstrPoli, Polinomio *ptstrDerivada, int intN)

{

int	intAbsN = abs(intN),
	i,
	j;

/* DETERMINAMOS EL GRADO DE LA DERIVADA */

if ( intAbsN >= (ptstrPoli->intGrado) )
	(ptstrDerivada->intGrado) = 0;

else
	(ptstrDerivada->intGrado) = ((ptstrPoli->intGrado)-intAbsN);

/* COMPROBAMOS SI EL MIEMBRO dblCoefi DE ptstrDerivada HA SIDO DIMENSIONADO,
   SI LO HA SIDO LIBERAMOS LA MEMORIA ASIGNADA Y POSTERIORMEMTE ASIGNAMOS LA
   MEMORIA NECESARIA PARA CONTENER LOS COEFICIENTES DE LA DERIVADA */

if ( (ptstrDerivada->dblCoefi) != NULL )
	free(ptstrDerivada->dblCoefi);

(ptstrDerivada->dblCoefi) = (double *)dblPtAsigMemVec((ptstrDerivada->intGrado)+1);

if ( (ptstrDerivada->dblCoefi) == NULL )
	return (ERR_AMEM);	/* FIN */

/* CACULAMOS LA DERIVADA */

for(i=0;i<=(ptstrDerivada->intGrado);i++)

	{	/* INICIO PRIMER for */

	(ptstrDerivada->dblCoefi[i]) = (ptstrPoli->dblCoefi[i+intAbsN]);
	
	for(j=i+intAbsN;j>i;j--)
		(ptstrDerivada->dblCoefi[i]) *= j;

	}	/* FINAL PRIMER for */

return (TRUE);
}


/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que suma el polinomio ptstrPoli1 con el polinomio            */
/* ptstrPoli2 y lo almacena en ptstrRes. 								*/
/*                                                                      */
/* La funcion devuelve los siguientes codigos:							*/
/*																		*/
/*	ERR_AMEM -> Hubo un error en la asignacion de memoria.				*/
/*	TRUE     -> Se multiplico con exito los dos polinomios.				*/
/*																		*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez						*/
/*																		*/
/*	BIbliotecA de proGRamacion cientificA.								*/
/*																		*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int SumarPolinomios(Polinomio *ptstrPoli1, Polinomio *ptstrPoli2, 
		Polinomio *ptstrRes)

{
int	i;

/* CALCULO DEL ORDEN DE LA SUMA */

(ptstrRes->intGrado) = ((ptstrPoli1->intGrado) >= (ptstrPoli2->intGrado)) ? 
			(ptstrPoli1->intGrado) : (ptstrPoli2->intGrado);

/* SI ESTA DIMENSIONADO EL MIEMBRO dblCoefi DE ptstrRes LIBERAMOS LA MEMORIA
   Y ASIGNAMOS LA MEMORIA NECESARIA */

if ( (ptstrRes->dblCoefi) != NULL )
	free (ptstrRes->dblCoefi);

(ptstrRes->dblCoefi) = (double *)dblPtAsigMemVec((ptstrRes->intGrado)+1);

if ( (ptstrRes->dblCoefi) == NULL )
	return (ERR_AMEM);	/* FIN */

/* CALCULAMOS LA SUMA */

for(i=0;i<=(ptstrPoli1->intGrado);i++)
	(ptstrRes->dblCoefi[i]) += (ptstrPoli1->dblCoefi[i]);

for(i=0;i<=(ptstrPoli2->intGrado);i++)
	(ptstrRes->dblCoefi[i]) += (ptstrPoli2->dblCoefi[i]);

return (TRUE);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que resta el polinomio ptstrPoli1 con el polinomio           */
/* ptstrPoli2 y lo almacena en ptstrRes. 								*/
/*                                                                      */
/* La funcion devuelve los siguientes codigos:							*/
/*																		*/
/*	ERR_AMEM -> Hubo un error en la asignacion de memoria.				*/
/*	TRUE     -> Se multiplico con exito los dos polinomios.				*/
/*																		*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez						*/
/*																		*/
/*	BIbliotecA de proGRamacion cientificA.								*/
/*																		*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int RestarPolinomios(Polinomio *ptstrPoli1, Polinomio *ptstrPoli2, 
		Polinomio *ptstrRes)
                
{
int	i;

/* CALCULO DEL ORDEN DE LA SUMA */

(ptstrRes->intGrado) = ((ptstrPoli1->intGrado) >= (ptstrPoli2->intGrado)) ? 
			(ptstrPoli1->intGrado) : (ptstrPoli2->intGrado);

/* SI ESTA DIMENSIONADO EL MIEMBRO dblCoefi DE ptstrRes LIBERAMOS LA MEMORIA
   Y ASIGNAMOS LA MEMORIA NECESARIA */

if ( (ptstrRes->dblCoefi) != NULL )
	free (ptstrRes->dblCoefi);

(ptstrRes->dblCoefi) = (double *)dblPtAsigMemVec((ptstrRes->intGrado)+1);

if ( (ptstrRes->dblCoefi) == NULL )
	return (ERR_AMEM);	/* FIN */

for(i=0;i<=(ptstrPoli1->intGrado);i++)
	(ptstrRes->dblCoefi[i]) += (ptstrPoli1->dblCoefi[i]);

/* RESTAMOS strPoli2 A strPoli1 */

for(i=0;i<=(ptstrPoli2->intGrado);i++)
	(ptstrRes->dblCoefi[i]) -= (ptstrPoli2->dblCoefi[i]);

return (TRUE);
}          
                
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que multiplica el polinomio ptstrPoli1 por el polinomio      */
/* ptstrPoli2) y lo almacena ptstrRes.                                  */
/* 																		*/
/* La funcion devuelve los siguientes codigos:							*/
/*																		*/
/*	ERR_AMEM -> Hubo un error en la asignacio de memoria.				*/
/*	TRUE     -> Se multiplico con exito los dos polinomios.         	*/
/*																		*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez						*/
/*																		*/
/*	BIbliotecA de proGRamacion cientificA.								*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int MultiplicarPolinomios(Polinomio *ptstrPoli1, Polinomio *ptstrPoli2,
		Polinomio *ptstrRes)

{
int	i,
	j;

/* GRADO DEL PRODUCTO DE AMBOS POLINOMIOS */

(ptstrRes->intGrado) = (ptstrPoli1->intGrado) + (ptstrPoli2->intGrado);

/* COMPROBAMOS SI SE HA RESERVADO MEMORIA PARA EL MIEMBRO dblCoefi DE ptstrRes,
   EN CASO AFIRMATIVO LIBERAMOS Y REASIGNAMOS LA MEMORIA NECESARIA */

if ( (ptstrRes->dblCoefi) != NULL )
	free((ptstrRes->dblCoefi));

(ptstrRes->dblCoefi) = (double *)dblPtAsigMemVec((ptstrRes->intGrado)+1);

if ( (ptstrRes->dblCoefi) == NULL )
	return (ERR_AMEM);	/* FIN */

/* MULTIPLICAMOS AMBOS POLINOMIOS */

for(i=0;i<=(ptstrPoli1->intGrado);i++)

	{	/* INICIO PRIMER for */

	for(j=0;j<=(ptstrPoli2->intGrado);j++)

		{	/* INICIO SEGUNDO for */

		(ptstrRes->dblCoefi[i+j]) += (ptstrPoli1->dblCoefi[i]) * 
					     (ptstrPoli2->dblCoefi[j]);

		}	/* FINAL SEGUNDO for */

	}	/* FINAL PRIMER for */

return (TRUE);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula por el metodo de Newton una raiz de un           */
/* polinomio.                                                           */
/*                                                                      */
/* La funcion devuelve:                                                 */
/*                                                                      */
/*         FALSE    No se calculo la raiz del polinomio en las          */
/*                  condiciones dadas(NMI y Tolerancia).                */
/*         DIV_CERO Division por Cero.                                  */
/*         TRUE     Se calculo la raiz del polinomio en las             */
/* 				    condiciones dadas. 							  		*/
/*         ERR_AMEM Hubo un error en la asignacion de memoria, para     */
/*             		almacenar la derivada del polinomio.                */
/*																		*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez						*/
/*																		*/
/*	BIbliotecA de proGRamacion cientificA.								*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int NewtonPoli(Polinomio *ptstrPoli, DatosAprxFunc *ptstrDatos)

{
int		i,
		intGradoAbs = abs(ptstrPoli->intGrado),
		intNMIAbs   = abs(ptstrDatos->intNMI);

double 	dblAprxNew   = .0,
	dblAprxOld   = (ptstrDatos->dblx0),
	dblValorPoli = .0,
	dblValorDeri = .0,
	dblTolAbs    = fabs(ptstrDatos->dblTol);

Polinomio	Derivada;

/* INICIALIZAMOS LOS DATOS DE Derivada */

Derivada.intGrado = intGradoAbs;
Derivada.dblCoefi = 0;

/* CALCULAMOS LA DERIVADA DEL POLINOMIO */

i = DerivadaPolinomio(ptstrPoli, &Derivada, 1);

if ( i != TRUE ) /* HUBO UN ERROR EN LA ASIGNACION DE MEMORIA */

	{
	return (ERR_AMEM);	/* FIN */
	}

for(i=1;i<=intNMIAbs;i++)

	{	/* INICIO for */

	dblValorPoli = dblEvaluarPolinomio(ptstrPoli, dblAprxOld);
	dblValorDeri = dblEvaluarPolinomio(&Derivada, dblAprxOld);

	if ( dblValorDeri == .0 )	/* DIVISION POR CERO */
		{
		free(Derivada.dblCoefi);

		return (DIV_CERO);	/* FIN */ 
		}

	/* NUEVA APROXIMACION */

	dblAprxNew = dblAprxOld - (dblValorPoli/dblValorDeri);

	/* CALCULO DEL ERROR */

	ptstrDatos->dblError = fabs(dblAprxOld-dblAprxNew);

	if ( (ptstrDatos->dblError) < dblTolAbs )
		{
		free(Derivada.dblCoefi);

		ptstrDatos->dblSolucion = dblAprxNew;

		return (TRUE);	/* FIN */
		}

	dblAprxOld = dblAprxNew;
					
	}	/* FINAL for */
	 	
return (FALSE); 	/* FIN */
}
