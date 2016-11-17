#ifndef _COMPLEX_H
  #define _COMPLEX_H

#include <biagra/datacomplex.h>
#include <biagra/const.h>                                                                                                                             

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
/* Function to add two complex numbers                                  */
/*                                                                      */

  void addComplex(biaComplex *ptCmplx1, biaComplex *ptCmplx2, biaComplex *ptRes);

/*                                                                      */
/* Function to subtract two complex numbers                             */
/*                                                                      */

  void subtractComplex(biaComplex *ptCmplx1, biaComplex *ptCmplx2, biaComplex *ptRes);


/*                                                                      */
/* Function to multiply two complex numbers                             */
/*                                                                      */

  void multiplyComplex(biaComplex *ptCmplx1, biaComplex *ptCmplx2, biaComplex *ptRes);

/*                                                                      */
/* Function to complex division                                         */
/*                                                                      */
/*        ptCmplx1 * (ptCmplx2)^(-1)                                    */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_ZERO_DIV -> Division by zero                                */
/*      BIA_TRUE     -> Success                                         */
/*                                                                      */

  int divideComplex(biaComplex *ptCmplx1, biaComplex *ptCmplx2, biaComplex *ptRes);


/*                                                                      */
/* Function to get a complex number module                              */
/*                                                                      */

  double dblComplexModule(biaComplex *ptCmplx);

/*                                                                      */
/* Function to get a complex number argument                            */
/*                                                                      */

  double dblComplexArg(biaComplex *ptCmplx);

/*                                                                      */
/* Function to get the inverse (addition) of a complex number           */
/*                                                                      */

  void invSumComplex(biaComplex *ptCmplx, biaComplex *ptRes);

/*                                                                      */
/* Function to get the inverse (multiplication) of a complex number     */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_ZERO_DIV -> Division by zero                                */
/*      BIA_TRUE     -> Success                                         */
/*                                                                      */

  int invMulComplex(biaComplex *ptCmplx, biaComplex *ptRes);

/*                                                                      */
/* Function to get the complex conjugate of a complex number            */
/*                                                                      */

  void conjugateComplex(biaComplex *ptCmplx, biaComplex *ptRes);

/*                                                                      */
/* Function to get the polar coordinates of a complex number            */
/*                                                                      */

  void complex2Polar(biaComplex *ptCmplx, biaPolar *ptRes);

/*                                                                      */
/* Function to get the cartesian coordinates of a complex number        */
/* in polar coordinates                                                 */
/*                                                                      */

  void polar2Complex(biaPolar *ptPolar, biaComplex *ptRes);

#endif
