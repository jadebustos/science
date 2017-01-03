#include <graphics.h>
#include <dos.h>

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*----------------------------------------------------------------------------
			PRESENTACION EN MODO GRAFICO
----------------------------------------------------------------------------*/

main ()

{
int TSCR;

if ( inicializar_modo_grafico () != 0 )  /* INICIALIZAR MODO GRAFICO */

	{
	/* SELECCION DEL COLOR */

	setcolor (YELLOW);

	/* INSTALA TIPO DE LETRA DEL USUARIO */

	TSCR = installuserfont("tscr.chr");

	/* ATRIBUTOS DEL TEXTO EN MODO GRAFICO */

	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);

	/* TEXTO */

	outtextxy(30,60,"PRACTICAS DE CALCULO NUMERICO II.");

	/* SELECCION DEL COLOR */

	setcolor(LIGHTGREEN);

	/* TEXTO */

	outtextxy(60,130,"Grupo I");
	outtextxy(240,130,"Ordenador 15");
	outtextxy(60,200,"Jose Angel de Bustos Perez");

	/* SELECCION DEL COLOR */

	setcolor(LIGHTBLUE);

	/* ATRIBUTOS DEL TEXTO EN MODO GRAFICO */

	settextstyle(TSCR, HORIZ_DIR, 4);

	/* TEXTO */
	setcolor (LIGHTRED);
	outtextxy(60,340,"2 - 2 - 1996");

	sleep (7); /* PAUSA PARA MOSTRAR ROTULO DE PRESENTACION */

	fin_modo_grafico ();   /* RESTAURAR MODO TEXTO */
	}

else
	{

	/* PRESENTACION EN MODO TEXTO SI EL ADAPTADOR GRAFICO NO ES VGA */

	rotulo_texto ();
	}
}
