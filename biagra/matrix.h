#ifndef _MATRIX_H
  #define _MATRIX_H

#include <biagra.h/datamatrix.h>

/*                                                                      */
/* Function to store identity matrix.                                   */
/*                                                                      */
/* Matrix order it taken from intRows member of biaMatrix var           */
/*                                                                      */

  void identityMatrix(biaMatrix *ptMatrix);

/*                                                                      */
/* Function to store scaling matrix with factor dblFactor.              */
/*                                                                      */
/* Matrix order it taken from intRows member of biaMatrix var           */
/*                                                                      */

  void scalingMatrix(biaMatrix *ptMatrix, double dblFactor);

/*                                                                      */
/* Function to store the null matrix.                                   */
/*                                                                      */
/* Rows and columns are takem from intRows and intCols members of       */
/* biaMatrix var.                                                       */
/*                                                                      */

  void nullMatrix(biaMatrix *ptMatrix);

/*                                                                      */
/* Function to get the transpose matrix of the given matrix.            */
/*                                                                      */
/* Rows and columns are takem from intRows and intCols members of       */
/* biaMatrix var.                                                       */
/*                                                                      */

  void transposeMatrix(biaMatrix *ptMatrix, biaMatrix  *ptRes);

 /*                                                                      */
 /* Function to check if a given matrix is the identity matrix           */
 /*                                                                      */
 /* The following values are returned:                                   */
 /*                                                                      */
 /*      BIA_FALSE -> Not identity matrix                                */
 /*      BIA_TRUE  -> Identity matrix                                    */
 /*                                                                      */

  int isIdentityMatrix(biaMatrix *ptMatrix);

#endif
