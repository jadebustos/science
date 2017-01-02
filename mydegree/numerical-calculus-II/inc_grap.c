#include <graphics.h>

/*----------------------------------------------------------------------
		    INICIALIZACION DEL MODO GRAFICO VGA
		    DEVUELVE 1 SI NO HAY PROBLEMAS Y 0
		    SI NO SE HA PODIDO INICIALIZAR EL 
                    MODO VGA O NO ESTA INSTALADO
-----------------------------------------------------------------------*/

int inicializar_modo_grafico ( void )

{
int Adaptador_Grafico, /* ADAPTADOR GRAFICO INSTALADO */
    Modo_Grafico;      /* MODO GRAFICO */

/* DETECCION DEL ADAPTADOR Y MODO GRAFICOS DEL SISTEMA */

detectgraph(&Adaptador_Grafico,&Modo_Grafico);

if ( graphresult () != 0 )
	{
	return (0); /* ERROR EN LA DETECCION DEL HARDWARE GRAFICO, LA
		       PRESENTACION SE REALIZARA EN MODO TEXTO */
	}
/* SI EL ADAPTADOR ES UN VGA INICIALIZA EL MODO GRAFICO, EN CASO CONTRARIO
   SE REALIZARA LA PRESENTACION EN MODO TEXTO */

if ( Adaptador_Grafico == VGA )
	{
	initgraph(&Adaptador_Grafico,&Modo_Grafico,"");

		if ( graphresult () != 0 )
			{
			return (0); /* NO ESTA EL CONTROLADOR GRAFICO
					egavga.bgi, LA PRESENTACION SE
					REALIZARA EN MODO TEXTO */
			}
	return (1); /* SALIDA CON EXITO */
	}

else
	return (0); /* SALIDA SIN EXITO */
}
