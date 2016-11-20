#include <biagra/datamatrix.h>
#include <biagra/const.h>

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

/*                                                                      */
/* Function to check if a given matrix is the identity matrix           */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_FALSE -> Not identity matrix                                */
/*      BIA_TRUE  -> Identity matrix                                    */                                                                           
/*                                                                      */

int isIdentityMatrix(biaMatrix *ptMatrix) {

  int i,
      j,
      intRes = BIA_TRUE;

  for(i=0;i<(ptMatrix->intRows);i++) {
    for(j=0;j<(ptMatrix->intRows);j++) {
      if ( i != j ) {
        if ( (ptMatrix->dblCoefS[i][j]) != .0 ) {
          intRes = BIA_FALSE;
          break;
        }
      }
      else {
        if ( (ptMatrix->dblCoefs[i][i]) != 1. ) {
          intRes = BIA_FALSE;
          break;
        }
      }
    }
    if ( intRes == BIA_FALSE )
      break;
  }
  return intRes; 
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que comprueba si una matriz es la matriz nula, donde dblTol  */
/* es la tolerancia con la que los coeficientes de la matriz se pueden  */
/* aproximar a cero.                                                    */
/*                                                                      */
/* La funcion devuelve los siguientes valores:                          */
/*                                                                      */
/*	FALSE -> Si la matriz no es la matriz nula.                     */
/*	TRUE  -> Si la matriz es la matriz nula.                        */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int EsMatrizNula(Matriz *ptstrMatriz, double dblTol)

{
int	i,	/* CONTADOR */
	j,	/* CONTADOR */
	intRes = TRUE;

double	dblTolPos = fabs(dblTol);

for(i=0;i<(ptstrMatriz->intFilas);i++)

	{	/* INICIO PRIMER for */

	for(j=0;j<(ptstrMatriz->intColumnas);j++)

		{	/* INICIO SEGUNDO for */
	
		if ( fabs((ptstrMatriz->dblCoefi[i][j])) > dblTolPos )
			
			{	/* NO ES LA MATRIZ NULA */
			intRes = FALSE;
			return (intRes);
			}

		}	/* FINAL SEGUNDO for */

	}	/* FINAL PRIMER for */

return (intRes);
}

