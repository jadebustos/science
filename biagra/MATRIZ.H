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
/* matriz.c     Jose Angel de Bustos Perez                              */
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
/* Funcion que almacena la matriz identidad.                            */
/*                                                                      */
/* El orden de la matriz viene dado por el miembro intFilas de la       */
/* variable a la que apunta ptstrMatriz.				*/
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void MatrizIdentidad(Matriz *ptstrMatriz);

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que almacena la matriz de la homotecia de razon dblRazon.    */
/*                                                                      */
/* El orden de la matriz viene dado por el miembro intFilas de la       */
/* variable a la que apunta ptstrMatriz.				*/
/*                                                                      */
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void MatrizHomotecia(Matriz *ptstrMatriz, double dblRazon);

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que almacena la matriz nula en dblMatriz.                    */
/*                                                                      */
/* Las filas y columnas de la matriz vienen dadas por los miembros	*/
/* intFilas e intColumnas de la variable a la que apunta ptstrMatriz.   */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void MatrizNula(Matriz *ptstrMatriz);

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que almacena la matriz traspuesta de ptstrMatriz en          */
/* ptstrTras.   							*/
/*                                                                      */
/* Las filas y columnas de la matriz vienen dadas por los miembros	*/
/* intFilas e intColumnas de la variable a la que apunta ptstrMatriz.   */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void MatrizTraspuesta(Matriz *ptstrMatriz, Matriz *ptstrTras);
