#include <graphics.h>


/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/* DIBUJA UN RECTANGULO NEGRO PARA BORRAR LA GRAFICA ANTERIOR Y
   ASI DE ESTA FORMA PODER PONER ENCIMA LA NUEVA SIN QUE ESTORBEN
   LOS DATOS DE LA ANTERIOR */

/*--------------------------------------------------------------------------
		FUNCION QUE BORRA GRAFICA ANTERIOR
--------------------------------------------------------------------------*/

void borrar(void)

{

setcolor(BLACK);
setfillstyle(EMPTY_FILL,BLACK);
bar(241,79,581,429);

return;
}
