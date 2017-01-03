#include "struct.h"

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*---------------------------------------------------------------------------
	     FUNCION QUE CALCULA EL VALOR DEL JACOBIANO EN punto
	     Y LO ALMACENA EN jac
---------------------------------------------------------------------------*/

void jacobiano(double *punto, struct datos *ptparametros, double **jac)

{
int i, j;       /* CONTADORES */

double res = 0.;

for(i=0;i<(ptparametros->N)-1;i++)

	{
	for(j=0;j<(ptparametros->N);j++)
		{
		par_fn(i+1, j+1, ptparametros, punto, &res);

		jac[i][j] = res;
		}
	}

for (j=0;j<(ptparametros->N);j++)

	{
	par_fN(j+1, punto, ptparametros, &res);
	
	jac[(ptparametros->N)-1][j] = res;
	}

}
