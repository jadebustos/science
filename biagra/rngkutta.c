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

int ExplicitRungeKutta(DataRK *ptstrDatos, double (*IVP)(double dblX, double dblY) ) {

  int i,
      j,
      k;
        
  double  dblPtoAct,	/* PUNTO EN EL QUE SE ESTA CALCULANDO LA APROX */
   	  dblPtoPrev,	/* PUNTO ANTERIOR */
          dblX,
          dblY,
          *dblK;		/* PUNTERO DONDE ALMACENAREMOS LOS k_i */       

  /* step-size as a positive number, just in case */
  (ptstrDatos->dblStepSize) = fabs((ptstrDatos->dblStepSize));
     
  /* memory reservation */        
  dblK = (double *)calloc(ptstrDatos->strCoefs.intStages, sizeof(double));

  if ( dblK == NULL ) {
    return (BIA_MEM_ALLOC);
  }

  /* initializations */
  dblPtoAct = (ptstrDatos->dblFirst) + (ptstrDatos->dblStepSize);
  dblPtoPrev = (ptstrDatos->dblFirst);

  for(i = 1;i < (ptstrDatos->intNumApprox) ;i++) {
      
   /* ki */
   for(k = 0;k < (ptstrDatos->strCoefs.intStages);k++) {
      
   dblX = dblPtoPrev + ( (ptstrDatos->dblStepSize)*(ptstrDatos->strCoefs.dblC[k]) );
   dblY = .0;
   
   for(j = 0;j < k;j++)
     dblY += (dblK[j])*(ptstrDatos->strCoefs.dblMatrix[k][j]);   
   
   dblY *= (ptstrDatos->dblStepSize);
   dblY += (ptstrDatos->dblPoints[i-1]);
   
   dblK[k] = (*IVP)(dblX, dblY);
                  
   }
      
   /* APROXIMACION */
       
   (ptstrDatos->dblPoints[i]) = .0;

   for(j = 0;j < (ptstrDatos->strCoefs.intStages);j++)
     (ptstrDatos->dblPoints[i]) += dblK[j] * (ptstrDatos->strCoefs.dblB[j]);
      
   (ptstrDatos->dblPoints[i]) *= (ptstrDatos->dblStepSize);
   (ptstrDatos->dblPoints[i]) += (ptstrDatos->dblPoints[i-1]);
   
   dblPtoPrev = dblPtoAct;   
   dblPtoAct += (ptstrDatos->dblStepSize);
   
   }

  /* freing memory */
  free (dblK);   

  return (BIA_TRUE);   
}

/*                                                                      */
/* Funcion que devuelve el numero de nodos que hay en un intervalo de   */
/* longitud dblLong e igualmente espaciados por dblPaso.                */
/*									*/


int intNumNodos(double dblLong, double dblPaso)

{
int	intRes = 1;

intRes += (int)ceil(fabs(dblLong)/fabs(dblPaso));

return (intRes);
}
