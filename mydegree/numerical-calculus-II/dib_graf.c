#include <graphics.h>

/*--------------------------------------------------------------------------
  DIBUJA LOS EJES DE COORDENADAS DE LAS GRAFICAS, Y DEVUELVE EL VALOR 1
  SI SE HA PODIDO INICIALIZAR EL MODO GRAFICO O CERO SI NO SE HA PODIDO
--------------------------------------------------------------------------*/

int dibujar_graficas(void)

{
int i;

i = inicializar_modo_grafico();

if ( i == 0 )	/* NO SE PUDO INICIALIZA EL MODO GRAFICO */
	return (0);

/* GRAFICA DONDE SE VAN A REPRESENTAR LOS ERRORES DEL METODO DE NEWTON */

setcolor(WHITE);

line(80,20,80,220);	/* EJE X */
line(60,200,280,200);   /* EJE Y */

/* GRAFICA DONDE SE VAN A REPRESENTAR LOS ERRORES DEL METODO DE BROYDEN */

line(320,20,320,220);	/* EJE X */
line(300,200,560,200);	/* EJE Y */

/* GRAFICA DONDE VAMOS A SUPERPONER LAS DOS ANTERIORES */

line(80,240,80,440);	/* EJE X */
line(60,420,560,420);	/* EJE Y */

/* IMPRESION DE ROTULOS */

setcolor(RED);
outtextxy(125,3,"METODO DE NEWTON");

setcolor(BLUE);
outtextxy(365,3,"METODO DE BROYDEN");

return (1);
}
