#include <math.h>
#include <limits.h>

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
/* primos.c     Jose Angel de Bustos Perez                              */
/*                                                                      */
/* Funciones relacionadas con los numeros primos.                       */
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
/* Funcion que calcula si un numero es primo o no.                      */
/*                                                                      */
/* La funcion devuelve los siguientes codigos:                          */
/*                                                                      */
/*	TRUE  -> Si el argumento es un numero primo.			*/
/*	FALSE -> En caso contrario.					*/
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int Primo(int intNumero)

{
int     i,           /* CONTADOR */
        intResultado = TRUE,
        intAbsNumero = abs(intNumero),
        intResto;

for(i=2;i<intAbsNumero;i++)

        {       /* INICIO for */

        intResto = intAbsNumero % i;

        if ( intResto == 0 )      /* NO ES UN NUMERO PRIMO */

		{	/* INICIO if */
		
		intResultado = FALSE;

		break;
		}	/* FINAL if */

	}	/* FINAL for */

return (intResultado);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula los intNumero primeros numeros primos y los      */
/* almacena en ptunsPrimos.                                             */
/*                                                                      */
/* La funcion almacena en ptintCalc la cantidad de numeros primos       */
/* que han sido calculados.                                             */
/*                                                                      */
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void PrimerosPrimos(unsigned int *ptunsPrimos, int intNumero, int *ptintCalc)

{
unsigned int	i,
		unsResto;

int	intCalculados = 0,
	intNumAbs = abs(intNumero),
	j;

if ( intNumAbs != 0 )
	ptunsPrimos[intCalculados++] = 2;

for(i=3;(i<UINT_MAX-1) && (intCalculados<intNumAbs);i+=2)

	{	/* INICIO PRIMER for */

	for(j=1;j<intCalculados;j++)

		{	/* INICIO SEGUNDO for */

		unsResto = i % ptunsPrimos[j];

		if ( unsResto == 0 )
			break;

		}	/* FINAL SEGUNDO for */
	
	if ( unsResto != 0 )
		ptunsPrimos[intCalculados++] = i;

	}	/* FINAL PRIMER for */

*ptintCalc = intCalculados; /* CANTIDAD CALCULADA */

return;
}
