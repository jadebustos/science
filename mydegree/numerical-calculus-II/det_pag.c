#include <stdlib.h>

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*----------------------------------------------------------------------------
        MACRO QUE DETERMINA EL NUMERO DE PAGINAS QUE VA A HABER, EN CADA
        PAGINA APARECERAN 20 VARIABLES
----------------------------------------------------------------------------*/

#define n_pag(cociente,resto) (resto == 0) ? (cociente) : (cociente+1)

int short det_pag (int N)

{
div_t res = {0, 0}; /* VARIABLE DE ESTRUCTURA div_t EN LA QUE SE VA A
		       ALMACENAR EL COCIENTE Y EL RESTO DE UNA DIVISION
		       ENTERA */

res = div (N,20);

return ( n_pag(res.quot, res.rem) );
}
