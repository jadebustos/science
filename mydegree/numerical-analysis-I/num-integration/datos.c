#include <stdio.h>

#include "datos.h"

#define BIEN      0
#define ERR_FICH 1 /* ERROR AL ABRIR UN FICHERO */

/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* Funcion que pide los datos necesarios para comenzar la integracion.  */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void PeticionDatos(DatosIntgr *ptstrDatos)

{

printf("Introduce el limite inferior de integracion: ");
scanf("%lf", &(ptstrDatos->dblInicio));

printf("Introduce el limite superior de integracion: ");
scanf("%lf", &(ptstrDatos->dblFinal));

printf("Introduce el numero de subintervalos a utilizar: ");
scanf("%d", &(ptstrDatos->intNumIntervalos));

if ( (ptstrDatos->intNumIntervalos) <= 0 )
	ptstrDatos->intNumIntervalos = 1;

/* INICIALIZACIONES */

ptstrDatos->dblResulT  = .0;
ptstrDatos->dblResulS  = .0;
ptstrDatos->dblResul38 = .0;
ptstrDatos->dblErrorT  = .0;
ptstrDatos->dblErrorS  = .0;
ptstrDatos->dblError38 = .0;

return;
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* Funcion que almacena los resultados obtenidos con los tres metodos.  */
/*                                                                      */
/* La funcion devuelve los siguientes codigos:                          */
/*									*/
/*	0 NO HUBO NINGUN ERROR						*/
/*	1 HUBO UN ERROR AL ABRIR ALGUN FICHERO				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int intAlmacenarResultados(DatosIntgr *ptstrDatos)

{
FILE	*fichero;

/* ALMACENAMOS LOS DATOS DE LA INTEGRACION DEL SENO */

fichero = fopen(ptstrDatos->ptNomFich, "a");

if ( fichero == NULL )
	return (ERR_FICH);	/* FIN */

fprintf(fichero, "Limite Inferior: %lf\n", ptstrDatos->dblInicio);
fprintf(fichero, "Limite Superior: %lf\n", ptstrDatos->dblFinal);
fprintf(fichero, "Se han utilizado %d subintervalos.\n\n", ptstrDatos->intNumIntervalos);

fprintf(fichero, "Resultados obtenidos con la regla del trapecio:\n\n");
fprintf(fichero, "\tResultado: %.15lf\tError: %.10e\n\n", ptstrDatos->dblResulT, 
		 ptstrDatos->dblErrorT);

fprintf(fichero, "Resultados obtenidos con le regla de Simpson:\n\n");
fprintf(fichero, "\tResultado: %.15lf\tError: %.10e\n\n", ptstrDatos->dblResulS,
		  ptstrDatos->dblErrorS);

fprintf(fichero, "Resultado obrenidos con la regla de los 3/8:\n\n");
fprintf(fichero, "\tResultado: %.15lf\tError: %.10e\n", ptstrDatos->dblResul38,
		  (ptstrDatos->dblError38));
fprintf(fichero, "----------------------------------------------------------------\n");

fclose(fichero);

return (BIEN);
}
