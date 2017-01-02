#include <math.h>
#include "struct.h"

/*--------------------------------------------------------------------------
		ECUACIONES DEL SISTEMA A RESOLVER
--------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
  ACLARACIONES:

	(a) LAS ECUACIONES f(n)(é(1),...,é(N)) LAS HEMOS DESCOMPUESTO EN
	    SUMA DE DOS g(n+1)(é(1),...,é(N))-g(n)(é(1),...,é(N)) para
	    n = 1,...N-1.

	(b) RECORDAR QUE LA COMPONENTE i-ESIMA DE VECTOR TIENE POR INDICE
	    i-1.
-------------------------------------------------------------------------*/

/* SUBECUACION v(n) DEL PROBLEMA, ALMACENA EL RESULTADO EN *ptresultado */

void v_n(int n, double *punto, struct datos *ptparametros, double *ptresultado)

{
double resultado = 0.,
       sumatorio = 0.;

int i;  /* CONTADOR */

for (i=1;i<=n;i++)

	{
	sumatorio += (1./(cos (punto[i-1])));
	}

resultado = pow(ptparametros->velocidad_inicial,2)+
		(2*(ptparametros->gravedad)*n*(ptparametros->incr_y))-
		(2*(ptparametros->fuerza)*(ptparametros->incr_y)*sumatorio);

*ptresultado = sqrt (resultado);

return;
}

/* SUBECUACION w(n) DEL PROBLEMA, ALMACENA EL RESULTADO EN *ptresultado */

void w_n(int n, double *punto, struct datos *ptparametros, double *ptresultado)

{

double res = 0.,
       sumatorio = 0.;

int i;  /* CONTADOR */

for (i=1;i<=(ptparametros->N);i++)
	{
	v_n(i, punto, ptparametros,&res);

	sumatorio += (1./(pow(res, 3)*cos(punto[i-1]) ) );
	}

v_n(n, punto, ptparametros, &res);

*ptresultado = (-1.)*(ptparametros->incr_y)*res*sumatorio;

return;
}

/* ECUACION MEDIANTE LA CUAL PONEMOS f(n)(...) EN FUNCION DE DOS IGUALES
   A ELLA, CALCULA SU VALOR EN punto Y LO ALMACENA EN *ptresultado */

void g_n(int n, double *punto, struct datos *ptparametros, double *ptresultado)

{
double res_v_n = 0.,
       res_w_n = 0.;

v_n(n, punto, ptparametros, &res_v_n);

w_n(n, punto, ptparametros, &res_w_n);

*ptresultado = (sin(punto[n-1])*(1-((ptparametros->fuerza)*res_w_n)))/res_v_n;

return;
}

/* ECUACIONES f(n)(...) PARA n=1,...,N-1, CALCULA EL VALOR DE f(n) Y
   LO ALMACENA EN *ptresultado */

void f_n(int n, double *punto, struct datos *ptparametros, double *ptresultado)


{
double res_1 = 0.,
       res_2 = 0.;

g_n(n+1, punto, ptparametros, &res_2);
g_n(n, punto, ptparametros, &res_1);

*ptresultado = res_2-res_1;

return;
}

/* ECUACION f(N)(...), ALMACENA SU VALOR EN punto EN *ptresultado */

void f_N(double *punto, struct datos *ptparametros, double *ptresultado)

{
double sumatorio = 0.;

int i;  /* CONTADOR */

for (i=1;i<=(ptparametros->N);i++)
	{
	sumatorio += tan(punto[i-1]);
	}

*ptresultado = ((ptparametros->incr_y)*sumatorio) - (ptparametros->X);

return;
}
