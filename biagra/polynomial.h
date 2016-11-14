#ifndef _POLYNOMIAL_H
  #define _POLYNOMIAL_H

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                           <jadebustos@gmail.com>                     */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/*                                                                      */
/* Function to evaluate a polynomial in one value.                      */
/*                                                                      */
/* Arguments:                                                           */
/*    *ptstrPol -> Polynomial                                           */
/*    dblX -> Value to evaluate                                         */
/*                                                                      */
/* Returned value:                                                      */
/*    Polynomial value at dblX                                          */

  double dblEvaluatePol(biaPol *ptPol, double dblX);

/*                                                                      */
/* Funcion que calcula la derivada N-esima de un ptstrPolinomio y la    */
/* almacena en ptstrDerivada.                                           */
/*                                                                      */ 
/* La funcion devuelve los siguientes codigos:                          */
/*                                                                      */
/*      ERR_AMEM -> Hubo un error en la asignacion de memoria.          */
/*      TRUE     -> Se calculo con exito la derivada.                   */
/*                                                                      */

  int derivatePol(biaPol *ptPoli, biaPol *ptDerivada, int intN);

/*                                                                      */
/* Funcion que suma el polinomio ptstrPoli1 con el polinomio            */
/* ptstrPoli2 y lo almacena en ptstrRes. 				*/
/*                                                                      */
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*	ERR_AMEM -> Hubo un error en la asignacion de memoria.		*/
/*	TRUE     -> Se multiplico con exito los dos polinomios.		*/
/*									*/

int SumarPolinomios(Polinomio *ptstrPoli1, Polinomio *ptstrPoli2, 
		Polinomio *ptstrRes);
                
/*                                                                      */
/* Funcion que resta el polinomio ptstrPoli1 con el polinomio           */
/* ptstrPoli2 y lo almacena en ptstrRes. 				*/
/*                                                                      */
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*	ERR_AMEM -> Hubo un error en la asignacion de memoria.		*/
/*	TRUE     -> Se multiplico con exito los dos polinomios.		*/
/*									*/

int RestarPolinomios(Polinomio *ptstrPoli1, Polinomio *ptstrPoli2, 
		Polinomio *ptstrRes);                
                
/*                                                                      */
/* Funcion que multiplica el polinomio ptstrPoli1 por el polinomio      */
/* ptstrPoli2 y lo almacena en ptstrRes. 				*/
/*                                                                      */
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*	ERR_AMEM -> Hubo un error en la asignacion de memoria.		*/
/*	TRUE     -> Se multiplico con exito los dos polinomios.		*/
/*									*/

int MultiplicarPolinomios(Polinomio *ptstrPoli1, Polinomio *ptstrPoli2, 
		Polinomio *ptstrRes);

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

int NewtonPoli(Polinomio *ptstrPoli, DatosAprxFunc *ptstrDatos);

#endif
