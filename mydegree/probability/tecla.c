#include <ctype.h>

/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */                                                                            
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*-------------------------------------------------------------------------
FUNCION QUE LEE UNA PULSACION DE TECLADO Y LA DEVUELVE SI ES "c", "f" O "r"
-------------------------------------------------------------------------*/

char leer_tecla(void)

{
char tecla;

do
        tecla = toupper( getch() );

while ( tecla != 'C' && tecla != 'F' && tecla != 'R' && tecla != 'G');

return(tecla);
}
