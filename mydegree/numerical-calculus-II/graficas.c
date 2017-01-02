#include <math.h>
#include <graphics.h>
#include <stdlib.h>

/*--------------------------------------------------------------------------
  SE ENCARGA DE DIBUJAR LAS GRAFICAS, SI NO SE HA PODIDO INICIALIZAR
  EL MODO GRAFICO DEVUELVE 0 SI SE PUDO DEVUELVE 1
--------------------------------------------------------------------------*/

int hacer_graficas(int newton_ite, double *error_new,
		   int broyden_ite, double *error_broy)

{

void cal_coor(int numero, int x, int y, int a, int d,
		double unidad, double *puntos, int *coordenadas);

int i;  /* CONTADOR */

int *coordenadas;

/* ESCALA DEL EJE X PARA LA GRAFICA COMUN, SERA EL NUMERO MAYOR DE ITERACIONES */

int esc_x_ambas = 0;

double unidad = -1., /* UNIDAD EN EL EJE Y, SERA EL MAYOR ERROR COMETIDO */
       unidad_ambas = -1.; /* IGUAL QUE LA ANTERIOR PERO PARA LA GRAFICA COMUN */

/* DIBUJAR LOS EJES DE COORDENADAS DE LAS GRAFICAS */

i = dibujar_graficas ();

if (i == 0)
	{
	return (0);
	}

/* DETERMINAR unidad_ambas PARA LA GRAFICA COMUN */

for(i=0;i<newton_ite;i++)
	{
	if ( error_new[i] > unidad_ambas )
		unidad_ambas = error_new[i];
	}

for(i=0;i<broyden_ite;i++)
	{
	if ( error_broy[i] > unidad_ambas )
		unidad_ambas = error_broy[i];
	}

/* LA ESCALA DEL EJE X SERA EL NUMERO MAYOR DE ITERACIONES */

if (broyden_ite >= newton_ite )

	{
	esc_x_ambas = broyden_ite;
	}

else
	{
	esc_x_ambas = newton_ite;
	}

/* DIBUJAR LA GRAFICA DE ERRORES DEL METODO DE NEWTON */

/* ASIGNAR MEMORIA A COORDENADAS */

coordenadas = (int *)calloc(2*newton_ite,sizeof(int));

/* CALCULAR LA UNIDAD DEL EJE Y */

for(i=0;i<newton_ite;i++)
	{
	if ( error_new[i] > unidad )
		unidad = error_new[i];
	}

setcolor(RED);

/* DIBUJARLA EN SU GRAFICA */

cal_coor(newton_ite, 80, 200, 280, 20, unidad, error_new, coordenadas);

drawpoly(newton_ite, coordenadas);

/* DIBUJARLA EN LA GRAFICA COMUN */

cal_coor(esc_x_ambas, 80, 420, 560, 240, unidad_ambas, error_new, coordenadas);

drawpoly(newton_ite, coordenadas);


/* DIBUJAR LA GRAFICA DEL METODO DE BROYDEN */

/* ASIGNAR MEMORIA A COORDENADAS */

free(coordenadas);

coordenadas = (int *)calloc(2*broyden_ite,sizeof(int));

/* CALCULAR LA UNIDAD DEL EJE Y */

unidad = -1.;

for(i=0;i<broyden_ite;i++)
	{
	if ( error_broy[i] > unidad )
		unidad = error_broy[i];
	}

setcolor (BLUE);

/* DIBUJARLA EN SU GRAFICA */

cal_coor(broyden_ite, 320, 200, 560, 20, unidad, error_broy, coordenadas);

drawpoly(broyden_ite, coordenadas);

/* DIBUJARLA EN LA GRAFICA COMUN */

cal_coor(esc_x_ambas, 80, 420, 560, 240, unidad_ambas, error_broy, coordenadas);

drawpoly(broyden_ite, coordenadas);

free(coordenadas);

getch ();

/* FINALIZAR MODO GRAFICO */

fin_modo_grafico ();

return (1);
}

/*--------------------------------------------------------------------------
  CALCULA LAS COORDENADAS EN PANTALLA DE puntos, QUE TIENE numero ELEMENTOS,
  Y SE TOMA COMO UNIDAD EN EL EJE Y unidad, EL EJE Y Y EL X SE INTERSECCIONAN
  EN EL PUNTO (x,y) EL OTRO PUNTO QUE DEFINE EL EJE Y ES EL (c,d) Y EL QUE
  DEFINE EL EJE X ES (a,b) Y LAS ALMACENA EN COORDENADAS.
--------------------------------------------------------------------------*/

void cal_coor(int numero, int x, int y, int a, int d,
		double unidad, double *puntos, int *coordenadas)

{
int i;  /* CONTADOR */

int esc_x = 0; /* ESCALA DEL EJE X */

int j = 1;

/* CALCULAMOS LAS COORDENADAS DEL EJE X */

esc_x = (a-x)/numero;

for(i=0;i<2*numero;i+=2)
	{
	coordenadas[i] = x+(esc_x*(j++));
	}

/* CALCULAMOS LAS COORDENADAS DEL EJE Y */

j = 0;

for(i=0;i<2*numero;i+=2)
	{
	double tmp = 0.;
	tmp = y-(((y-d)*puntos[j++])/unidad);

	coordenadas[i+1] = (int) tmp;
	}

return;
}
