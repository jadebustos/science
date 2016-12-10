#ifndef _RNGKUTTA_H
  #define _RNGKUTTA_H

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
/*  Funcion que resuelve un P.V.I. mediante un metodo de RUNGE - KUTTA  */
/*  explicito, *ptstrDatos es un puntero a un tipo de dato definido por */
/*  el usuario(prototip en struct.h), y (*PVI) es un puntero a una      */
/*  funcion que devuelve el valor de la ecuacion diferencial en dblX y  */
/*  dblY.                                                               */ 
/*                                                                      */
/*  La funcion devuelve los siguientes valores:				*/
/*                                                                      */
/*	ERR_AMEM -> Hubo algun error en la asignacion de memoria.	*/
/*	TRUE     -> Se calculo con exito la aproximacion.		*/
/*                                                                      */

int ExplicitRungeKutta(DatosRK *ptstrDatos, double (*PVI)(double dblX, double dblY));

/*                                                                      */
/* Funcion que devuelve el numero de nodos que hay en un intervalo de   */
/* longitud dblLong e igualmente espaciados por dblPaso.                */
/*									*/
/*                                                                      */

int intNumNodos(double dblLong, double dblPaso);
#endif
