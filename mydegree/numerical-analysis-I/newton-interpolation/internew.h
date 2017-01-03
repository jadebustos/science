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
 
int intPolNewton(double *dblPuntos, double *dblValor, int intN, 
		double *dblDD, double *dblPolinomio);
