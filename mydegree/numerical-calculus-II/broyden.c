#include <stdlib.h>
#include "struct.h"

#define BROYDEN 2

/*--------------------------------------------------------------------------
  FUNCION QUE SE ENCARGA DE RESOLVER EL PROBLEMA MEDIANTE EL METODO
  DE BROYDEN, DONDE vector ES LA APROXIMACION INICIAL, LA FUNCION
  DEVUELVE LOS SIGUIENTES CODIGOS.

	-1 HUBO UN ERROR EN LA ASIGNACION DE MEMORIA

	0 NO SE PUDO CALCULAR ALGUNA APROXIMACION

	1 SE CALCULO CON EXITO LA SOLUCION DEL PROBLEMA

       -2 NO SE LLEGA A LA SOLUCION EN EL NUMERO DE ITERACIONES
	  ESTABLECIDAS POR EL USUARIO

--------------------------------------------------------------------------*/

int hacer_broyden (struct datos *ptparametros, double *vector, 
			double *error_broy)

{
int i,  /* CONTADOR */
    broyden_ite = 0;  /* ITERACIONES REALIZADAS */

double error = 1000.;   /* ERROR COMETIDO EN CADA ITERACION */

/* VECTOR QUE ES LA DIFERENCIA ENTRE DOS APROCIMACIONES SUCESIVAS,
   SE UTILIZA PARA CALCULAR LA SIGUIENTE APROXIMACION Y LAS MATRICES
   DE ITERACION */

double *s;

/* VECTOR QUE ES LA DIFERENCIA DEL VALOR DEL SISTEMA EN vector_ns Y
   vector_n, SE UTILIZA PARA CALCULAR LA MATRICES DE ITERACION */

double *y;

/* VALOR DE LA FUNCION EN vector_n */

double *fn;

double **jac;   /* JACOBIANO DEL SISTEMA */

/* vector_n ES LA APROXIMACION OBTENIDA EN LA ITERACION n-ESIMA, MIENTRAS
   QUE vector_ns ES LA APROXIMACION OBTENIDA EN LA ITERACION (n+1)-ESIMA */

double *vector_n,
       *vector_ns;

/* ASIGNACION DE MEMORIA PARA LOS VECTORES */

vector_n = (double *)calloc(ptparametros->N,sizeof(double));

/* SI HAY ERROR LA ASIGNACION DEVUELVE -1 */

if ( vector_n == NULL )

	{
	return (-1);
	}

vector_ns = (double *)calloc(ptparametros->N,sizeof(double));

/* SI HAY ERROR LA ASIGNACION DEVUELVE -1 */

if ( vector_ns == NULL )

	{
	/* LIBERA LA MEMORIA ASIGNADA A vector_n */

	free(vector_n);

	return (-1);
	}

s = (double *)calloc(ptparametros->N,sizeof(double));

/* SI HAY ERROR LA ASIGNACION DEVUELVE -1 */

if ( s == NULL )

	{
	/* LIBERA LA MEMORIA ASIGNADA */

	free(vector_n);
	free(vector_ns);

	return (-1);
	}

y = (double *)calloc(ptparametros->N,sizeof(double));

/* SI HAY ERROR LA ASIGNACION DEVUELVE -1 */

if ( y == NULL )

	{
	/* LIBERA LA MEMORIA ASIGNADA */

	free(vector_n);
	free(vector_ns);
	free(s);

	return (-1);
	}


fn = (double *)calloc(ptparametros->N,sizeof(double));

/* SI HAY ERROR LA ASIGNACION DEVUELVE -1 */

if ( fn == NULL )

	{
	/* LIBERA LA MEMORIA ASIGNADA */

	free(vector_n);
	free(vector_ns);
	free(s);
	free(y);

	return (-1);
	}

/* RESERVA DE MEMORIA PARA jac */

jac = (double **)calloc(ptparametros->N,sizeof(double *));

/* SI HAY UN ERROR EN LA ASIGNACION DE MEMORIA DEVUELVE -1 */

if ( jac == NULL )
	{
	/* LIBERA LA MEMORIA ASIGNADA A vector_n, vector_ns */

	free(vector_n);
	free(vector_ns);
	free(s);
	free(y);
	free(fn);

	return (-1);
	}

for(i=0;i<(ptparametros->N);i++)
	{       /* INICIO FOR */

	jac[i] = (double *)calloc(ptparametros->N,sizeof(double));

	/* SI HUBO ERROR EN LA ASIGNACION DE MEMORIA DEVUELVE -1 */

	if ( jac[i] == NULL )
		{
		/* LIBERA LA MEMORIA ASIGNADA */

		free(vector_n);
		free(vector_ns);
		free(s);
		free(y);
		free(fn);
		free(jac);

		return (-1);
		}

	}       /* FIN FOR */

/* MENSAJE DE ESPERA */

esperar ();

/* COPIAR vector EN vector_ns */

for(i=0;i<(ptparametros->N);i++)
	{
	vector_n[i] = vector[i];
	}

/* LA PRIMERA MATRIZ DE ITERACION ES EL JACOBIANO DEL SISTEMA EN LA
   APROXIMACION INICIAL */

jacobiano(vector_n, ptparametros, jac);

/* LA SIGUIENTE APROXIMACION LA OBTENEMOS MEDIANTE EL METODO DE NEWTON */

i = newton (vector_n, vector_ns, ptparametros, jac);

if ( i == 0 ) /* NO SE PUDO CALCULAR LA PRIMERA APROXIMACION */
	{
	return (0);
	}

/* CALCULO DE s(0) INICIAL QUE ES LA DIFRENCIA ENTRE LAS DOS PRIMERAS
   APROXIMACIONES */

for(i=0;i<(ptparametros->N);i++)
	{
	s[i] = vector_ns[i]-vector_n[i];
	}

/* CALCULO DEL ERROR COMETIDO EN LA PRIMERA ITERACION */

norma(ptparametros->N, vector_n, vector_ns, &error);

error_broy[broyden_ite] = error;

++broyden_ite;

while ( (broyden_ite <= (ptparametros->ite)) && (error >= ptparametros->tol) )

	{       /* INICIO DE WHILE */

	/* CALCULO DEL VECTOR y */

	funcion(vector_ns, ptparametros, fn);

	funcion(vector_n, ptparametros, y);

	/* EL VALOR DEL SISTEMA EN vector_n LO MULTIPLICAMOS POR -1 Y
	   LUEGO LE SUMAMOS EL VALOR DEL SISTEMA EN vector_ns Y YA TENEMOS y */

	for(i=0;i<(ptparametros->N);i++)

		{
		y[i] *= (-1.);
		}

	for(i=0;i<(ptparametros->N);i++)

		{
		y[i] += fn[i];
		}

	/* CALCULAMOS LA MATRIZ DE ITERACION Y LA ALMACENAMOS EN jac */

	matriz_ite(jac, s, y, ptparametros->N);

	/* CALCULAMOS s */

	for(i=0;i<(ptparametros->N);i++)
		{
		fn[i] *= (-1.);
		}

	i = sis_lin(ptparametros->N, jac, s, fn);

	switch (i)
		{       /* PRINCIPIO SWITCH */

		case -1:        /* ERROR DE MEMORIA AL RESOLVER EL SISTEMA */

			{
			free(jac);
			free(vector_n);
			free(vector_ns);
			free(s);
			free(y);
			free(fn);

			return (-1);
			}

		case 0:         /* EL SISTEMA NO TIENE SOLUCION */

			{
			free(jac);
			free(vector_n);
			free(vector_ns);
			free(s);
			free(y);
			free(fn);

			return (0);
			}

		default:
			{
			break;
			}

		}       /* FIN SWITCH */

	/* COPIAMOS vector_ns EN vector_n */

	for(i=0;i<(ptparametros->N);i++)
		{
		vector_n[i] = vector_ns[i];
		}

	/* CALCULAMOS LA NUEVA APROXIMACION , RECORDAR QUE EL VALOR
	   AHORA ALMACENADO EN vector_n ES LA APROXIMACION OBTENIDA
	   EN LA ITERACION ANTERIOR */

	for(i=0;i<(ptparametros->N);i++)
		{
		vector_ns[i] += s[i];
		}

	/* CALCULAMOS EL ERROR COMETIDO EN ESTA ITERACION */

	norma(ptparametros->N, vector_n, vector_ns, &error);

	/* COPIAMOS EL ERROR COMETIDO EN error_broy */

	error_broy[broyden_ite] = error;

	++broyden_ite;
	}       /* FINAL DE WHILE */

/* LIBERAR LA MEMORIA ASIGNADA */

free(jac);
free(vector_n);

/* SE ALCANZO LA CONVERGENCIA */

if ( broyden_ite <= (ptparametros->ite) )

	{

	/* MUESTRA POR PANTALLA LAS SOLUCIONES OBTENIDAS */

	ver_solucion(ptparametros->N, vector_ns, ptparametros->pre, broyden_ite,
			BROYDEN, &error);

	/* GRABA EN DISCO LAS SOLUCIONES */

	salida_a_disco(ptparametros, vector_ns, broyden_ite, BROYDEN, 
			vector, error);

	clrscr ();

	free(vector_ns);
	free(s);
	free(y);
	free(fn);
	return (broyden_ite);

	}

free(vector_ns);
free(s);
free(y);
free(fn);

/* DEVUELVE EL VALOR -2 SI NO SE HA ALCANZADO LA CONVERGENCIA */

if ( broyden_ite > (ptparametros->ite ))
	{
	return (-2);
	}

}
