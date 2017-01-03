#include <stdlib.h>
#include <math.h>

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*---------------------------------------------------------------------------
  FUNCION QUE CALCULA LAS MATRICES DE ITERACION DEL METODO DE BROYDEN,
  DEVUELVE LOS SIGUIENTES CODIGOS.

        -1 ERROR EN LA ASIGNACION DE MEMORIA.

         1 SE PUDO CALCULAR CON EXITO.
---------------------------------------------------------------------------*/

int matriz_ite(double **jac, double *s, double *y, int N)

{
int i,j;  /* CONTADORES */

/* PRODUCTO ESCALAR DEL VECTOR s POR SI MISMO */

double pro_es = 0.;

/* VECTOR QUE SERA EL RESULTADO DE RESTAR EL VECTOR y AL VECTOR OBTENIDO AL
   MULTIPLICAR LA MATRIZ DE ITERACION jac, QUE NO TIENE POR QUE SER EL
   JACOBIANO A EXCEPCION DE LA PRIMERA ITERACION, POR EL VECTOR s */

double *vec;

/* MATRIZ AUXILIAR */

double **aux;

/* ASIGNACION DE MEMORIA PARA vec */

vec = (double *)calloc(N,sizeof(double));

/* DEVUELVE -1 SI HAY ERROR EN LA ASIGNACION */

if ( vec == NULL )
        {
        return (-1);
        }

/* ASIGNACION DE MEMORIA PARA aux */

aux = (double **)calloc(N,sizeof(double *));

/* DEVUELVE -1 SI HAY ERROR EN LA ASIGNACION */

if ( aux == NULL )
        {
        /* LIBERA MEMORIA */

        free(vec);

        return (-1);
        }

for(i=0;i<N;i++)

        {       /* INICIO FOR i */

	aux[i] = (double *)calloc(N,sizeof(double ));

	/* DEVUELVE -1 SI HAY ERROR EN LA ASIGNACION */

	if ( aux[i] == NULL )
		{
		/* LIBERA MEMORIA */

		free(vec);
		free(aux);

		return (-1);
		}

	}               /* FIN FOR i */

/* MULTIPLICAMOS LA MATRIZ DE ITERACION jac POR EL VECTOR s Y LO
   ALMACENAMOS EN vec */

pro_mat_vec(jac, N, N, s, N, vec);

/* MULTIPLICAMOS TODOS SUS MIEMBROS POR -1 */

for(i=0;i<N;i++)
        {
        vec[i] *= (-1.);
        }

/* LE SUMAMOS EL VECTOR y */

for(i=0;i<N;i++)
        {
        vec[i] += y[i];
        }

/* CALCULAMOS LA MATRIZ QUE RESULTA DE MULTIPLICAR EL VECTOR COLUMNA vec
   POR EL VECTOR FILA s Y LO ALMACENAMOS EN aux */

vectcol_vectfil(N, vec, s, aux);

/* DIVIDIMOS TODOS LOS TERMINOS DE aux POR EL PRODUCTO ESCALAR DEL VECTOR
   s POR SI MISMO */

for(i=0;i<N;i++)
        {
        pro_es += pow(s[i],2);
        }

for(i=0;i<N;i++)
        {
        for(j=0;j<N;j++)
                {
                aux[i][j] /= pro_es;
                }
        }

/* SUMAMOS LA MATRIZ aux A LA MATRIZ DE ITERACION jac */

for(i=0;i<N;i++)
        {
        for(j=0;j<N;j++)
                {
                jac[i][j] += aux[i][j];
                }
        }


/* LIBERAMOS LA MEMORIA UTILIZADA EN aux Y vec */

free(aux);
free(vec);

return (1);
}
