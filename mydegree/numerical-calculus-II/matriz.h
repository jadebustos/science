#include <stdlib.h>

/*--------------------------------------------------------------------------
	FUNCION QUE REALIZA EL PRODUCTO DE LA MATRIZ a POR EL VECTOR
	b Y LO ALMACENA EN res, SIENDO fil_a Y fil_b SON LAS FILAS DE
	LAS MATRICES a Y b RESPECTIVAMENTE, col_a COLUMNAS DE a.

	LA FUNCION DEVUELVE LOS SIGUIENTES CODIGOS:

		1 - SE MULTIPLICARON LAS MATRICES.
		2 - LAS MATRICES NO SE PUEDEN MULTIPLICAR.

--------------------------------------------------------------------------*/

int pro_mat_vec(double **a, int fil_a, int col_a,
	    double *b, int fil_b, double *res)

{

int i,k; /* CONTADORES */

/* SI EL NUMERO DE COLUMNAS DE a ES DISTINTO DEL NUMERO
   DE FILAS DE b NO SE PUEDEN MULTIPLICAR LAS MATRICES,
   ENTONCES LA FUNCION DEVUELVE EL VALOR 0 */

if ( col_a != fil_b )
	return (0); /* NO SE PUEDEN MULTIPLAR LAS MATRICES */

/* INICIALIZAMOS A 0 EL ARRAY RES */

for (i=0;i<fil_a;i++)
	{
	res[i] = 0.;
	}

/* MULTIPLICACION DE LAS DOS MATRICES */

for (i=0;i<fil_a;i++)   /* VARIA LAS FILAS DE res */

	{               /* INICIO FOR i */

	/* ESTE BUCLE FOR VARIA EL INDICE DE a Y b */

	for (k=0;k<col_a;k++)

		{       /* INICIO FOR k */

		res [i] += a[i][k]*b[k];

		}       /* FINAL FOR k */


	}               /* FINAL FOR i */

return (1);
}

/*--------------------------------------------------------------------------
	ESTA FUNCION DEJA A CERO TODOS LOS ELEMENTOS POR DEBAJO
	DE LA DIAGONAL DE LA MATRIZ m, LOS CODIGOS QUE DEVUELVE
	SON LOS SIGUIENTES:

	       -1 OCURRIO ALGUN ERROR DE MEMORIA.

		0 SI ALGUN PIVOTE SE HACE CERO, CON LO CUAL NO HACE
		  NINGUNA MODIFICACION A LA MATRIZ, SI EL PIVOTE QUE
		  SE HACE CERO ES EL ULTIMO NO LO TIENE EN CUENTA,
		  PUES NO TIENE QUE DIVIDIR POR EL, SI LA MATRIZ ES
		  CUADRADA NINGUN PIVOTE HA DE SER CERO.

		1 SI LA TRIANGULA CORRECTAMENTE.
--------------------------------------------------------------------------*/

int trian_inf(int filas, int col, double **m)


{
int i,j,k;        /* CONTADORES */

double **matriz;

/* ASIGNACION DE MEMORIA PARA matriz */

matriz = (double **)calloc(filas,sizeof(double *));

/* SI HUBO ERROR EN LA ASIGNACION DEVUELVE -1 */

if ( matriz == NULL )
	return (-1);

for(i=0;i<filas;i++)

	{
	matriz[i] = (double *)calloc(col,sizeof(double));

	/* SI HUBO ERROR EN LA ASIGNACION DEVUELVE -1 */

	if (matriz[i] == NULL )
		return(-1);

	/* COPIAR LA MATRIZ m EN matriz */

	for(j=0;j<col;j++)

		{
		matriz[i][j] = m[i][j];
		}
	}

/* LA HACEMOS TRIANGULAR INFERIOR */

for (j=0;j<filas-1;j++)  /* INDICA LA COLUMNA EN LA QUE VAMOS A HACER CEROS */

	{       /* INICIO FOR j */

	/* SI ALGUN PIVOTE ES CERO NO CONTINUA */

	if ( matriz[j][j] == 0 )
		{
		/* LIBERA EL ESPACIO RESERVADO PARA matriz */

		free(matriz);
		
		return (0);
		}

	/* FILA EN LA QUE EMPEZAMOS A HACER CEROS */

	for(i=j+1;i<filas;i++)

		{               /* INICIO FOR i */

		/* RECORRE LOS ELEMENTOS DE LA FILA i-esima */

		/* SI EL ELEMENTO QUE VAMOS A HACER CERO ES CERO CONTINUA */

		if (matriz[i][j] == 0 )
			continue;

		for(k=col-1;k>=j;k--)

			{       /* FINAL FOR k */

			matriz[i][k] -= (matriz[i][j]/matriz[j][j])*
				matriz[j][k];

			}       /* FINAL FOR k */

		}               /* FINAL FOR i */

	}       /* FINAL FOR j */

/* SI El ULTIMO PIVOTE ES CERO ENTONCES DEVUELVE CERO */

if ( matriz[filas-1][filas-1] == 0. )
	{
	/* LIBERA EL ESPACIO RESERVADO PARA matriz */

	free(matriz);
	return (0);
	}

/* COPIAMOS matriz EN m */

for(i=1;i<filas;i++)
	{
	/* LA PRIMERA FILA, FILA 0, NO LA COPIAMOS PUESTO QUE NO HA VARIADO */

	for(j=0;j<col;j++)

		{
		m[i][j] = matriz[i][j];
		}
	}

/* LIBERA EL ESPACIO RESERVADO PARA matriz */

free(matriz);

return(1);
}

