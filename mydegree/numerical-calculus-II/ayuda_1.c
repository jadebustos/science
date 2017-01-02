#include <conio.h>

/*----------------------------------------------------------------------------
	PRIMERA PAGINA DE LA AYUDA DEL MENU DE PETICION DE DATOS
----------------------------------------------------------------------------*/

void ayuda_1 (void)

{
/* ARRAYS CON EL TEXTO A IMPRIMIR */

char cifras[] = {
	"Cifras con las que el ordenador mostrara los resultados obtenidos."
	"\n\rSu rango oscila entre 1 y 16."
		};

char tolerancia[] = 	{
	"Error cometido, cuando se alcanze un error menor o igual parara  "
	"la ejecucion del programa."
			};

char numero_iteraciones[] = 	{
	"Numero maximo de iteraciones que se realizara para alcanzar la "
	"solucion al\n\rproblema propuesto."
				};

char X[] =	{
	"Coordenada x del final del canal."
		};

/* SELECCION DEL COLOR DEL TEXTO */

textcolor(WHITE);

/* POSICIONAMIENTO E IMPRESION DE LOS ARRAYS */

gotoxy(1,6);
	cprintf("%s", cifras);

gotoxy(1,11);
	cprintf("%s", tolerancia);

gotoxy(1,16);
	cprintf("%s", numero_iteraciones);

gotoxy(1,21);
	cprintf("%s", X);

/* IMPRESION DE ESC */

gotoxy(10,24);
	cprintf("Esc");

/* SELECCION DEL COLOR DEL TEXTO */

textcolor(LIGHTRED);

/* POSICIONAMIENTO E IMPRESION DE ROTULOS */

gotoxy(1,4);
	cprintf("'C' Cifras significativas:");

gotoxy(1,9);
	cprintf("'N' Tolerancia:");

gotoxy(1,14);
	cprintf("'N' Numero de iteraciones:");

gotoxy(1,19);
	cprintf("'X' Coordenada X:");

/* REEESTABLECER COLOR DE TEXTO NORMAL */

textcolor(LIGHTGRAY);
}
