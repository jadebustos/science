#include <math.h>
#include "struct.h"

/*--------------------------------------------------------------------------
	DERIVADAS PARCIALES DE LAS FUNCIONES f(n) DONDE n = 1,...,N-1
	Y DE LA FUNCION f(N) EN punto.
--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
	FUNCION DE APOYO PARA CALCULAR LA PARCIAL DE g_n EN punto
--------------------------------------------------------------------------*/

double delta(int n, int j, double *punto, struct datos *ptparametros)
{
double res_vn = 0.,
       resultado = 0.;

if ( j != n )
	{
	return (0.);
	}

else
	{
	v_n(n, punto, ptparametros, &res_vn);
	resultado = cos(punto[j-1])*res_vn;
	}

return (resultado);
}

/*--------------------------------------------------------------------------
	     FUNCION QUE CALCULA LA PARCIAL DE g_n EN punto, Y
	     LA ALMACENA EN *ptresultado
--------------------------------------------------------------------------*/

void par_gn(int n, int j, struct datos *ptparametros,
	    double *punto, double *ptresultado)

{
double res_wn = 0.,
       res_par_vn = 0.,
       res_vn = 0.,
       res_par_wn = 0.,
       prim_suman = 0.,
       num_prim = 0.,
       segun_suman = 0.,
       num_segun = 0;

w_n(n, punto, ptparametros, &res_wn);

par_vn(n, j, ptparametros, punto, &res_par_vn);


num_prim = (1-((ptparametros->fuerza)*res_wn))*(delta(n, j, punto, ptparametros)-
		(sin(punto[n-1])*res_par_vn));

v_n(n, punto, ptparametros, &res_vn);

prim_suman = num_prim/pow(res_vn,2);

par_wn(n, j, ptparametros, punto, &res_par_wn);

num_segun = (ptparametros->fuerza)*sin(punto[n-1])*res_par_wn;

segun_suman = num_segun/res_vn;

*ptresultado = prim_suman-segun_suman;

return;
}

/*-------------------------------------------------------------------------
	  PARCIAL DE f_n RESPECTO DE LA COORDENADA j-ESIMA
	  EN punto Y LO ALMACENA EN *ptresultado
-------------------------------------------------------------------------*/

void par_fn(int n, int j, struct datos *ptparametros, double *punto,
	double *ptresultado)

{
double par_gn1 = 0.,
       par_gn2 = 0.;

par_gn(n+1, j, ptparametros, punto, &par_gn2);

par_gn(n, j, ptparametros, punto, &par_gn1);

*ptresultado = par_gn2-par_gn1;

return;
}

/*--------------------------------------------------------------------------
	DERIVADA PARCIAL DE f(N) RESPECTO DE LA COORDENADA j-ESIMA
	EN punto Y LO ALMACENA EN *ptpunto
--------------------------------------------------------------------------*/

void par_fN(int j, double *punto, struct datos *ptparametros, 
		double *ptresultado)

{

*ptresultado = (ptparametros->incr_y)/(pow(cos(punto[j-1]),2));

return;
}
