#ifndef DATAMATRIX_H
  #define DATAMATRIX_H

/*									*/
/*	B.I.A.G.R.A.	(c) 1998 Jose Angel de Bustos Perez		*/
/*			 <jadebustos@gmail.com>         		*/
/*									*/
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Estructura para manejar matrices.                                    */
/*                                                                      */
/*	intFilas    -> Numero de filas de la matriz.			*/
/*	intColumnas -> Numero de columnas de la matriz.			*/
/*	dblCoefi    -> Coeficientes de la matriz.			*/
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

typedef struct {
  int intRows,
      intCols;

  double **dblCoefs;
  } biaMatrix;        

#endif
