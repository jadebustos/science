#include <stdlib.h>
#include <math.h>

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*--------------------------------------------------------------------------
	  CALCULA LA DISTANCIA ENTRE DOS APROXIMACIONES SUCESIVAS
	  UTILIZANDO LA NORMA INFINITO, DONDE *punto ES EL VECTOR
	  n-ESIMO DE LA SUCESION Y *punto_s ES EL VECTOR
	  (n-1)-ESIMO DE LA SUCESION Y LA GUARDA EN *ptresultado
--------------------------------------------------------------------------*/

void norma(int N, double *punto, double *punto_s,double *ptresultado)

{
int i;	/* CONTADOR */

double *aux;

/* INICIALIZAMOS EL VALOR DE *ptresultado */

*ptresultado = 0.;

/* RESERVA DE MEMORIA */

aux = (double *)calloc(N,sizeof(double));

/* COPIAMOS LA DIFERENCIA, EN VALOR ABSOLUTO, COORDENADA A COORDENADA EN aux */

for (i=0;i<N;i++)
	{
	aux[i] = fabs(punto[i]-punto_s[i]);
	}

/* COPIAMOS EL MAXIMO DE ESE VALOR EN resultado */

for (i=0;i<N;i++)
	{
	/* SI EL VALOR DE LA COORDENADA i-ESIMA ES MENOR QUE RESULTADO,
	   ENTONCES CONTINUA LA EJECUCION DEL BUCLE, SI NO ES ASI ENTONCES
	   COPIA ESE VALOR EN RESULTADO Y SIGUE CON LA EJECUCION DEL BUCLE */

	if (aux[i] < *ptresultado)
		continue;

	*ptresultado = aux[i];
	}

return ;
}
