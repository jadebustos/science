#include "struct.h"
#include "matriz.h"
#include "define.h"
#include "Mod2.h"
#include <stdio.h>
extern Sindromes Tabla[];

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*             FUNCION QUE INICIALIZA LOS SINDROMES DEL CODIGO                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

void InicializarSindromes(Matriz *MatrizControl)

{
int i;

Tabla[0].Lider[0] = 0; Tabla[0].Lider[3] = 0;
Tabla[0].Lider[1] = 0; Tabla[0].Lider[4] = 0;
Tabla[0].Lider[2] = 0; Tabla[0].Lider[5] = 0;

Tabla[0].Sindrome[0] = 0;
Tabla[0].Sindrome[1] = 0;
Tabla[0].Sindrome[2] = 0;

/* ERROR EN EL PRIMER BIT */

Tabla[1].Lider[0] = 1; Tabla[1].Lider[3] = 0;
Tabla[1].Lider[1] = 0; Tabla[1].Lider[4] = 0;
Tabla[1].Lider[2] = 0; Tabla[1].Lider[5] = 0;

/* ERROR EN EL SEGUNDO BIT */

Tabla[2].Lider[0] = 0; Tabla[2].Lider[3] = 0;
Tabla[2].Lider[1] = 1; Tabla[2].Lider[4] = 0;
Tabla[2].Lider[2] = 0; Tabla[2].Lider[5] = 0;

/* ERROR EN EL TERCER BIT */

Tabla[3].Lider[0] = 0; Tabla[3].Lider[3] = 0;
Tabla[3].Lider[1] = 0; Tabla[3].Lider[4] = 0;
Tabla[3].Lider[2] = 1; Tabla[3].Lider[5] = 0;

/* ERROR EN EL CUARTO BIT */

Tabla[4].Lider[0] = 0; Tabla[4].Lider[3] = 1;
Tabla[4].Lider[1] = 0; Tabla[4].Lider[4] = 0;
Tabla[4].Lider[2] = 0; Tabla[4].Lider[5] = 0;

/* ERROR EN EL QUINTO BIT */

Tabla[5].Lider[0] = 0; Tabla[5].Lider[3] = 0;
Tabla[5].Lider[1] = 0; Tabla[5].Lider[4] = 1;
Tabla[5].Lider[2] = 0; Tabla[5].Lider[5] = 0;

/* ERROR EN EL SEXTO BIT */

Tabla[6].Lider[0] = 0; Tabla[6].Lider[3] = 0;
Tabla[6].Lider[1] = 0; Tabla[6].Lider[4] = 0;
Tabla[6].Lider[2] = 0; Tabla[6].Lider[5] = 1;

/* UN ERROR DE PESO DOS */

Tabla[7].Lider[0] = 1; Tabla[7].Lider[3] = 0;
Tabla[7].Lider[1] = 0; Tabla[7].Lider[4] = 0;
Tabla[7].Lider[2] = 0; Tabla[7].Lider[5] = 1;

/* CALCULO DE LOS SINDROMES */

for(i=1;i<8;i++)
   MulMatVec(MatrizControl, Tabla[i].Lider, Tabla[i].Sindrome);

return;
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*          PROCESADOR DE ERROR PARA EL CODIGO DE TRIPLE REPETICION           */
/*                                                                            */
/*----------------------------------------------------------------------------*/

int ProcError(PalCod *PalRec, PalCod *PalOk, PalCod *Sindr, Sindromes Tabla[])

{
int i,
    j;

/* COMPARAMOS EL SINDROME DE LA PALABRA RECIBIDA CON LOS DE LA TABLA */

for(i=0;i<7;i++)    { /* INICIO PRIMER for */

   for(j=0;j<3;j++) { /* INICIO SEGUNDO for */

      if ( Tabla[i].Sindrome[j] != Sindr->intPalabra[j] )
         break;

      } /* FINAL SEGUNDO for */

   if ( j == 3 ) /* LOS SINDROMES COINCIDEN */
      break;

   } /* FINAL PRIMER for */

if ( i == 7 ) /* SE HA COMETIDO UN ERROR DE PESO DOS */
   return (MAL);

/* CALCULO DE LA PALABRA QUE SE TRANSMITIO ORIGINALMENTE */

for(j=0;j<PalOk->intLong;j++) { /* INICIO PRIMER for */

   PalOk->intPalabra[j] = DifF2(PalRec->intPalabra[j], Tabla[i].Lider[j]);

   } /* FINAL PRIMER for */

return (BIEN);
}
