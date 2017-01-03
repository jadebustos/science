#include "struct.h"

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*---------------------------------------------------------------------------
	     FUNCION QUE CALCULA EL VALOR DE LA FUNCION EN punto
	     Y LO ALMACENA EN valor_f
---------------------------------------------------------------------------*/

void funcion(double *punto, struct datos *ptparametros, double *valor_f)

{
int i;  /* CONTADOR */

double res = 0.;

for(i=0;i<(ptparametros->N)-1;i++)
	{
	f_n(i+1, punto, ptparametros, &res);

	valor_f[i] = res;
	}

f_N(punto, ptparametros, &res);

valor_f[(ptparametros->N)-1] = res;

return;
}
