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
		double (*dblFuncion)(double dblX));

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* Funcion que calcula el error cometido por la regla de los 3/8 al     */
/* integrar en las condiciones de ptstrDatos. Donde dblDer4 es una      */
/* funcion que devuelve el valor de la cuarta derivada de la funcion    */
/* que estamos integrando en el punto dblX.                             */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void ErrorTresOct(DatosIntgr *ptstrDatos, double (*dblDer4)(double dblX));
