#ifndef _MATRIX_H
  #define _MATRIX_H

/*                                                                      */
/* Funcion que almacena la matriz identidad.                            */
/*                                                                      */
/* El orden de la matriz viene dado por el miembro intFilas de la       */
/* variable a la que apunta ptstrMatriz.				*/
/*                                                                      */

void MatrizIdentidad(Matriz *ptstrMatriz);

/*                                                                      */
/* Funcion que almacena la matriz de la homotecia de razon dblRazon.    */
/*                                                                      */
/* El orden de la matriz viene dado por el miembro intFilas de la       */
/* variable a la que apunta ptstrMatriz.				*/
/*                                                                      */

void MatrizHomotecia(Matriz *ptstrMatriz, double dblRazon);

/*                                                                      */
/* Funcion que almacena la matriz nula en dblMatriz.                    */
/*                                                                      */
/* Las filas y columnas de la matriz vienen dadas por los miembros	*/
/* intFilas e intColumnas de la variable a la que apunta ptstrMatriz.   */
/*                                                                      */

void MatrizNula(Matriz *ptstrMatriz);

/*                                                                      */
/* Funcion que almacena la matriz traspuesta de ptstrMatriz en          */
/* ptstrTras.   							*/
/*                                                                      */
/* Las filas y columnas de la matriz vienen dadas por los miembros	*/
/* intFilas e intColumnas de la variable a la que apunta ptstrMatriz.   */
/*                                                                      */

void MatrizTraspuesta(Matriz *ptstrMatriz, Matriz *ptstrTras);
#endif
