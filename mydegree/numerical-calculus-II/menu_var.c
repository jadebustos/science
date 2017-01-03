#include <conio.h>

/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

void menu_variables (int N, double *vector, int pre)

{
int short pagina = 1,                   /* PAGINA ACTUAL */
	  p_pagina = 1,                 /* PRIMERA PAGINA */
	  u_pagina = det_pag(N);        /* ULTIMA PAGINA */

char tecla = ' ';

/* SE EJECUTARA EL BUCLE MIENTRAS pagina SEA DISTINTO DE u_pagina+1
   EN ESTE CASO SE PASARA A LA EJECUCION DE LA SIGUIENTE PARTE, ELECCION
   DEL METODO */


do
	{
	plan_pet(pagina,u_pagina, N, vector, pre);

	/* ESTABLECER NUEVOS COLORES TEXTO */

	textcolor(LIGHTGREEN);
	textbackground(BLUE);

	/* IMPRIMIR SE¥AL EN PRIMERA VARIABLE DE LA PAGINA ACTIVA */

	gotoxy(5,2);
		cprintf("û");

	tecla = leer_tecla ();

	/* FUNCION QUE SE ENCARGA DE MOVERSE POR LOS CAMPOS */

	if ( tecla == 'p' || tecla == 'k' || tecla == 'm' || tecla == 'h')

		tecla = intr_var(N, pagina, u_pagina, tecla, vector, pre);

	/* DETERMINAR NUEVA PAGINA */

	pagina = navegar (p_pagina, u_pagina, pagina, tecla);

	/* COLORES ORIGINALES */

	textcolor(LIGHTGRAY);
	textbackground(BLACK);

	}

while ( pagina != u_pagina+1 );
}
