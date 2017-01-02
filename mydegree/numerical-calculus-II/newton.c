#include <stdlib.h>
#include "struct.h"

#define NEWTON 1

/*--------------------------------------------------------------------------
	FUNCION QUE LLAMA A LA FUNCION QUE REALIZA UNA ITERACION
	DEL METODO DE NEWTON Y LA REALIZA MIENTRAS NO SE ALCANZE
	LA TOLERANCIA O NO SE SOBREPASE EL NUMERO MAXIMO DE
	ITERACIONES, AMBOS ESTABLECIDOS POR EL USUARIO.
	LA FUNCION DEVUELVE LOS SIGUIENTES CODIGOS:

	       -2 NO SE ALCANZO LA CONVERGENCIA DESPUES DEL
		   NUMERO MAXIMO DE ITERACIONES.

		SI SE ALCANZO LA CONVERGENCIA CON UN NUMERO
		DE ITERACIONES MENOR O IGUAL QUE EL ESTABLECIDO
		POR EL USUARIO, ENTONCES DEVUELVE EL NUMERO DE
		ITERACIONES CON EL QUE SE HA ALCANZADO LA CONVERGENCIA.

		0 EL SISTEMA PLANTEADO NO TIENE SOLUCION.

	       -1 ERROR EN LA ASIGNACION DE MEMORIA.
--------------------------------------------------------------------------*/

int hacer_newton (struct datos *ptparametros, double *vector,
		  double *error_new)

{

int i = 0.;        /* CONTADORES */

int newton_ite = 0;     /* NUMERO DE ITERACIONES REALIZADAS */

double error = 1000.;   /* ERROR COMETIDO EN CADA ITERACION */

double  **jac, /* JACOBIANO DEL SISTEMA EN UN PUNTO */
	*vector_n,     /* SE VA A GUARDAR EL VECTOR DE LA ITERACION n-ESIMA */
	*vector_ns;    /* SE VA A GUARDAR EL VECTOR DE LA ITERACION (n+1)-ESIMA*/

/* ASIGNACION DE MEMORIA PARA jac */

jac = (double **)calloc(ptparametros->N,sizeof(double *));

/* SI HAY ERROR EN LA ASIGNACION SAL FUERA */

if ( jac == NULL )
	{
	return (-1);
	}

for(i=0;i<(ptparametros->N);i++)
	{
	jac[i] = (double *)calloc(ptparametros->N,sizeof(double));

	/* SI HAY ERROR EN LA ASIGNACION SAL FUERA */

	if ( jac[i] == NULL )
		{
		free(jac);
		return (-1);
		}
	}

/* ASIGNACION DE MEMORIA PARA ESTOS PUNTEROS */

vector_n = (double *)calloc(ptparametros->N,sizeof(double ));

/* SI HUBO ERROR EN LA ASIGNACION DE MEMORIA SAL FUERA */

if ( vector_n == NULL )
	{
	/* LIBERA LA ZONA ASIGNADA A jac */

	free(jac);

	return(-1);
	}

vector_ns = (double *)calloc(ptparametros->N,sizeof(double ));

/* SI HUBO ERROR EN LA ASIGNACION DE MEMORIA SAL FUERA */

if ( vector_ns == NULL )
	{
	/* LIBERA LA ZONA ASIGNADA A jac */

	free(jac);

	return(-1);
	}

/* COPIAMOS EN vector_n EL VECTOR DE APROXIMACION INICIAL, YA QUE CON EL
   ES CON QUIEN VAMOS A EMPEZAR LOS CALCULOS */

for(i=0;i<(ptparametros->N);i++)
	{
	vector_n[i] = vector[i];
	}

esperar ();

while ( (newton_ite <= (ptparametros->ite)) &&
	(error >= (ptparametros->tol)) )

	{       /* COMIENZO WHILE */

	/* CALCULAMOS EL VALOR DEL JACOBIANO vector_n */

	jacobiano(vector_n, ptparametros, jac);

	i = newton(vector_n, vector_ns, ptparametros, jac);

	switch (i)

		{       /* INICIO SWITCH */

		case 0:

		/* NO SE PUDO CALCULAR LA NUEVA APROXIMACION DEBIDO A
		   QUE SE INTENTO RESOLVER UN SISTEMA QUE NO TIENE
		   SOLUCION */

			{
			/* LIBERA EL ESPACIO RESERVADO PARA LOS PUNTEROS */

			free(jac);
			free(vector_ns);
			free(vector_n);

			return(0);
			}

		case -1:

		/* ERROR DE ASIGNACION DE MEMORIA */

			{
			/* LIBERA MEMORIA */

			free(jac);
			free(vector_ns);
			free(vector_n);

			return (-1);
			}

		case -2:

		/* NO SE ALCANZA LA CONVERGENCIA EN EL NUMERO DE
		   ITERACIONES ESTABLECIDAS POR EL USUARIO */

			{
			/* LIBERA MEMORIA */

			free(jac);
			free(vector_ns);
			free(vector_n);

			return (-2);
			}

		}       /* FIN SWITCH */

	norma(ptparametros->N, vector_n, vector_ns, &error);

	/* COPIAMOS EL ERROR COMETIDO */

	error_new[newton_ite] = error;

	/* COPIAMOS LA NUEVA APROXIMACION vector_ns EN vector_n */

	for (i=0;i<(ptparametros->N);i++)

		{
		vector_n[i] = vector_ns[i];
		}

	++newton_ite;

	}       /* FINAL WHILE */

/* SI SE HAN SOBREPASADO EN NUMERO MAXIMO DE ITERACIONES ENTONCES NO
   SE HA ALCANZADO LA CONVERGENCIA */

if ( newton_ite > (ptparametros->ite) )
	{
	/* LIBERA EL ESPACIO RESERVADO PARA LOS PUNTEROS */

	free(jac);
	free(vector_ns);
	free(vector_n);

	return (0);
	}
else
	{
	/* LIBERA LA MEMORIA RESERVADA */

	free(jac);
	free(vector_ns);

	/* VER EN PANTALLA LAS SOLUCIONES */

	ver_solucion(ptparametros->N, vector_n, ptparametros->pre, 
		     newton_ite, NEWTON, &error);

	/* GUARDAR EN DISCO LOS RESULTADOS OBTENIDOS */

	salida_a_disco(ptparametros, vector_n, newton_ite, NEWTON, 
			vector, error);

	clrscr ();

	/* LIBERA LA MEMORIA RESERVADA PARA vector_n */

	free(vector_n);

	return (newton_ite);
	}

}

