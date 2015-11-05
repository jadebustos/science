#include <stdlib.h>
#include <math.h>

#include <biagra/struct.h>
#include <biagra/const.h>

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
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

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* edo.c     Jose Angel de Bustos Perez                                 */
/*                                                                      */
/* Funciones para resolver numericamente E.D.O's.                       */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/


/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* IMPORTANTE!!!                                                        */
/*                                                                      */
/*     1) El autor no se responsabiliza de los posibles bugs(si los     */
/*        hubiera) ni del mal uso de esta biblioteca.                   */
/*                                                                      */
/*     2) Esta biblioteca ha sido desarrollada y testeada bajo LiNUX.   */
/*                                                                      */ 
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/*  Funcion que resuelve un P.V.I. mediante un metodo de RUNGE - KUTTA  */
/*  explicito, *ptstrDatos es un puntero a un tipo de dato definido por */
/*  el usuario(prototip en struct.h), y (*PVI) es un puntero a una      */
/*  funcion que devuelve el valor de la ecuacion diferencial en dblX y  */
/*  dblY.                                                               */ 
/*                                                                      */
/*  La funcion devuelve los siguientes valores:				*/
/*									*/
/*	ERR_AMEM -> Hubo algun error en la asignacion de memoria.	*/
/*	TRUE     -> Se calculo con exito la aproximacion.		*/
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int ExplicitRungeKutta(DatosRK *ptstrDatos, double (*PVI)(double dblX, double dblY) )

{

int 	i, 		/* CONTADOR */
   	j,		/* CONTADOR */
        k;		/* CONTADOR */
        
double	dblPtoAct,	/* PUNTO EN EL QUE SE ESTA CALCULANDO LA APROX */
   	dblPtoPrev,	/* PUNTO ANTERIOR */
        dblX,
        dblY,
        *dblK;		/* PUNTERO DONDE ALMACENAREMOS LOS k_i */       

/* ALMACENAMOS EL PASO COMO UN NUMERO POSITIVO */

(ptstrDatos->dblPaso) = fabs((ptstrDatos->dblPaso));
     
/* RESERVA DE MEMORIA */        

dblK = (double *)calloc(ptstrDatos->strCoefi.intEtapas, sizeof(double));

if ( dblK == NULL )	/* SI HUBO ALGUN ERROR TERMINA */
   
   {
   return (ERR_AMEM);
   }

/* INICIALIZACIONES */

dblPtoAct = (ptstrDatos->dblInicio) + (ptstrDatos->dblPaso);
dblPtoPrev = (ptstrDatos->dblInicio);

for(i = 1;i < (ptstrDatos->intNumAprox) ;i++)

   {	/* INICIO PRIMER for */
      
   /* CALCULO DE LOS ki */
      
   for(k = 0;k < (ptstrDatos->strCoefi.intEtapas);k++)
      
      {  /* INICIO SEGUNDO for */
      
      dblX = dblPtoPrev + ( (ptstrDatos->dblPaso)*(ptstrDatos->strCoefi.dblC[k]) );
      dblY = .0;
   
      for(j = 0;j < k;j++)
      
         dblY += (dblK[j])*(ptstrDatos->strCoefi.dblMatriz[k][j]);   
   
      dblY *= (ptstrDatos->dblPaso);
      dblY += (ptstrDatos->dblPuntos[i-1]);
   
      dblK[k] = (*PVI)(dblX, dblY);
                  
      }	/* FINAL SEGUNDO for */
      
   /* APROXIMACION */
       
   (ptstrDatos->dblPuntos[i]) = .0;

   for(j = 0;j < (ptstrDatos->strCoefi.intEtapas);j++)
   
      (ptstrDatos->dblPuntos[i]) += dblK[j] * (ptstrDatos->strCoefi.dblB[j]);
      
      
   (ptstrDatos->dblPuntos[i]) *= (ptstrDatos->dblPaso);
   (ptstrDatos->dblPuntos[i]) += (ptstrDatos->dblPuntos[i-1]);
   
   dblPtoPrev = dblPtoAct;   
   dblPtoAct += (ptstrDatos->dblPaso);
   
   }	/* FINAL PRIMER for */

/* LIBERAR MEMORIA */
   
free (dblK);   

return (TRUE);   
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que devuelve el numero de nodos que hay en un intervalo de   */
/* longitud dblLong e igualmente espaciados por dblPaso.                */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/


int intNumNodos(double dblLong, double dblPaso)

{
int	intRes = 1;

intRes += (int)ceil(fabs(dblLong)/fabs(dblPaso));

return (intRes);
}
