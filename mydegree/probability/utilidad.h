#include <time.h>
#include <stdlib.h>
#include <dos.h>

/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */                                                                            
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*-----------------------------------------------------------------------------
FUNCION QUE RETARDA UNA TAREA t SEGUNDOS DE TIEMPO REAL INDEPENDIENTEMENTE DEL
PROCESADOR DEL SISTEMA, ********** 0 <= t <= 59
-----------------------------------------------------------------------------*/

void retr (int t)

{

/* PROGRAMA QUE RETARDA UNA ACCION UNOS t SEGUNDOS DE TIEMPO REAL */

struct tm *tiempo; /* ALMACENARA LA FECHA COMO ESTRUCTURA */
time_t hora; /* FECHA Y HORA EN SEGUNDOS */

/* CONTADORES AUXILIARES  LOS NECESITAMOS YA QUE LOS
   VALORES OBTENIDOS EN LA ESTRUCTURA SON ENTEROS LARGOS
   Y AL ALMACENARLOS EN UN ENTERO NORMAL LOS TENEMOS DE 0 A 60 */

int seg;  /* SEGUNDOS */

/* VARIABLE CUYO VALOR VENDRA DADO POR LOS SEGUNDOS
   DE INICIO + EL RETARDO */

int s; /* SEGUNDOS FINALES */

time(&hora); /* OBTIENE LA HORA DEL SISTEMA */
tiempo=gmtime(&hora); /* LA CONVIERTE A ESTRUCTURA tm  */

	/* ASIGNACION DE SEGUNDOS INICIALES */

seg = (*tiempo).tm_sec;

	/* RETARDO DEL SISTEMA */

s = (seg + t) % 60;
while ( seg != s )
	{
	time(&hora); /* OBTIENE LA NUEVA HORA DEL SISTEMA */
	tiempo=gmtime(&hora); /* LA CONVIERTE A ESTRUCTURA tm  */
	seg = (*tiempo).tm_sec;
	}
return; 
}

/*----------------------------------------------------------------------------
    FUNCION QUE GENERA UN NUMERO PSEUDO-ALEATORIO COMPRENDIDO ENTRE 1 Y n
----------------------------------------------------------------------------*/

int num_aleatorio(int n)

{
int numero;

numero = (rand()%n)+1;

return(numero);
}
