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
		valor = (punto*polinomio[(int)ORDEN-1])+polinomio[(int)ORDEN-2];
		for(i=(int)ORDEN-3;i>=0;i--) { /* inicio bucle for - i */
			valor *= punto;			
			valor += polinomio[i];			
		} /* final bucle for - i */
		punto += h;
	} /* final bucle for - indice */

	return 0;

} /* final funcion main */
