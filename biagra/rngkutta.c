#include <stdlib.h>
#include <math.h>

#include <biagra/rngkutta.h>
#include <biagra/const.h>

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
/*  Function to solve a I.V.P (Cauchy problem) using explicit           */
/*  Runge-Kutta methods.                                                */
/*                                                                      */
/* Arguments:                                                           */
/*    *ptstrDatos -> Pointer to a DataRK data structure                 */
/*    (*IVP)      -> Pointer to a function implementing de differential */
/*                   equation in (dblX, dblY)                           */
/*                                                                      */
/*  The following values are returned:                                  */
/*                                                                      */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*      BIA_TRUE      -> Success                                        */
/*                                                                      */

int ExplicitRungeKutta(biaDataRK *ptData, double (*IVP)(double dblX, double dblY) ) {

  int i,
      j,
      k;
        
  double  dblCurrentPoint,	/* point where the approximation is being calculated */
   	  dbliPrevPoint, 	/* previous point */
          dblX,
          dblY,
          *dblK;		/* vector to store the k_i */       

  /* step-size as a positive number, just in case */
  (ptData->dblStepSize) = fabs((ptData->dblStepSize));
     
  /* memory reservation */        
  dblK = (double *)calloc(ptData->strCoefs.intStages, sizeof(double));

  if ( dblK == NULL ) {
    return (BIA_MEM_ALLOC);
  }

  /* initializations */
  dblCurrentPoint = (ptData->dblFirst) + (ptData->dblStepSize);
  dblPrevPoint = (ptData->dblFirst);

  for(i=1;i<(ptData->intNumApprox);i++) {
      
   /* k_i */
   for(k = 0;k < (ptData->strCoefs.intStages);k++) {
     dblX = dblPrevPoint + ( (ptData->dblStepSize)*(ptData->strCoefs.dblC[k]) );
     dblY = .0;
   
     for(j = 0;j < k;j++)
       dblY += (dblK[j])*(ptData->strCoefs.dblMatrix[k][j]);   
   
     dblY *= (ptData->dblStepSize);
     dblY += (ptData->dblPoints[i-1]);
   
     dblK[k] = (*IVP)(dblX, dblY);
   }
      
   /* approximation */
       
   (ptData->dblPoints[i]) = .0;

   for(j=0;j<(ptData->strCoefs.intStages);j++)
     (ptData->dblPoints[i]) += dblK[j] * (ptData->strCoefs.dblB[j]);
      
   (ptData->dblPoints[i]) *= (ptData->dblStepSize);
   (ptData->dblPoints[i]) += (ptData->dblPoints[i-1]);
   
   dblPrevPoint = dblCurrentPoint;   
   dblCurrentPoint += (ptData->dblStepSize);
   
   }

  /* freing memory */
  free (dblK);   

  return (BIA_TRUE);   
}

/*                                                                      */
/* Function to get the number of nodes in a dblLong size interval where */
/* dblStepSize is the distance between two consecutive nodes.           */
/*									*/

int intNodeNumber(double dblLong, double dblStepSize) {
  int  intRes = 1;

  intRes += (int)ceil(fabs(dblLong)/fabs(dblStepSize));

  return (intRes);
}
