#include <math.h>
#include "struct.h"

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*---------------------------------------------------------------------------
	   ECUACIONES CON LAS DERIVADAS PARCIALES DE w(n) RESPECTO
	   DE LA COORDENADA j-ESIMA EN punto
--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
	FUNCIONES DE APOYO PARA CALCULAR LAS PARCIALES RESPECTO
	LA COORDENADA j-ESIMA DE w_n 
-------------------------------------------------------------------------*/

double h(int n, int j, double *punto, struct datos *ptparametros)

{
double resultado = 0.,
       res_vn = 0.,
       res_par_vn = 0.,
       pot_vn = 0.;
int i;

if ( j > n )
	return (resultado);

else
	{
	for(i=1;i<=(ptparametros->N);i++)
		{
		v_n(i, punto, ptparametros,&res_vn);

		pot_vn = pow(res_vn,3);

		resultado += 1./(pot_vn*cos(punto[i-1]));
		}

	par_vn(n, j, ptparametros, punto, &res_par_vn);

	resultado *= res_par_vn;
	}

return (resultado);
}

/*---------------------------------------------------------------------------
	DERIVADA PARCIAL DE w_n RESPECTO DE LA COORDENADA j-ESIMA, 
	EN punto Y LA ALMACENA EN *ptresultado
---------------------------------------------------------------------------*/

void par_wn(int n, int j, struct datos *ptparametros, double *punto, 
	    double *ptresultado)

{
double res_vn = 0.,
       res_par_vn = 0.,
       primer_miembro = 0.,
       segundo_miembro = 0.;

int i;  /* CONTADOR */

primer_miembro = h(n, j, punto, ptparametros);

/* CALCULO DEL SEGUNDO MIEMBRO */

v_n(j, punto, ptparametros, &res_vn);

par_vn(j, j, ptparametros, punto, &res_par_vn);

segundo_miembro = ( (res_vn*sin(punto[j-1]))-(3*res_par_vn*cos(punto[j-1])) )
		/(pow(res_vn,4)*pow(cos(punto[j-1]),2));

for(i=j+1;i<=(ptparametros->N);i++)
	{
	v_n(i, punto, ptparametros,&res_vn);

	par_vn(i, j, ptparametros, punto, &res_par_vn);

	segundo_miembro +=((-3.)*res_par_vn)/(pow(res_vn,4)*cos(punto[i-1]));
	}

v_n(n, punto, ptparametros, &res_vn);

segundo_miembro *= res_vn;

*ptresultado = (-1.)*(ptparametros->incr_y)*(primer_miembro+segundo_miembro);
}
