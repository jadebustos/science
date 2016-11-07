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
/* polynomial.h                                                         */
/*                                                                      */
/* Functions to work using polynomials.                                 */
/*                                                                      */
/* p(x) = a0 + a1*x^1 + a2*x^2 + .... + an*x^n                          */
/*                                                                      */
/* #include <stdlib.h>                                                  */
/* double *mypol = (double *)calloc(n + 1, size(double))                */
/*                                                                      */
/* *(mypol) = mypol[0] = a0                                             */
/* *(mypol + i) = mypol[i] = ai where i in [1,n]                        */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Function to evaluate a polynomial in one value.                      */
/*                                                                      */
/* Arguments:                                                           */
/*    *ptstrPol                                                        */
/*    dblX                                                              */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

double dblEvaluatePol(biaPol *ptstrPol, double dblX);

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula la derivada N-esima de un ptstrPolinomio y la    */
/* almacena en ptstrDerivada.                                           */
/*                                                                      */ 
/* La funcion devuelve los siguientes codigos:                          */
/*                                                                      */
/*      ERR_AMEM -> Hubo un error en la asignacion de memoria.          */
/*      TRUE     -> Se calculo con exito la derivada.                   */
/*                                                                      */
/*      B.I.A.G.R.A.        Jose Angel de Bustos Perez                  */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int DerivadaPolinomio(Polinomio *ptstrPoli, Polinomio *ptstrDerivada, int intN);

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que suma el polinomio ptstrPoli1 con el polinomio            */
/* ptstrPoli2 y lo almacena en ptstrRes. 				*/
/*                                                                      */
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*	ERR_AMEM -> Hubo un error en la asignacion de memoria.		*/
/*	TRUE     -> Se multiplico con exito los dos polinomios.		*/
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int SumarPolinomios(Polinomio *ptstrPoli1, Polinomio *ptstrPoli2, 
		Polinomio *ptstrRes);
                
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que resta el polinomio ptstrPoli1 con el polinomio           */
/* ptstrPoli2 y lo almacena en ptstrRes. 				*/
/*                                                                      */
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*	ERR_AMEM -> Hubo un error en la asignacion de memoria.		*/
/*	TRUE     -> Se multiplico con exito los dos polinomios.		*/
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int RestarPolinomios(Polinomio *ptstrPoli1, Polinomio *ptstrPoli2, 
		Polinomio *ptstrRes);                
                
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que multiplica el polinomio ptstrPoli1 por el polinomio      */
/* ptstrPoli2 y lo almacena en ptstrRes. 				*/
/*                                                                      */
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*	ERR_AMEM -> Hubo un error en la asignacion de memoria.		*/
/*	TRUE     -> Se multiplico con exito los dos polinomios.		*/
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/ 
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int MultiplicarPolinomios(Polinomio *ptstrPoli1, Polinomio *ptstrPoli2, 
		Polinomio *ptstrRes);

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
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int NewtonPoli(Polinomio *ptstrPoli, DatosAprxFunc *ptstrDatos);
