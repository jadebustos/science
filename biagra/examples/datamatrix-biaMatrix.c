#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <biagra/datamatrix.h>
#include <biagra/const.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/* Simple example of biaMatrix usage */

int main (void) {

  /* Matrix data */
  int  rows = 8,
       cols = 8;

  /* Matrix declaration */
  biaMatrix myMatrix;

  /* Matrix data */
  myMatrix.intCols = cols;
  myMatrix.intRows = rows;

  /* Memory reservation por Matrix coefs */
  myMatrix.dblCoefs = (double **)calloc(myMatrix.intRows, sizeof(double *));

  if ( myMatrix.dblCoefs == NULL ) {
    printf("Error in memory assignation.\n");
    return 1;
  }

  for(int i=0;i<=myMatrix.intRows;i++) {
    myMatrix.dblCoefs[i] = (double *)calloc(myMatrix.intCols, sizeof(double));
    if ( myMatrix.dblCoefs[i] == NULL ) {
      printf("Error in memory assignation.\n");
      return 1;
    }
  }

  /* Random coefs between 0 and 100 (not cryptographically secure) */
  srand(time(NULL));
  for(int i=0;i<myMatrix.intRows;i++)
    for(int j=0;j<myMatrix.intCols;j++)
      myMatrix.dblCoefs[i][j] = (double) (rand() % 100);

  printf("Random matrix:\n\n");

  /* Print Matrix to stdout */
  for(int i=0;i<myMatrix.intRows;i++) {
    for(int j=0;j<myMatrix.intCols;j++) {
      printf("%g ", myMatrix.dblCoefs[i][j]);
    }
    printf("\n");
  }

  return BIA_TRUE;
}
