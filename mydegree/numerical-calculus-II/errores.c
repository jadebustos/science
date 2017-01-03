#include <conio.h>

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*--------------------------------------------------------------------------
			  ERRORES DE MEMORIA
--------------------------------------------------------------------------*/

void errores_mem (void)

{
clrscr();

textcolor(WHITE);

gotoxy(8,2);
cprintf("Hubo un error en la asignacion de memoria.");

gotoxy(8,4);
cprintf("Libera memoria o intentalo con valores mas pequenyos.");

textcolor(LIGHTGRAY);
}

/*-------------------------------------------------------------------------
	  SE INTENTA RESOLVER UN SISTEMA QUE NO TIENE SOLUCION
-------------------------------------------------------------------------*/

void error_sis (void)

{
clrscr();

textcolor(WHITE);

gotoxy(8,2);
cprintf("No se pudo calcular la siguiente aproximacion, debido a que ");

gotoxy(8,3);
cprintf("el sistema planteado no tiene solucion.");

textcolor(LIGHTGRAY);

return;
}

/*---------------------------------------------------------------------------
 NO SE HA ALCANZADO LA CONVERGENCIA DESPUES DEL NUMERO MAXIMO DE ITERACIONES
---------------------------------------------------------------------------*/

void error_convergencia(int ite)

{
clrscr ();

textcolor(WHITE);

gotoxy(8,2);
cprintf("No se alcanzo la convergencia despues de:");

gotoxy(8,4);
cprintf("%d iteraciones.", ite);

textcolor(LIGHTGRAY);

return;
}

/*---------------------------------------------------------------------------
     NO SE PUDO INICIALIZAR EL MODO GRAFICO PARA DIBUJAR LAS GRAFICAS
---------------------------------------------------------------------------*/

void error_graficas()

{
clrscr ();

textcolor(WHITE);

gotoxy(8,2);
cprintf("No se pudo inicializar el modo VGA para dibujar las graficas.");
gotoxy(8,4);
cprintf("Asegurese de que el fichero EGAVGA.BGI esta en el directorio.");

textcolor(LIGHTGRAY);

return;
}

/*--------------------------------------------------------------------------
		ESPERA PARA CONTINUAR CON EL OTRO METODO
--------------------------------------------------------------------------*/

void continuar ()

{
textcolor(WHITE);

gotoxy(8,10);
cprintf("Pulse una tecla para continuar con el metodo de Broyden.");

getch ();

textcolor(LIGHTGRAY);

return;
}
