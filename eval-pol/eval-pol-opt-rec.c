/*
  This software is licensed under GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
  (c) 2013 Jose Angel de Bustos Perez <jadebustos@gmail.com>
*/

/*
  The following are deliberately forbidden:
        - Attempt World domination
        - Using this software as compiling massive weapon
        - Translating into Klingon
        - Ask for /home nationalisms
        - Reverse spelling of this source code
*/

#include <stdio.h>
#include <stdlib.h>

#define ORDEN 7

double evaluar_polinomio(int pol[], int orden, double punto, int binomio);

int main (int argc, char *argv[]) { /* inicio funcion main */
	
	int a = 1,
	    b = 10,
	    indice, i,
	    num_puntos;

	double h,
		   punto = (double)a,
		   valor;

	int polinomio[ORDEN] = {1,-2,3,4,5,-3,2};

	if ( argc != 2 ) {
		printf("Es necesario introducir el numero de puntos a evaluar como argumento.\n");
		exit (0);
	}

	num_puntos = atoi(argv[1]);

	h = (double)(b-a)/(double)(num_puntos - 1);

	for(indice=0;indice<num_puntos;++indice) { /* inicio bucle for - indice */
		valor = evaluar_polinomio(polinomio,(int)ORDEN-1,punto,0); 
		punto += h;
	} /* final bucle for - indice */

	return 0;

} /* final funcion main */

/* funcion recursiva que calcula el valor de un polinomio en un punto */

double evaluar_polinomio(int pol[], int orden, double punto, int binomio) { /* inicio funcion evaluar_polinomio */
	if ( binomio == orden - 1 )
		return pol[binomio]+pol[binomio+1]*punto;
	return pol[binomio] + punto * evaluar_polinomio(pol,orden,punto,binomio+1);
} /* final funcion evaluar_polinomio */
