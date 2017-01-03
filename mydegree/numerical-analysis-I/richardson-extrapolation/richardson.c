#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */       
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

double fi(double punto, double paso);

int main (void)

{
double punto,
       paso,
       tol,
       error = 1.,
       exacto = .0,
       **triangulo;                        

int n = 0, 		/* CONTADOR */
    k = 0,  		/* CONTADOR */
    i = 0,		/* CONTADOR */
    precision = 6,	/* PRECISION CON LA QUE SE MOSTRARAN LOS CALCULOS */
    NMI = 256;  	/* NUMERO MAXIMO DE ITERACIONES QUE VAMOS A REALIZAR */

double funcion(double punto);
double d(double punto, double paso, int n, int k, double **triangulo);
double derivada(double punto);

/* PETICION DE DATOS */

printf("Introduce el punto: ");
scanf("%lf", &punto);

printf("Introduce el paso: ");
scanf("%lf", &paso);

printf("Introduce la tolerancia: ");
scanf("%lf", &tol);

printf("Introduce el numero maximo de iteraciones: ");
scanf("%d", &NMI);

printf("Introduce la precision con la que vamos a mostrar los calculos: ");
scanf("%d", &precision);

/* RESERVA DE MEMORIA */

triangulo = (double **)calloc(NMI, sizeof(double *));

for(i=0;i<NMI;i++)
	triangulo[i] = (double *)calloc(NMI, sizeof(double ));

/* CALCULO DE "D(0,0)" */

triangulo[0][0] = d(punto, paso, 0, 0, triangulo);

while (error > tol)

	{
	if ( (++n) == NMI )	/* NO SE ALCANZO LA TOLERANCIA EN EL NMI */
		{

		printf("\n\nNo se alcanzo la tolerancia en %d iteraciones.\n", NMI);

		exit (0);
		}

	for(k=0;k<=n;k++)
		triangulo[n][k] = d(punto, paso, n, k, triangulo);

	error = fabsl(triangulo[n][n]-triangulo[n-1][n-1]);

	printf("Error cometido en la aproximacion %d es %.*lf\n", n+1, precision, error);
	}

printf("\nEl valor aproximado en el punto %.*lf es %.*lf\n", precision, punto, precision, triangulo[n][n]);

exacto = derivada(punto);

printf("\nEl valor exacto en el punto %.*lf es %.*lf\n", precision, punto, precision, exacto);

return 0;
}

double d(double punto, double paso, int n, int k, double **triangulo)

{
double valor = .0;

if ( k == 0 )
	{
	valor = fi(punto, paso/(pow(2,n)));

	return (valor);
	}
else
	{
	double numerador = pow(4,k),
	       denominador = numerador-1;

	double fraccion1 = 1.,
	       fraccion2 = 1.;

	fraccion1 *= (numerador/denominador);
	fraccion2 /= denominador;

	valor = (fraccion1*(triangulo[n][k-1]))-(fraccion2*(triangulo[n-1][k-1]));

	return (valor);
	}

}

double funcion(double punto)

{
double valor = .0;

valor = sin(punto);

return (valor);
}

double derivada(double punto)

{
double valor = .0;

valor = cos(punto);

return (valor);
}

double fi(double punto, double paso)

{
double valor = .0;

valor = ((funcion(punto+paso))-(funcion(punto-paso)))/(2*paso);

return (valor);
}