/*-------------------------------------------------------------------------
	FUNCION QUE REALIZA UNA ITERACION DEL METODO DE NEWTON,
	A PARTIR DE vector_n OBTIENE vector_ns.LA FUNCION DEVUELVE
	LOS SIGUIENTES CODIGOS:

		-1 ERROR DE MEMORIA.

		0 NO SE HA PODIDO CALCULAR vector_ns.

		1 SE HA PODIDO CALCULAR vector_ns.
--------------------------------------------------------------------------*/

int newton(double *vector_n, double *vector_ns, struct datos *ptparametros,
	   double **jac)

{
/* vector_ns SERA LA SOLUCION DEL SISTEMA Ax = b, DONDE A SERA EL JACOBIANO
   DEL SISTEMA EN EL PUNTO vector_n Y b SERA EL VECTOR OBTENIDO DE LA RESTAR
   EL VALOR DEL SISTEMA EN vector_n AL VECTOR OBTENIDO DE APLICAR EL JACOBIANO
   DEL SISTEMA EN vector_n EN vector_n */

int i; /* CONTADOR */

double *b;  /* VECTOR b DEL SISTEMA A RESOLVER */

/* ASIGNACION DE MEMORIA PARA b */

b = (double *)calloc(ptparametros->N,sizeof(double));

/* SI HAY ERROR EN LA ASIGNACION SAL FUERA */

if ( b == NULL)
	{
	return (-1);
	}

/* ALMACENAMOS EL VALOR DEL JACOBIANO EN vector_n APLICADO A vector_n
   EN b PARA POSTERIORMENTE RESTARLE EL VALOR DE LA FUNCION EN vector_n */

pro_mat_vec(jac, ptparametros->N, ptparametros->N, vector_n, ptparametros->N, b);

/* CALCULAMOS EL VALOR DE LA FUNCION EN vector_n Y LO ALMACENA EN vector_ns */

funcion(vector_n, ptparametros, vector_ns);

/* CALCULAMOS EL VECTOR b DEFINITIVO RESTANDOLE vector_ns */

for(i=0;i<(ptparametros->N);i++)
	{
	b[i] -= vector_ns[i];
	}

/* CACULAMOS LA NUEVA APROXIMACION Y LA ALMACENAMOS EN vector_ns */

i = sis_lin(ptparametros->N, jac, vector_ns, b);

switch (i)
	{       /* PRINCIPIO SWITCH */

	case -1:        /* ERROR EN LA ASIGNACION DE MEMORIA */
		{
		/* LIBERA LA MEMORIA ASIGNADA A b */

		free(b);

		return (-1);

		}

	case 0:         /* EL SISTEMA Ax=b NO SE PUEDE RESOLVER */
		{

		/* LIBERA LA MEMORIA RESERVADA A b */

		free(b);

		return (0);

		}

	case 1:         /* EL SISTEMA SE PUDO RESOLVER */
		{
		/* LIBERA LA MEMORIA RESERVADA A b */

		free(b);

		return (1);

		}

	}       /*  FIN SWITCH */

}
