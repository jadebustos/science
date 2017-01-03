#include <math.h>
#include "struct.h"

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*------------------------------------------------------------------------
	FUNCION QUE CALCULA EL VALOR DE LA PARCIAL DE v_n RESPECTO DE LA
	COORDENADA j-ESIMA EN punto, Y LO ALMACENA EN *ptresultado.
------------------------------------------------------------------------*/

void par_vn(int n, int j, struct datos *ptparametros,
	    double *punto, double *ptresultado)

{
double denominador = 0.,
       numerador = 0.;

if ( j > n )
	{
	*ptresultado = 0.;
	return;
	}

if ( j < n )
	{
	numerador = ( (-1.)*(ptparametros->fuerza)*(ptparametros->incr_y)*sin(punto[j-1])) /
		(pow(cos(punto[j-1]),2));

	v_n(n, punto, ptparametros,&denominador);

	*ptresultado = numerador/sqrt(denominador);

	return;
	}

if ( j == n )

	{
	numerador = ((ptparametros->gravedad)*(ptparametros->incr_y))-
		    (((ptparametros->fuerza)*(ptparametros->incr_y)*sin(punto[j-1])) /
		    (pow(cos(punto[j-1]),2)));

	v_n(n, punto, ptparametros,&denominador);

	*ptresultado = numerador/sqrt(denominador);

	return;
	}

}
