#ifndef DATACOMPLEX_H
  #define DATACOMPLEX_H

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */                                                                            
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/*                                                                      */
/* Data structure to store complex numbers                              */
/*                                                                      */
/* a + b * i                                                            */
/*                                                                      */
/* dblReal -> Real part                                                 */
/* dblImag -> Imaginary part                                            */ 
/*                                                                      */

  typedef struct {
    double dblReal,
           dblImag;
    } biaComplex;

/*                                                                      */
/* Data structure to store complex numbers as polar coordinates         */
/*                                                                      */
/* a + b * i = (r, theta)                                               */
/*                                                                      */
/* dblMod -> Modulus                                                    */
/* dblArg -> Argument                                                   */
/*                                                                      */

  typedef struct {
    double dblMod,
           dblArg;
    } biaPolar;