/*--------------------------------------------------------------------------
  RESUELVE UN SISTEMA DE ECUACIONES LINEAL, POR ELIMINACION GAUSSIANA,
  DEL TIPO Ax = b, DONDE A ES UNA MATRIZ DE ORDEN n, x ES UN VECTOR
  DE DIMENSION n DONDE SE VAN A GUARDAR LAS SOLUCIONES Y b ES EL VECTOR
  DE LOS TERMINOS INDEPENDIENTES, DEVUELVE LOS CODIGOS:

	-1 ERROR DE MEMORIA.

	 0 NO SE ENCUENTRA SOLUCION DEBIDO A QUE ALGUN PIVOTE ES CERO.

	 1 SE RESOLVIO CON EXITO.
--------------------------------------------------------------------------*/

int sis_lin(int n, double **A, double *x, double *b)

{
int i,j;        /* CONTADORES */

int res;

double **Ab;    /* MATRIZ CON LOS ELEMENTOS DE A Y DE b */

double sumatorio;

/* ASIGNACION DE MEMORIA A Ab */

Ab = (double **)calloc(n,sizeof(double *));

/* SI HAY ERROR DE MEMORIA DEVUELVE -1 */

if ( Ab == NULL )
	return (-1);

for(i=0;i<n;i++)
	{
	Ab[i] = (double *)calloc(n+1,sizeof(double));

	/* SI HAY ERROR DE MEMORIA DEVUELVE -1 */

	if ( Ab[i] == NULL)
		return (-1);

	}

/* COPIAR EN LA PRIMERA PARTE DE Ab LA MATRIZ A */

for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		{
		Ab[i][j] = A[i][j];
		}

	/* COPIAR EN Ab LOS COEFICIENTES DE b */

	Ab[i][n] = b[i];
	}

/* HACER TRIANGULAR INFERIOR LA MATRIZ Ab */

res = trian_inf(n, n+1, Ab);

switch ( res )

	{       /* INICIO SWITCH */

	case -1:
		{
		/* LIBERA EL ESPACIO RESERVADO PARA Ab */

		free(Ab);
		return (-1);

		}

	case 0:

		{
		/* LIBERA EL ESPACIO RESERVADO PARA Ab */

		free(Ab);
		return(0);

		}

	default:
		{
		break;
		}

	}      /* FIN SWITCH */

/* CALCULO DE LAS SOLUCIONES */

x[n-1] = Ab[n-1][n]/Ab[n-1][n-1];

for(i=n-2;i>=0;i--)
	{       /* INICIO FOR i */

	sumatorio = 0.;
	for(j=i+1;j<n;j++)

		{       /* INICIO FOR j */

		sumatorio += Ab[i][j]*x[j];

		}       /* FINAL FOR j */

	x[i] = (Ab[i][n]-sumatorio)/Ab[i][i];

	}       /* FINAL FOR i */

/* LIBERA EL ESPACIO RESERVADO PARA Ab */

free(Ab);

return (1);
}

/*--------------------------------------------------------------------------
  FUNCION QUE CALCULA LA MATRIZ QUE RESULTA DE MULTIPLICAR EL VECTOR DE n
  FILAS a POR EL VECTOR DE n COLUMNAS b Y LA ALMACENA EN matriz DE ORDEN
  n POR n
--------------------------------------------------------------------------*/

void vectcol_vectfil(int n, double *a, double *b, double **matriz)

{
int i,j;        /* CONTADORES */

for(i=0;i<n;i++)                /* CONTROLA LAS FILAS */

	{
	for(j=0;j<n;j++)        /* CONTROLA LAS COLUMNAS */

		{
		matriz[i][j] = a[i]*b[j];
		}
	}

return;
}
