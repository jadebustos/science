#include <stdlib.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                           <jadebustos@gmail.com>                     */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/*                                                                      */
/* Function to sum the first n integers                                 */
/*                                                                      */ 
/* The forllowing codes are returned:                                   */
/*                                                                      */
/*      0 If sum is bigger than unsigned int maximum value              */
/*                                                                      */
/*      Sum of the first n integers                                     */
/*                                                                      */ 

unsigned uintSumFirstNIntegers(int n) {
	
  double dblHalf = .0,
	 dblSum  = .0;

  int intNum = abs(n);

  unsigned intSum = 0;

  if ( (intNum % 2) == 0 ) {
    dblHalf = ((double)intNum)/2.;
    dblSum  = dblHalf*(1.+(double)intNum);
  }
  else {
    dblHalf = (((double)intNum)-1.)/2.;
    dblSum  = (dblHalf)*(2.+((double)intNum))+1.;
  }

  intSum = (unsigned)dblSum;

  if ( dblHalf > intSum )
    intSum = 0;
		
  return (intSum);
}
