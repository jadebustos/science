#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <stdlib.h>

/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */                                                                            
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

main ()

{

/* VARIABLES PARA LA INICIALIZACION DEL MODO GRAFICO */

int adaptador_grafico = VGA, modo_grafico = VGAHI;

/* VARIABLE PARA CONTROLAR EL NUMERO DE EXPERIMENTOS QUE SE
				REALIZAN SIMULTANEAMENTE */

int i;
int j; /* CONTADOR */

char res;

unsigned long int expe = 1; /* NUMERO DE EXPERIMENTOS QUE SE REALIZA DE UNA PASADA */
unsigned long int n_exp = 0; /* NUMERO DE EXPERIMENTOS REALIZADOS */

/* VAMOS A ALMACENAR LAS VECES QUE SALGA EL NUMERO n EN
		 sum_num[n-2] DONDE n VARIA DESDE 2 HASTA 12 */

unsigned long int sum_num[11]; 

/* INICIALIZACION A CERO DE sum_num */

for(j=0;j<11;++j)
	sum_num[j] = 0;

/* INICIALIZACION PARA LA GENERACION DE NUMEROS ALEATORIOS */

srand( (unsigned)time(NULL) );

informacion();

res = leer_tecla();

if ( res == 'F' || res == 'R' || res == 'G' )
	exit(0);

initgraph(&adaptador_grafico,&modo_grafico,""); /* INICIALIZAR MODO
						   GRAFICO VGA */

dibujar_grafica(); /* DIBUJA LA GRAFICA, EJES DE COORDENADAS */

do
	{
	n_exp+=expe; /* NUMERO DE EXPERIMENTOS REALIZADOS */

	borrar ();  /* BORRAR GRAFICA ANTERIOR */

	/* BUCLE QUE SIMULA EL LANZAMIENTO DE LOS DADOS */

	for(i=0;i<expe;++i)
		{
		dados(sum_num);
		}

	/* GRAFICA DE LA PROBABILIDAD OBTENIDA EN EL LANZAMIENTO */

	grafica_exp(sum_num, n_exp);

	}

while ( texto(&expe, n_exp, sum_num) == 'C' );

/* FIN MODO GRAFICO */

cleardevice ();
restorecrtmode ();

}
