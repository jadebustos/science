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
/*                                                                      */
/* intStages -> Method stages                                           */
/* *dblC -> vector storing c_i coefficients                             */
/*          dblC[i] = c_(i+1)  0 <= i <= s-1                            */
/* *dblB -> vector storing  b_i coeffcients                             */
/*          dblB[i] = b_(i+1)  0 <= i <= s-2                            */
/* **dblMatrix -> matrix storing a_ij coefficients                      */
/*                dblMatrix[i][j] = a_(i+1)(j+1)  0 <= i,j <= s         */
/*                                                                      */

  typedef struct {
    double  *dblC,
            *dblB,
            **dblMatrix;

    int     intStages;
  } biaButcherArray;

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
/* dblStepSize -> method's step-size                                    */
/* dblFirst    -> first point used to get other approximations          */
/* dblLast     -> last point to get function approximation              */
/* dblPoints   -> vector to store function values in x_i                */
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

    biaButcherArray strCoefs;
  } biaDataRK;

/*                                                                      */
/*  Function to solve a I.V.P (Cauchy problem) using explicit           */
/*  Runge-Kutta methods.                                                */
/*                                                                      */
/* Arguments:                                                           */
/*    *ptDats -> Pointer to a DataRK data structure                     */
/*    (*IVP)  -> Pointer to a function implementing de differential     */
/*               equation in (dblX, dblY)                               */
/*                                                                      */
/*  The following values are returned:   				*/
/*                                                                      */
/*	BIA_MEM_ALLOC -> Memory allocation error                 	*/
/*	BIA_TRUE      -> Success                                   	*/
/*                                                                      */

  int ExplicitRungeKutta(biaDataRK *ptstrDatos, double (*IVP)(double dblX, double dblY));

/*                                                                      */
/* Function to get the number of nodes in a dblLong size interval where */
/* dblStepSize is the distance between two consecutive nodes.           */
/*                                                                      */

  int intNodeNumber(double dblLong, double dblStepSize);

#endif
