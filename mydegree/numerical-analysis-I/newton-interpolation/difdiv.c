
/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */                                                                            
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* Funcion recursiva que calcula diferencias divididas.                 */
/*                                                                      */
/* Dados n+1 puntos x_0,...x_n los cuales estan almacenados en:         */
/*	dblPuntos[i] = x_i                                              */
/*                                                                      */
/* f(x_i) = dblValor[i]                                                 */
/*                                                                      */
/* Esta funcion devuelve f[x_intInf,...,x_intSup]                       */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

double dblDifDiv(double *dblPuntos, double *dblValor, 
		int intInf, int intSup)

{
if ( intInf != intSup )
	return((dblDifDiv(dblPuntos, dblValor, intInf, intSup-1)-
	        dblDifDiv(dblPuntos, dblValor, intInf+1, intSup))/
		(dblPuntos[intInf]-dblPuntos[intSup]));

else
	return(dblValor[intInf]);
} 
