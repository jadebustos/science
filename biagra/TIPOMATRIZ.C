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
/* tipomatriz.c     Jose Angel de Bustos Perez                          */
/*                                                                      */
/* Funciones para clasificar matrices.                                  */
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
/* Funcion que comprueba si una matriz es simetrica o no.               */
/*                                                                      */
/* La funcion devuelve los siguientes valores:                          */
/*                                                                      */
/* 	FALSE -> Si la matriz no es simetrica.                          */
/*      TRUE  ->   Si la matriz es simetrica.                           */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int EsMatrizSimetrica(Matriz *ptstrMatriz)

{
int	i,
	j,
	intRes = TRUE;

for(i=0;i<(ptstrMatriz->intFilas)-1;i++)

	{	/* INICIO PRIMER for */

	for(j=i+1;j<(ptstrMatriz->intFilas);j++)

		{	/* INICIO SEGUNDO for */

		if ( (ptstrMatriz->dblCoefi[i][j]) != (ptstrMatriz->dblCoefi[j][i]) )
			
			{	/* INICIO if */

			intRes = FALSE;
			break;

			}	/* FINAL if */

		}	/* FINAL SEGUNDO for */

	if ( intRes == FALSE )
		break;

	}	/* FINAL PRIMER for */

return (intRes);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que comprueba si una matriz es la matriz identidad.          */
/*                                                                      */
/* La funcion devuelve los siguientes valores:                          */
/*                                                                      */
/*	FALSE -> Si la matriz no es la identidad.                       */
/*	TRUE  -> Si la matriz es la matriz identidad.                   */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int EsMatrizIdentidad(Matriz *ptstrMatriz)

{
int	i,
	j,
	intRes = TRUE;

for(i=0;i<(ptstrMatriz->intFilas);i++)

	{	/* INICIO PRIMER for */

	for(j=0;j<(ptstrMatriz->intFilas);j++)

		{	/* INICIO SEGUNDO for */

		if ( i != j )

			{	/* INICIO PRIMER if */

			if ( (ptstrMatriz->dblCoefi[i][j]) != .0 )	/* NO ES LA IDENTIDAD */

				{	/* INICIO SEGUNDO if */
				
				intRes = FALSE;
				break;

				}	/* FINAL SEGUNDO if */

			}	/* FINAL PRIMER if */

		else

			{	/* INICIO else */

			if ( (ptstrMatriz->dblCoefi[i][i]) != 1. )	/* NO ES LA IDENTIDAD */

				{	/* INICIO PRIMER if */

				intRes = FALSE;
				break;

				}	/* FINAL PRIMER if */

			}	/* FINAL else */

		}	/* FINAL SEGUNDO for */

	if ( intRes == FALSE )	/* NO ES LA IDENTIDAD */
		break;

	}	/* FINAL PRIMER for */

return (intRes); 
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que comprueba si una matriz es la matriz nula, donde dblTol  */
/* es la tolerancia con la que los coeficientes de la matriz se pueden  */
/* aproximar a cero.                                                    */
/*                                                                      */
/* La funcion devuelve los siguientes valores:                          */
/*                                                                      */
/*	FALSE -> Si la matriz no es la matriz nula.                     */
/*	TRUE  -> Si la matriz es la matriz nula.                        */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int EsMatrizNula(Matriz *ptstrMatriz, double dblTol)

{
int	i,	/* CONTADOR */
	j,	/* CONTADOR */
	intRes = TRUE;

double	dblTolPos = fabs(dblTol);

for(i=0;i<(ptstrMatriz->intFilas);i++)

	{	/* INICIO PRIMER for */

	for(j=0;j<(ptstrMatriz->intColumnas);j++)

		{	/* INICIO SEGUNDO for */
	
		if ( fabs((ptstrMatriz->dblCoefi[i][j])) > dblTolPos )
			
			{	/* NO ES LA MATRIZ NULA */
			intRes = FALSE;
			return (intRes);
			}

		}	/* FINAL SEGUNDO for */

	}	/* FINAL PRIMER for */

return (intRes);
}

