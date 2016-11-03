#ifndef BASICDATA_H
  #define BASICDATA_H

/*									*/
/*	B.I.A.G.R.A.	(c) 1998 Jose Angel de Bustos Perez		*/
/*			 <jadebustos@gmail.com>         		*/
/*									*/
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/

/*                                                                      */
/* Data structure to handle polynomials                                 */
/*                                                                      */
/* p(x) = a0 + a1*x^1 + a2*x^2 + .... + an*x^n                          */                                                                            
/*                                                                      */
/* intDegree    -> Polynomial degree                                    */
/* intRealRoots -> Number of real roots                                 */
/* intCompRoots -> Number of complex roots                              */
/* dblCoefs     -> Polynomial coefs                                     */
/*                   dblCoefs[i] = ai                                   */
/*                                                                      */

typedef struct {
  int   intDegree    = 0
        intRealRoots = 0,
        intCompRoots = 0;

  double *dblCoefs;        
  } biaRealPol;

#endif
