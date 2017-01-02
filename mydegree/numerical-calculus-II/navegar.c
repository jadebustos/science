/*--------------------------------------------------------------------------
	ESTA FUNCION INDICA LA PAGINA A MOSTRAR EN PANTALLA, DONDE
	p_pagina, ES LA PRIMERA PAGINA, u_pagina ES LA ULTIMA PAGINA,
	pagina ES LA PAGINA EN LA QUE ESTAMOS ACTUALMENTE Y tecla ES LA
	PULSACION DE TECLADO QUE INDICA LA SIGUIENTE PAGINA A
	IMPRIMIR EN PANTALLA 
--------------------------------------------------------------------------*/

int navegar (int short p_pagina, int short u_pagina,
	     int short pagina, char tecla)

{

/* SI TENEMOS QUE IR A LA PRIMERA PAGINA */

if ( tecla == 'g' )
	{
	pagina = p_pagina;
	return (pagina);
	}

/* SI TENEMOS QUE IR A LA ULTIMA PAGINA */

if ( tecla == 'o' )
	{
	pagina = u_pagina;
	return (pagina);
	}

/* SI NO ESTAMOS NI EN LA PRIMERA PAGINA */

	/* OBS: SI ESTAMOS EN LA ULTIMA PAGINA Y AVANZAMOS PAGINA, EL
	   VALOR DE pagina ES 4 ENTONCES EL PROGRAMA SABE QUE SE HA
	   TERMINADO ESTA FASE, Y PASA A LA SIGUIENTE FASE */

if ( pagina != p_pagina )
	{
	switch ( tecla )
		{	/* INICIO SWITCH */

		case 'i':	/* RETROCESO DE PAGINA */
			{
			--pagina;
			break;
			}

		case 'q':	/* AVANCE DE PAGINA */
			{
			++pagina;
			break;
			}

		}       /* FIN SWITCH */

	return (pagina);
	}

/* SI ESTAMOS EN LA PRIMERA PAGINA */

if ( pagina == p_pagina )
	{
	switch ( tecla )
		{	/* INICIO SWITCH */

		case 'q':	/* AVANCE DE PAGINA */
			{
			++pagina;
			break;
			}

		case 'i':	/* RETROCESO DE PAGINA */
			{
			break;
			}
		}       /* FIN SWITCH */

	return (pagina);
	}
}
