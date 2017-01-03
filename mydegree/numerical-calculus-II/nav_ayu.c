
/*                                                                      */
/*                      (c) 1995 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*---------------------------------------------------------------------------
      FUNCION PARA MOVERSE POR LA AYUDA DEL MENU DE PETICION DE DATOS 
---------------------------------------------------------------------------*/

void nav_ayuda (void)

{
int short pagina = 1,	/* PAGINA ACTUAL */
	  p_pagina = 1, /* PRIMERA PAGINA */
	  u_pagina = 2; /* ULTIMA PAGINA */

char tecla = ' ';

do
	{
	if ( pagina == 1 )
		{
		plantilla (pagina, u_pagina);
		ayuda_1();
		tecla = leer_tecla ();
		}
	else
		{
		/* LA FUNCION NAVEGAR SI ESTAMOS EN LA ULTIMA PAGINA AL
		   PULSAR AV PAG DEVUELVE UNA PAG MAS PARA SABER CUANDO
		   TERMINA LA EJECUCION DE ESA FASE, AQUI LA AYUDA
		   TERMINA AL PULSAR ESC Y SE VUELVE AL MENU DE PETICION
		   DE DATOS */

		pagina = 2;

		plantilla (pagina, u_pagina);
		ayuda_2();

		tecla = leer_tecla ();
		}

	/* BUSQUEDA DE LA NUEVA PAGINA POR INDICACION DEL USUARIO */

	while ( tecla != 'i' && tecla != 'q' && tecla != 'g' &&
		tecla != 'o' && tecla != 27 )

		{
		tecla = leer_tecla ();
		}

	pagina = navegar(p_pagina, u_pagina, pagina, tecla);

	}

while ( tecla != 27 ); /* 27 CODIGO DECIMAL DE 'ESC' */

}
