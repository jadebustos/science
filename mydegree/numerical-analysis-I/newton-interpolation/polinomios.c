#include <stdlib.h>
#include <math.h>

#include "polinomios.h"
#include "memoria.h"

/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */                                                                            
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula el valor del polinomio dblPoli(de grado intGrado)*/
/* en el punto dblPunto, la funcion devuelve dicho valor.               */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

double dblEvaluarPolinomio(double *dblPoli, int intGrado, double dblPunto)

{
double 	dblRes =.0;		/* VALOR DEL POLINOMIO EN dblPunto */

int 	i = 0; 		/* CONTADOR */

for(i=0;i<=intGrado;i++)

	{	/* INICIO for */
	dblRes += dblPoli[i]*pow(dblPunto,i);
	}	/* FINAL for */

return dblRes;
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que multiplica el polinomio dblPoli1(de grado intGrado1) por */
/* el polinomio dblPoli2(de grado intGrado2) y lo almacena en           */
/* dblResultado.                                                        */
/*                                                                      */
/* La funcion supone que se ha reservado memoria para *dblResultado,    */
/* y que todos sus elementos estan inicializados a cero.                */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void MultPoli(double *dblPoli1, int intGrado1, double *dblPoli2, int intGrado2, double *dblResultado)

{
int	i,	/* CONTADOR */
	j;	/* CONTADOR */

for(i=0;i<=intGrado1;i++)

	{	/* INICIO PRIMER for */

	for(j=0;j<=intGrado2;j++)

		{	/* INICIO SEGUNDO for */

		dblResultado[i+j] += dblPoli1[i]*dblPoli2[j];

		}	/* FINAL SEGUNDO for */

	}	/* FINAL PRIMER for */

return;
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula la expresion de un polinomio dadas su raices.    */
/*                                                                      */
/* La funcion devuelve los codigos:					*/
/*                                                                      */
/*	-1 HUBO UN ERROR DE MEMORIA.					*/
/*	0 SE CALCULO CON EXITO						*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int intExpre(double *dblRaices, int intNumero, double *dblRes)

{
double 	*dblAux,
	*dblPolRaiz;

int	i;

/* SI SOLO HAY UNA RAIZ */

if ( intNumero == 1 )
	{
	dblRes[0] = -dblRaices[0];
	dblRes[1] = 1.;

	return (0);
	}

/* RESERVA DE MEMORIA */

dblPolRaiz = (double *)dblAsigMemVec(2);

if ( dblPolRaiz == NULL )
	{
	return (-1);
	}

dblAux = (double *)dblAsigMemVec(intNumero+1);

if ( dblAux == NULL )
	{
	free(dblPolRaiz);
	return (-1);
	}

/* INICIALIZACIONES */

dblRes[0] = -dblRaices[0];
dblRes[1] = dblPolRaiz[1] = 1.;

for(i=1;i<intNumero;i++)

	{	/* INICIO PRIMER for */
	
	int	j = 0;	/* CONTADOR */

	dblPolRaiz[0] = -dblRaices[i];

	MultPoli(dblPolRaiz, 1, dblRes, i, dblAux);

	for(j=0;j<=i+1;j++) /* COPIAMOS dblRes A dblAux */

		{	/* INICIO SEGUNDO for */

		dblRes[j] = dblAux[j];

		/* LA FUNCION MulPol ASUME QUE EL PUNTERO DONDE SE VA A
                   ALMACENAR EL PRODUCTO ESTA INICIALIZADO A CERO */

		dblAux[j] = .0;

		}	/* FINAL SEGUNDO for */

	}	/* FINAL PRIMER for */

/* LIBERAR MEMORIA */

free(dblAux);
free(dblPolRaiz);

return	(0);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula el valor m\'aximo del polinomio dblPoli          */
/* (de grado intGrado), en valor absoluto, en el intervalo [dblA, dblB] */
/* utilizando intN puntos en dicho intervalo. La funcion devuelve dicho */
/* valor.                                                               */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

double dblMaxPol(double *dblPoli, int intGrado, double dblA, double dblB,
		int intN)

{
double	dblResultado = .0, /* ALMACENAREMOS EL MAXIMO */
	dblX_i = dblA,	/* PUNTOS EN LOS QUE EVALUAREMOS EL POLINOMIO */	
	dblPX_i = .0,   /* VALOR DEL POLINOMIO EN dblX_i */
	dblPaso =(dblB-dblA)/intN; /* DISTANCIA ENTRE LOS PUNTOS */

while( dblX_i <= dblB )

	{	/* INICIO while */

	/* EVALUAMOS EL POLINOMIO EN EL PUNTO dblX_i */

	dblPX_i = fabs(dblEvaluarPolinomio(dblPoli, intGrado, dblX_i));

	/* SI EL VALOR ABSOLUTO ES MAYOR QUE EL ALMACENADO, GUARDALO */

	if ( dblPX_i > dblResultado )
		dblResultado = dblPX_i;
	
	/* SIGUIENTE PUNTO EN EL QUE VAMOS A EVALUAR EL POLINOMIO */

	dblX_i += dblPaso; 

	}	/* FINAL while */

return (dblResultado);
}
