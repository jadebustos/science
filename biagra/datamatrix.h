#ifndef _DATAMATRIX_H
  #define _DATAMATRIX_H

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
/* Data structure to store matrices                                     */
/*                                                                      */
/*      intRows  -> Number of rows                                      */
/*      intCols  -> Number of columns                                   */
/*      dblCoefs -> Matrix coeficients                                  */
/*                                                                      */

  typedef struct {
    int intRows,
        intCols;

    double **dblCoefs;
    } biaMatrix;        

#endif
