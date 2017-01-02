/*--------------------------------------------------------------------------
  PLANTILLA DE LA PAGINA DE SELECCION DEL METODO A UTILIZAR PARA RESOLVER
  EL PROBLEMA, LA FUNCION DEVUELVE EL CODIGO DEL METODO QUE SE HA
  SELECCIONADO PARA RESOLVER EL PROBLEMA
--------------------------------------------------------------------------*/

#include <conio.h>

#define NEWTON '1'
#define BROYDEN '2'
#define AMBOS '3'

char plan_met(void)

{
int i;  /* CONTADOR */

char res;

clrscr ();      /* BORRAR PANTALLA */

for(i=1;i<4;i++)
	{
	textcolor(LIGHTRED);

	gotoxy(10,3+2*i);
	cprintf("%d",i);

	}

textcolor(WHITE);

gotoxy(12,5);
cprintf("- Metodo de Newton.");

gotoxy(12,7);
cprintf("- Metodo de Broyden.");

gotoxy(12,9);
cprintf("- Utilizar ambos metodos.");

gotoxy(8,17);
cprintf("Cuando se alcanze la convergencia, los resultados obtenidos se");

gotoxy(8,18);
cprintf("almacenaran en los ficheros NEWTON.SOL y BROYDEN.SOL dependiendo");

gotoxy(8,19);
cprintf("del metodo utilizado para resolverlos.");

gotoxy(8,21);
cprintf("Al resolver el problema con la opcion \"3\" al final se realizara");

gotoxy(8,22);
cprintf("una comparacion grafica de los errores cometidos con cada metodo.");

gotoxy(14,13);
cprintf("Selecciona el metodo que quieres utilizar: ");

/* RESTAURAR COLORES ORIGINALES DE TEXTO */

textbackground(BLACK);
textcolor(LIGHTGRAY);

res = leer_num();       /* LEER RESPUESTA */

return (res);

}
