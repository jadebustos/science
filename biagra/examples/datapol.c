#include <stdio.h>
#include <stdlib.h>

#include "datapol.h"

/*|     |       |       |       |       |       |       |       |       */
/*|     B.I.A.G.R.A.|   (c) 1998 Jose Angel de Bustos Perez|    |       */
/*|     |       |        <jadebustos@gmail.com>         |       |       */
/*|     |       |       |       |       |       |       |       |       */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*|     |       |       |       |       |       |       |       |       */
/*|     BIbliotecA de proGRamacion cientificA.| |       |       |       */
/*|     |       |       |       |       |       |       |       |       */

/* Simple example of biaRealPol usage */

int main (void) {

  /* Polynomial degree */
  int polDegree = 3;

  /* Polynomial declaration */
  biaRealPol myPol;

  /* Polynomial degree */
  myPol.intDegree = polDegree;

  /* Memory reservation por polynomial coefs */
  myPol.dblCoefs = (double *)calloc(myPol.intDegree + 1, sizeof(double));

  if ( myPol.dblCoefs == NULL ) {
    printf("Error in memory assignation.\n");
    return 1;
  }

  /* p(x) = 3 + 2*x - 3*x^2 + x^3 */
  myPol.dblCoefs[0] = 3.;
  myPol.dblCoefs[1] = 2.;
  myPol.dblCoefs[2] = -3.;
  myPol.dblCoefs[3] = 1.;

  /* Printing polynomial to stdout */
  printf("p(x) = %g", myPol.dblCoefs[0]);
  
  for(int i=1;i<=myPol.intDegree;i++)
    printf(" + (%g) * x ^%d", myPol.dblCoefs[i], i);

  return 0;
}
