#ifndef _RNGKUTTA_H
  #define _RNGKUTTA_H

  #define BIA_IMPLICIT_RK_TRUE  0
  #define BIA_IMPLICIT_RK_FALSE 1

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
/* This data structure is used in Runge-Kutta methods (ODE)             */
/*                                                                      */
/* Butcher matricial notation is used in this implimentation.           */
/*                                                                      */
/* Para ello supondremos que el metodo R-K tiene la formulacion:        */
/*                                                                      */
/* Y_(n) aproximacion del valor de la funcion Y en el punto x_n.        */
/* h paso constante.                                                    */
/* s numero de etapas del metodo                                        */
/*                                                                      */
/* El metodo sera el siguiente:                                         */
/*                                                                      */
/* Y_(n+1) = Y_(n) +h*(SUM[(b_i * k_i),{i=,1,s}])                       */
/*                                                                      */
/* k_i = f(x_n + (h*c_i),Y_(n) + h*(SUM[(a_ij * k_j),{j=,1,s}]) )       */
/*                                                                      */
/* SUM[a_ij,{j=,1,s}] = c_i                                             */
/*                                                                      */
/* Donde f(x,Y(x)) = Y' sera el P.V.I a resolver, junto con su          */
/* inicializacion correspondiente.                                      */
/*                                                                      */
/* Los miembros de la estructura son:                                   */
/*                                                                      */
/* intStages -> Method stages                                           */
/*                                                                      */
/* *dblC -> vector storing c_i coefficients                             */
/*          dblC[i] = c_(i+1)  0 <= i <= s-1                            */
/*                                                                      */
/* *dblB -> vector storing  b_i coeffcients                             */
/*          dblB[i] = b_(i+1)  0 <= i <= s-2                            */
/*                                                                      */
/* **dblMatrix -> matrix storing a_ij coefficients                      */
/*                dblMatrix[i][j] = a_(i+1)(j+1)  0 <= i,j <= s         */
/*                                                                      */


  typedef struct {
    double  *dblC,
            *dblB,
            **dblMatrix;

    int     intStages;
    } ButcherArray;

/*                                                                      */
/* Data structure used to store all data to use Runge-Kutta methods     */
/*                                                                      */
/* strCoefs ButcherArray data structure to store method coeficients     */
/*                                                                      */
/* intNumApprox number of approximations to be performed. This is the   */
/*              dimension of dblPoints vector                           */
/*                                                                      */
/* intImplicit if Runge-Kutta is implicit then 0 in other case 1        */
/*                                                                      */
/* dblStepSize method's step-size                                       */
/*                                                                      */
/* dblFirst first point used to get other approximations                */
/*                                                                      */
/* dblLast last point to get function approximation                     */
/*                                                                      */
/* dblPoints vector to store function values in x_i                     */
/*                                                                      */
/* dblPoints[i] = Y_i                                                   */
/* dblPoints[0] = Y(dblFirst)                                           */
/*                                                                      */

  typedef struct {
    int intNumApprox,
        intImplicit;

    double  *dblPoints,
             dblStepSize,
             dblFirst,
             dblLast;

    ButcherArray strCoefs;
  } DataRK;

/*                                                                      */
/*  Function to solve a I.V.P (Cauchy problem) using explicit           */
/*  Runge-Kutta methods.                                                */
/*                                                                      */
/* Arguments:                                                           */
/*    *ptstrDatos -> Pointer to a DataRK data structure                 */
/*    (*IVP)      -> Pointer to a function implementing de differential */
/*                   equation in (dblX, dblY)                           */
/*                                                                      */
/*  The following values are returned:   				*/
/*                                                                      */
/*	BIA_MEM_ALLOC -> Memory allocation error                 	*/
/*	BIA_TRUE      -> Success                                   	*/
/*                                                                      */

  int ExplicitRungeKutta(DataRK *ptstrDatos, double (*IVP)(double dblX, double dblY));

/*                                                                      */
/* Function to get the number of nodes in a dblLong size interval where */
/* dblStepSize is the distance between two consecutive nodes.           */
/*                                                                      */

  int intNodeNumber(double dblLong, double dblStepSize);

#endif
