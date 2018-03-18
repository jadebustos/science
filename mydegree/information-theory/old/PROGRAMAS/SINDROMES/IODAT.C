#include <stdio.h>

#include "struct.h"
#include "define.h"

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*      FUNCION PARA RECOGER PALABRAS DEL CODIGO DESDE LA SALIDA ESTANDAR     */
/*                                                                            */
/*----------------------------------------------------------------------------*/

int LeerDato(PalCod *Palabra)

{
int i,
    intNumero = 0;

char chrTexto[80];

printf("Introduce una palabra del codigo: ");
gets(chrTexto);

/* DE LA CADENA DE TEXTO RECOGEMOS LOS Palabra->intLong PRIMEROS NUMEROS Y LOS
   CONVERTIMOS A Z/2 PARA FORMAR LA PALABRA DEL CODIGO */

for(i=0;i<80 || chrTexto[i] != '\0';i++) { /* INICIO for */

   if ( chrTexto[i] >= 48 && chrTexto[i] <= 57 ) { /* INICIO if */

      Palabra->intPalabra[intNumero++] = (chrTexto[i]-48)%2;

      } /* FINAL if */

   if ( intNumero >= (Palabra->intLong) ) 
      return (BIEN);

   } /* FINAL for */

return (MAL);
}
