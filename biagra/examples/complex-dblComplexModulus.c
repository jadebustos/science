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

/* Simple example of dblComplexModulus usage */

int main (void) {

  int i = 0;
  double modulus;

  /* complex numbers */
  biaComplex myCmplx;

  /* initialization */
  myCmplx.dblReal = 1.;
  myCmplx.dblImag = 3.5;

  /* division */
  modulus = dblComplexModulus(&myCmplx);

  /* print to stdout */
  printf("z = %g + %g * i\n", myCmplx.dblReal, myCmplx.dblImag);
  printf("|z| = %g\n", modulus);
  
  return BIA_TRUE;
	
}
