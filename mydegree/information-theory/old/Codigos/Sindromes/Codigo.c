#include "struct.h"
#include "Mod2.h"
#include "define.h"

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*             FUNCIONES PARA OPERAR CON LAS PALABRAS DEL CODIGO              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* FUNCION PARA SUMAR ELEMENTOS DEL CODIGO */

int SumaCodigo(PalCod *Pal1, PalCod *Pal2, PalCod *Res)

{
int i;

/* SI LAS PALABRAS SON DE DISTINTA LONGITUD ERROR */

if ( (Pal1->intLong != Pal2->intLong) || (Pal1->intLong != Res->intLong) )
   return (MAL);

for(i=0;i<(Pal1->intLong);i++)
     Res->intPalabra[i] = SumaF2(Pal1->intPalabra[i], Pal2->intPalabra[i]);

return (BIEN);
}

/* FUNCION PARA RESTAR ELEMENTOS DEL CODIGO */

int DifCodigo(PalCod *Pal1, PalCod *Pal2, PalCod *Res)

{
int i;

/* SI LAS PALABRAS SON DE DISTINTA LONGITUD ERROR */

if ( (Pal1->intLong != Pal2->intLong) && (Pal1->intLong != Res->intLong) )
   return(MAL);

for(i=0;i<(Pal1->intLong);i++)
     Res->intPalabra[i] = DifF2(Pal1->intPalabra[i], Pal2->intPalabra[i]);

return (BIEN);
}

