#include <stdlib.h>

#include "struct.h"
#include "define.h"

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*               FUNCIONES PARA RESERVAR MEMORIA DINAMICAMENTE                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* FUNCION QUE RESERVA MEMORIA PARA PALABRAS DEL CODIGO */

int ResMemCod(PalCod *Palabra)

{
int i;

Palabra->intPalabra = (int *)calloc(Palabra->intLong, sizeof(int));

if ( Palabra->intPalabra ==  NULL )
   return (ERR_MEM);

/* INICIALIZAMOS A CERO LA PALABRA */

for(i=0;i<Palabra->intLong;i++)
   Palabra->intPalabra[i] = 0;

return (BIEN);
}

/*----------------------------------------------------------------------------*/
/*									      */
/* FUNCION QUE RESERVA MEMORIA PARA UN ARRAY BIDIMENSIONAL, DEL TIPO int,     */
/* DE intFilas FILAS Y intCol COLUMNAS Y DEVUELVE SU DIRECCION.               */
/*									      */
/*----------------------------------------------------------------------------*/

int **intPtAsigMemMat(int intFilas, int intCol)

{
int 	i;

int     **intPt;

/* ASIGNACION DE MEMORIA */

intPt = (int **)calloc(intFilas, sizeof(int *) );

/* SI NO SE PUDO ASIGNAR MEMORIA TERMINA */

if ( intPt == NULL )
   
   return (intPt);
   
else

   {	/* INICIO else */

   for(i=0;i<intFilas;i++)
   
      {	/* INICIO PRIMER for */
      
      intPt[i] = (int *)calloc(intCol, sizeof(int) );
      
      if ( intPt[i] == NULL )
      
      /* SI NO SE PUDO ASIGNAR TODA LA MEMORIA LIBERA LA MEMORIA ASIGNADA
         Y ASIGNA NULL A intPt, A CONTINUACION TERMINA */
         
         {  /* INICIO if */
	
	 while ( i-- > 0 )
		free(intPt[i]);	 

         free(intPt);
         
         intPt = NULL;
         
         break;
         
         }  /* FINAL if */
              
      } /* FINAL PRIMER for */
      
   }	/* FINAL else */

return (intPt);
}
