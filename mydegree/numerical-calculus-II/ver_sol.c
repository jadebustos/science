
/*-------------------------------------------------------------------------
	 FUNCION QUE MUESTRA LA SOLUCION ENCONTRADA AL PROBLEMA, QUE ESTA
	 ALMACENADA EN *vector_n, LA MUESTRA CON UNA PRECISION DADA POR
	 pre, MUESTRA EL NUMERO DE ITERACIONES REALIZADAS PARA ALCANZARLA,
	 ite, EL METODO POR EL QUE SE HA CALCULADO metodo, Y EL ERROR
	 COMETIDO *pterror.
-------------------------------------------------------------------------*/

void ver_solucion (int N, double *vector_n, int pre, int ite, int metodo,
			double *pterror)

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
	plan_sol(pagina, u_pagina, N, vector_n, pre, ite, metodo, pterror);

	tecla = leer_tecla ();

	/* DETERMINAR NUEVA PAGINA */

	pagina = navegar (p_pagina, u_pagina, pagina, tecla);

	}

while ( pagina != u_pagina+1 );
}
