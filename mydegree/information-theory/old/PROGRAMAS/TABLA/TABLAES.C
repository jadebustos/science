#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "define.h"
#include "Mod2.h"

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                 FUNCION QUE INICIALIZA LA TABLA ESTANDAR                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

int InicializarTablaEstandar(PalCod Tabla[][8])

{
int i,
    j,
    k;

for(i=0;i<8;i++) { /* INICIO PRIMER for */

   for(j=0;j<8;j++)   { /* INICIO SEGUNDO for */

      Tabla[i][j].intLong = 6; /* LONGITUD DE PALABRA DEL CODIGO */

      /* RESERVA DE MEMORIA */

      Tabla[i][j].intPalabra = (int *)calloc(6, sizeof(int));

      if ( Tabla[i][j].intPalabra == NULL ) /* ERROR EN LA ASIGNACION */
         return(ERR_MEM);

      } /* FINAL SEGUNDO for */

   } /* FINAL PRIMER for */

/* PALABRAS DEL CODIGO */

Tabla[0][0].intPalabra[0] = Tabla[0][0].intPalabra[1] = 0;
Tabla[0][0].intPalabra[2] = Tabla[0][0].intPalabra[3] = 0;
Tabla[0][0].intPalabra[4] = Tabla[0][0].intPalabra[5] = 0;

Tabla[0][2].intPalabra[0] = 0; Tabla[0][2].intPalabra[1] = 1;
Tabla[0][2].intPalabra[2] = 0; Tabla[0][2].intPalabra[3] = 1;
Tabla[0][2].intPalabra[4] = 0; Tabla[0][2].intPalabra[5] = 1;

Tabla[0][1].intPalabra[0] = 1; Tabla[0][1].intPalabra[1] = 0;
Tabla[0][1].intPalabra[2] = 0; Tabla[0][1].intPalabra[3] = 1;
Tabla[0][1].intPalabra[4] = 1; Tabla[0][1].intPalabra[5] = 0;

Tabla[0][3].intPalabra[0] = 0; Tabla[0][3].intPalabra[1] = 0;
Tabla[0][3].intPalabra[2] = 1; Tabla[0][3].intPalabra[3] = 0;
Tabla[0][3].intPalabra[4] = 1; Tabla[0][3].intPalabra[5] = 1;

Tabla[0][4].intPalabra[0] = 1; Tabla[0][4].intPalabra[1] = 1;
Tabla[0][4].intPalabra[2] = 1; Tabla[0][4].intPalabra[3] = 0;
Tabla[0][4].intPalabra[4] = 0; Tabla[0][4].intPalabra[5] = 0;

Tabla[0][5].intPalabra[0] = 0; Tabla[0][5].intPalabra[1] = 1;
Tabla[0][5].intPalabra[2] = 1; Tabla[0][5].intPalabra[3] = 1;
Tabla[0][5].intPalabra[4] = 1; Tabla[0][5].intPalabra[5] = 0;

Tabla[0][6].intPalabra[0] = 1; Tabla[0][6].intPalabra[1] = 0;
Tabla[0][6].intPalabra[2] = 1; Tabla[0][6].intPalabra[3] = 1;
Tabla[0][6].intPalabra[4] = 0; Tabla[0][6].intPalabra[5] = 1;

Tabla[0][7].intPalabra[0] = 1; Tabla[0][7].intPalabra[1] = 1;
Tabla[0][7].intPalabra[2] = 0; Tabla[0][7].intPalabra[3] = 0;
Tabla[0][7].intPalabra[4] = 1; Tabla[0][7].intPalabra[5] = 1;

/* PATRONES DE ERROR */

Tabla[1][0].intPalabra[0] = 1; Tabla[1][0].intPalabra[1] = 0;
Tabla[1][0].intPalabra[2] = 0; Tabla[1][0].intPalabra[3] = 0;
Tabla[1][0].intPalabra[4] = 0; Tabla[1][0].intPalabra[5] = 0;

Tabla[2][0].intPalabra[0] = 0; Tabla[2][0].intPalabra[1] = 1;
Tabla[2][0].intPalabra[2] = 0; Tabla[2][0].intPalabra[3] = 0;
Tabla[2][0].intPalabra[4] = 0; Tabla[2][0].intPalabra[5] = 0;

Tabla[3][0].intPalabra[0] = 0; Tabla[3][0].intPalabra[1] = 0;
Tabla[3][0].intPalabra[2] = 1; Tabla[3][0].intPalabra[3] = 0;
Tabla[3][0].intPalabra[4] = 0; Tabla[3][0].intPalabra[5] = 0;

Tabla[4][0].intPalabra[0] = 0; Tabla[4][0].intPalabra[1] = 0;
Tabla[4][0].intPalabra[2] = 0; Tabla[4][0].intPalabra[3] = 1;
Tabla[4][0].intPalabra[4] = 0; Tabla[4][0].intPalabra[5] = 0;

Tabla[5][0].intPalabra[0] = 0; Tabla[5][0].intPalabra[1] = 0;
Tabla[5][0].intPalabra[2] = 0; Tabla[5][0].intPalabra[3] = 0;
Tabla[5][0].intPalabra[4] = 1; Tabla[5][0].intPalabra[5] = 0;

Tabla[6][0].intPalabra[0] = 0; Tabla[6][0].intPalabra[1] = 0;
Tabla[6][0].intPalabra[2] = 0; Tabla[6][0].intPalabra[3] = 0;
Tabla[6][0].intPalabra[4] = 0; Tabla[6][0].intPalabra[5] = 1;

Tabla[7][0].intPalabra[0] = 1; Tabla[7][0].intPalabra[1] = 0;
Tabla[7][0].intPalabra[2] = 0; Tabla[7][0].intPalabra[3] = 0;
Tabla[7][0].intPalabra[4] = 0; Tabla[7][0].intPalabra[5] = 1;

/* CALCULAMOS Y ALMACENAMOS EL RESTO DE PALABRAS DE (Z/2)^6 */

for(i=1;i<8;i++) { /* INICIO PRIMER for */

/* ESTE BUCLE CONTROLA LAS FILAS DE LA TABLA ESTANDAR */

   for(j=1;j<8;j++) { /* INICIO SEGUNDO for */

   /* ESTE BUCLE CONTROLA LAS COLUMNAS DE LA TABLA ESTANDAR */

      for(k=0;k<6;k++) { /* INICIO TERCER for */

      /* ESTE BUCLE SUMA LAS PALABRAS */

         Tabla[i][j].intPalabra[k] = SumaF2(Tabla[i][0].intPalabra[k],
                                             Tabla[0][j].intPalabra[k]);

         } /* FINAL TERCER for */

      } /* FINAL SEGUNDO for */

   } /* FINAL PRIMER for */

return(BIEN);
}

/*----------------------------------------------------------------------------*/
/*									     */
/* FUNCION COMPRUEBA LA PALABRA RECIBIDA Y CALCULA LA QUE SE TRANSMITIO.      */
/*									      */
/*----------------------------------------------------------------------------*/

void Decodificar(PalCod  Tabla[][8], PalCod *PalRec, int *intFila, int *intCol)

{
int i,
    j,
    k;

for(i=0;i<8;i++) { /* INICIO PRIMER for */

   for(j=0;j<8;j++) { /* INICIO SEGUNDO for */

      for(k=0;k<6;k++) { /* INICIO TERCER for */

         if ( PalRec->intPalabra[k] != Tabla[i][j].intPalabra[k] )
            break;

         } /* FINAL TERCER for */

      if ( k>=6 ) { /* PALABRA ENCONTRADA */

         *intFila = i;
         *intCol = j;

         return;
         }
 
      } /* FINAL SEGUNDO for */

   } /* FINAL PRIMER FOR */

return;
}
