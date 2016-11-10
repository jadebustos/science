#ifndef DATAPOL_H
  #define DATAPOL_H

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
    int   intDegree,
          intRealRoots,
          intCompRoots;

    double *dblCoefs;        
    } biaRealPol;

/*                                                                      */
/* Data structure to store function roots                               */
/*                                                                      */
/* intNMI   -> maximum number of iterations to get the root with        */
/*             dblTol error.                                            */
/* intIte   -> iterations used to get the root.                         */
/* dblx0    -> initial root approximation.                              */
/* dblRoot  -> function root approximation                              */
/* dblTol   -> Maximun error tolerance.                                 */
/* dblError -> error in root. Difference between two last root          */
/*             approximations.                                          */
/*                                                                      */
        
  typedef struct {
    
    int intNMI,
        intIte;

    double dblx0,
	   dblRoot,
	   dblTol,
	   dblError;
    } biaRealRoot;

#endif
