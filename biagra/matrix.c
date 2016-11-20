#include <biagra/datamatrix.h>

/*                                                                      */
/* Function to store identity matrix.                                   */
/*                                                                      */
/* Matrix order it taken from intRows member of biaMatrix var           */
/*                                                                      */

void identityMatrix(biaMatrix *ptMatrix) {

  int i,
      j;

  for(i=0;i<(ptMatrix->intRows);i++) {
    for(j=0;j<(ptMatrix->intRows);j++) {
      if ( i == j ) {
        (ptMatrix->dblCoefs[i][i]) = 1.;
      }
      else {
        (ptMatrix->dblCoefs[i][j]) = .0;
      }
    }
  }
  return;
}

/*                                                                      */
/* Function to store scaling matrix with factor dblFactor.              */
/*                                                                      */
/* Matrix order it taken from intRows member of biaMatrix var           */
/*                                                                      */

void scalingMatrix(biaMatrix *ptMatrix, double dblFactor) {

  int i,
      j;

  for(i=0;i<(ptMatrix->intRows);i++) {
    for(j=0;j<(ptMatrix->intRows);j++) {
      if ( i == j )
        (ptMatrix->dblCoefs[i][i]) = dblFactor;
      else
        (ptMatrix->dblCoefs[i][j]) = .0;
    }
  }

  return;
}

/*                                                                      */                                                                            
/* Function to store the null matrix.                                   */
/*                                                                      */
/* Rows and columns are takem from intRows and intCols members of       */
/* biaMatrix var.                                                       */
/*                                                                      */

void nullMatrix(biaMatrix *ptMatrix) {

  int i,
      j;

  for(i=0;i<(ptMatrix->intRows);i++) {
    for(j=0;j<(ptMatrix->intCols);j++) {
      (ptMatrix->dblCoefs[i][j]) = .0;
    }
  }
  return;
}

/*                                                                      */
/* Function to get the transpose matrix of the given matrix.            */
/*                                                                      */
/* Rows and columns are takem from intRows and intCols members of       */
/* biaMatrix var.                                                       */
/*                                                                      */

void transposeMatrix(biaMatrix *ptMatrix, biaMatrix  *ptRes) {

  int i,
      j;

  for(i=0;i<(ptMatrix->intCols);i++) {
    for(j=0;j<(ptMatrix->intRows);j++) {
      (ptRes->dblCoefs[i][j]) = (ptMatrix->dblCoefs[j][i]);
    }
  }

return;
}

