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
/* polinomios.h     Jose Angel de Bustos Perez                          */
/*                                                                      */
/* Prototipos de funciones para el tratamiento de polinomios.           */
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

double dblEvaluarPolinomio(Polinomio *ptstrPoli, double dblPunto);

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
