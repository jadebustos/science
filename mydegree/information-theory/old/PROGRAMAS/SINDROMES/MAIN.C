#include <stdio.h>

#include "struct.h"
#include "mem.h"
#include "iodat.h"
#include "define.h"
#include "descrip.h"
#include "check.h"
#include "matriz.h"
#include "sindromes.h"

#define LONGITUD        6 /* BITS TOTALES */
#define BITSINFORMACION 3 /* BITS DE INFORMACION EN EL CODIGO */

Sindromes Tabla[8]; /* SINDROMES DEL CODIGO */

int main (void)

{
PalCod PalRec, /* PALABRA RECIBIDA */
       PalOk,  /* PALABRA QUE, CON MAS PROBABILIDAD, SE TRANSMITIO */
       Sindr; /* SINDROME DE LA PALABRA RECIBIDA */

Matriz MatrizControl; /* MATRIZ DE CONTROL DEL CODIGO */

int i;

/* DESCRIPCION DEL PROGRAMA */

Descripcion();

/* ESTABLECEMOS LA LONGITUD DE PALABRA DEL CODIGO */

PalRec.intLong = LONGITUD;
PalOk.intLong  = LONGITUD;

/* RESERVAMOS MEMORIA PARA LAS PALABRAS DEL CODIGO */

i = ResMemCod(&PalRec);

if ( i != BIEN ) { /* HUBO UN ERROR DE MEMORIA */
   printf("\nOcurrio algun error de memoria.\n");
   return (i); /* FIN */
   }

i = ResMemCod(&PalOk);

if ( i != BIEN ) { /* HUBO UN ERROR DE MEMORIA */
   printf("Ocurrio algun error de memoria.\n");
   return (i); /* FIN */
   }

/* RESERVAMOS MEMORIA PARA LA MATRIZ DE CONTROL */

MatrizControl.intFilas = (int)(LONGITUD-BITSINFORMACION);
MatrizControl.intCol   = (int)(LONGITUD);

MatrizControl.intElemento = 
          (int **)intPtAsigMemMat(MatrizControl.intFilas, MatrizControl.intCol);

if ( MatrizControl.intElemento == NULL ) { /* HUBO UN ERROR DE MEMORIA */
   printf("\nOcurrio algun error de memoria.\n");
   return(ERR_MEM); /* FIN */
   }

/* RESERVAMOS MEMORIA PARA EL SINDROME */

Sindr.intLong = 3;

i = ResMemCod(&Sindr);

if ( i != BIEN ) { /* HUBO UN ERROR DE MEMORIA */
   printf("\nOcurrio algun error de memoria.\n");
   return(ERR_MEM);
   }

/* LEEMOS DE LA SALIDA ESTANDAR UNA PALABRA */

i = LeerDato(&PalRec);

if ( i != BIEN ) { /* ERROR EN LA CADENA DE TEXTO */
   printf("\nNo se pudo extraer una palabra del texto introducido.\n");
   return(i);
   }

/* INICIALIZAMOS LA MATRIZ DE CONTROL */

InicializarCheck(&MatrizControl);

/* CALCULAMOS EL SINDROME */

MulMatVec(&MatrizControl, PalRec.intPalabra, Sindr.intPalabra);

/* INICIALIZAMOS SINDROMES DE LOS ERRORES */

InicializarSindromes(&MatrizControl);

/* PROCESAMOS EL ERROR */

i = ProcError(&PalRec, &PalOk, &Sindr, Tabla);

/* IMPRIMIMOS LOS RESULTADOS */

if ( i == BIEN ) { /* INICIO if */
   printf("\nPalabra recibida: ");

   for(i=0;i<PalRec.intLong;i++)
      printf("%d", PalRec.intPalabra[i]);

   printf("\nLa palabra transmitida fue: ");

   for(i=0;i<PalOk.intLong;i++)
      printf("%d", PalOk.intPalabra[i]);

   printf("\n");

   } /* FINAL if */

else { /* INICIO else */

   printf("\nOcurrio un error de peso dos.\n");

   } /* FINAL else */

return (BIEN); /* FIN */
}
