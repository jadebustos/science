#include <graphics.h>

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*----------------------------------------------------------------------
		    RESTAURAR MODO TEXTO ANTERIOR
----------------------------------------------------------------------*/

void fin_modo_grafico ( void )

{
cleardevice ();
closegraph ();
return;
}
