#include <stdlib.h>

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
/* resmem.c     Jose Angel de Bustos Perez                              */
/*                                                                      */
/* Funciones para reservar memoria.                                     */
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
/* Funcion que reserva memoria para un array unidimensional, del tipo   */
/* double, de intN elementos y devuelve su direccion.                   */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

double *dblPtAsigMemVec(int intN)

{

double *dblPt;

/* ASIGNACION DE MEMORIA */

dblPt = (double *)calloc(intN, sizeof(double));

return (dblPt);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* Funcion que reserva memoria para un array bidimensional, del tipo    */
/* double, de intFilas filas y intCol columnas y devuelve su direccion. */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

double **dblPtAsigMemMat(int intFilas, int intCol)

{
int 	i;

double	**dblPt;

/* ASIGNACION DE MEMORIA */

dblPt = (double **)calloc(intFilas, sizeof(double *) );

/* SI NO SE PUDO ASIGNAR MEMORIA TERMINA */

if ( dblPt == NULL )
   
   return (dblPt);
   
else

   {	/* INICIO else */

   for(i=0;i<intFilas;i++)
   
      {	/* INICIO PRIMER for */
      
      dblPt[i] = (double *)calloc(intCol, sizeof(double) );
      
      if ( dblPt[i] == NULL )
      
      /* SI NO SE PUDO ASIGNAR TODA LA MEMORIA LIBERA LA MEMORIA ASIGNADA
         Y ASIGNA NULL A dblPt, A CONTINUACION TERMINA */
         
         {  /* INICIO if */
	
	 while ( i-- > 0 )
		free(dblPt[i]);	 

         free(dblPt);
         
         dblPt = NULL;
         
         break;
         
         }  /* FINAL if */
              
      } /* FINAL PRIMER for */
      
   }	/* FINAL else */

return (dblPt);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* Funcion que reserva memoria para una matriz triangular superior, del */
/* tipo double, cuadrada de orden intN.                                 */
/*                                                                      */
/* La primera fila contiene intN elementos, la segunda fila tiene intN-1*/
/* elementos, la fila n-esima tiene intN-(n-1) elementos y la fila      */
/* intN-esima tiene un elemento.                                        */
/*                                                                      */
/* La funcion devuelve la direccion del primer elemento, es decir un    */
/* puntero a puntero double.                                            */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

double **dblPtAsigMemMatTrSup(int intN)

{
int 	i,
   	intAux = intN;

double	**dblPt;

dblPt = (double **)calloc(intN, sizeof(double *) );

/* SI NO SE PUDO ASIGNAR MEMORIA TERMINA */

if ( dblPt == NULL )
   
   return (dblPt);
   
else

   {	/* INICIO else */

   for(i=0;i<intN;i++)
   
      {	/* INICIO PRIMER for */
      
      dblPt[i] = (double *)calloc(intAux--, sizeof(double) );

      if ( dblPt[i] == NULL )
      
      /* SI NO SE PUDO ASIGNAR TODA LA MEMORIA LIBERA LA MEMORIA ASIGNADA
         Y ASIGNA NULL A dblPt, A CONTINUACION TERMINA */
         
         {  /* INICIO if */
      
	 while ( i-- > 0 )
		free(dblPt[i]);   

         free(dblPt);
         
         dblPt = NULL;
         
         break;
         
         }  /* FINAL if */	
              
      } /* FINAL PRIMER for */
      
   }	/* FINAL else */

return (dblPt);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* Funcion que reserva memoria para una matriz triangular inferior, del */
/* tipo double, cuadrada de orden intN.                                 */
/*                                                                      */
/* La primera fila contiene un elemento, la segunda fila tiene dos      */
/* elementos, la fila n-esima tiene n elementos y la fila intN-esima    */
/* tiene intN elementos.                                                */
/*                                                                      */
/* La funcion devuelve la direccion del primer elemento, es decir un    */
/* puntero a puntero double.                                            */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

double **dblPtAsigMemMatTrInf(int intN)

{
int 	i;

double	**dblPt;

dblPt = (double **)calloc(intN, sizeof(double *) );

/* SI NO SE PUDO ASIGNAR MEMORIA TERMINA */

if ( dblPt == NULL )
   
   return (dblPt);
   
else

   {	/* INICIO else */

   for(i=0;i<intN;i++)
   
      {	/* INICIO PRIMER for */
      
      dblPt[i] = (double *)calloc(i+1, sizeof(double) );

      if ( dblPt[i] == NULL )
      
      /* SI NO SE PUDO ASIGNAR TODA LA MEMORIA LIBERA LA MEMORIA ASIGNADA
         Y ASIGNA NULL A dblPt, A CONTINUACION TERMINA */
         
         {
         
	 while ( i-- > 0 )
		free(dblPt[i]); 

         free(dblPt);
         
         dblPt = NULL;
         
         break;
         
         }
              
      } /* FINAL PRIMER for */
      
   }	/* FINAL else */

return (dblPt);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* Funcion que libera la memoria asignada a una matriz de punteros      */
/* del tipo double, la cual tiene intFilas filas.                       */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void FreeMemDblMat(double **dblMatriz, int intFilas)

{
int	i;

for(i=0;i<intFilas;i++)
   	free(dblMatriz[i]);
        
free(dblMatriz);

return;        
}

