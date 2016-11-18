#include <stdio.h>

#include <biagra/datacomplex.h>
#include <biagra/complex.h>
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

/* Simple example of addComplex usage */

int main (void) {

  /* complex numbers */
  biaComplex myCmplx1,
             myCmplx2,
             myRes;

  /* initialization */
  myCmplx1.dblReal = 1.;
  myCmplx1.dblImag = 3.5;
  myCmplx2.dblReal = -4.09;
  myCmplx2.dblImag = 0.00876;

  /* addition */
  addComplex(&myCmplx1, &myCmplx2, &myRes);

  /* print to stdout */
  printf("z1 = %g + %g * i\n", myCmplx1.dblReal, myCmplx1.dblImag);
  printf("z2 = %g + %g * i\n", myCmplx2.dblReal, myCmplx2.dblImag);
  printf("z1 + z2 = %g + %g * i\n", myRes.dblReal, myRes.dblImag);
  
  return BIA_TRUE;
	
}
