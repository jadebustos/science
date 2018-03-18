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
