#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <biagra/resmem.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/* Simple example of dblPtMemAllocUpperTrMat usage */

int main (void) {

  /* Data */
  int intOrder = 5;

  /* Matrix declaration */
  double **dblMatrix;

  /* Memory reservation por vector */
  dblMatrix = dblPtMemAllocUpperTrMat(intOrder);

  if ( dblMatrix == NULL ) {
    printf("Error in memory assignation.\n");
    return 1;
  }

  /* Random coefs between 0 and 100 (not cryptographically secure) */
  srand(time(NULL));
  for(int i=0;i<intOrder;i++) {
    for(int j=0;j<intOrder - i;j++) {
      dblMatrix[i][j] = (double) (rand() % 100);
      }
    }

  printf("Upper triangular matrix:\n\n");
  
  /* Print Matrix to stdout */
  for(int i=0;i<intOrder;i++) {
    for(int j=0;j<intOrder;j++) {
	if ( i > j)
	    printf("0 ");
	else
	    printf("%g ", dblMatrix[i][j-i]);
      }
    printf("\n");
    }

  return 0;
}
