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
		double (*dblFuncion)(double dblX));

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* Funcion que calcula el error cometido por la regla del trapecio al   */
/* integrar en las condiciones de ptstrDatos. Donde dblDer2 es una      */
/* funcion que devuelve el valor de la segunda derivada de la funcion   */
/* que estamos integrando en el punto dblX.                             */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void ErrorTrapecio(DatosIntgr *ptstrDatos, double (*dblDer2)(double dblX));
