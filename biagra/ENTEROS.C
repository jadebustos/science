#include <math.h>

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
/* enteros.c    Jose Angel de Bustos Perez                              */
/*                                                                      */
/* Funciones para el tratamiento de matrices.                           */
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
/* Funcion que calcula y devuelve la suma de los intNumero primeros     */
/* enteros.                                                             */
/*                                                                      */
/* La funcion devuelve los siguientes codigos:                          */
/*                                                                      */
/*      0 Si el resultado de la suma excede el rango de un dato del     */
/*        tipo int.                                                     */
/*                                                                      */
/*      Un numero distinto de cero que sera la suma buscada.            */
/*                                                                      */ 
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

unsigned SumaNumerosN(int intNumero)

{
double 	dblMitad = .0,
	dblSuma  = .0;

int     intNum = abs(intNumero);

unsigned intSuma = 0;

if ( (intNum % 2) == 0 ) /* intNumero ES PAR */

	{
	dblMitad = ((double)intNum)/2.;

	dblSuma = dblMitad*(1.+(double)intNum);
	}

else /* intNumero ES IMPAR */

	{
	dblMitad = (((double)intNum)-1.)/2.;

	dblSuma = (dblMitad)*(2.+((double)intNum))+1.;
	}

intSuma = (unsigned)dblSuma;	/* CONVERTIMOS LA SUMA A int */

if ( dblSuma > intSuma ) /* EL RESULTADO EXCEDE EL RANGO DEL unsigned */
	intSuma = 0;
		
return (intSuma);
}
