#include <stdio.h>

#include "struct.h"
#include "mem.h"
#include "iodat.h"
#include "define.h"
#include "descrip.h"
#include "tablaes.h"

#define LONGITUD        6 /* BITS TOTALES */
#define BITSINFORMACION 3 /* BITS DE INFORMACION EN EL CODIGO */

int main (void)

{
PalCod PalRec; /* PALABRA RECIBIDA */

PalCod Tabla[8][8];

int i,
    intFila,
    intCol;

/* DESCRIPCION DEL PROGRAMA */

Descripcion();

/* ESTABLECEMOS LA LONGITUD DE PALABRA DEL CODIGO */

PalRec.intLong = LONGITUD;

/* RESERVAMOS MEMORIA PARA LAS PALABRAS DEL CODIGO */

i = ResMemCod(&PalRec);

if ( i != BIEN ) { /* HUBO UN ERROR DE MEMORIA */
   printf("\nOcurrio algun error de memoria.\n");
   return (i); /* FIN */
   }

/* LEEMOS DE LA SALIDA ESTANDAR UNA PALABRA */

i = LeerDato(&PalRec);

if ( i != BIEN ) { /* ERROR EN LA CADENA DE TEXTO */
   printf("\nNo se pudo extraer una palabra del texto introducido.\n");
   return(i);
   }

if ( i != BIEN ) { 
   printf("\nNo hay memoria suficiente para continuar.\n");
   return(i);
   }

/* INICIALIZAMOS LA TABLA ESTANDAR */

i = InicializarTablaEstandar(Tabla);

if ( i != BIEN  ) {
   printf("\nNo hay memoria suficiente para continuar.\n");
   return(i);
   }

/* COMPROBAMOS LA PALABRA RECIBIDA */

Decodificar(Tabla, &PalRec, &intFila, &intCol);

/* IMPRIMIMOS LOS RESULTADOS */

printf("\nPalabra recibida: ");

for(i=0;i<PalRec.intLong;i++)
   printf("%d", PalRec.intPalabra[i]);

if ( intFila < 7 ) { /* INICIO if */

   printf("\nLa palabra transmitida fue: ");

   for(i=0;i<PalRec.intLong;i++)
      printf("%d", Tabla[0][intCol].intPalabra[i]);

   printf("\n");

   } /* FINAL if */

else { /* INICIO else */

   printf("\nOcurrio un error de peso dos.\n");

   } /* FINAL else */

return (BIEN); /* FIN */
}
