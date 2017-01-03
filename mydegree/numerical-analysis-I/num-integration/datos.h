/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* Estructura que contiene los datos necesarios para integrar una       */
/* funcion.                                                             */
/*	                                                                */
/*	dblInicio        -> Limite inferior de integracion.             */      
/*	dblFinal         -> Limite superior de integracion.             */
/*	dblResulT        -> Resultado de la integracion con Trapecio.   */
/*	dblResulS        -> Resultado de la integracion con Simpson.    */
/*      dblResul38       -> Resultado de la integracion con 3/8.        */
/*      dblErrorT        -> Error cometido con Trapecio.                */
/*      dblErrorS        -> Error cometido con Simpson.                 */
/*      dblError38       -> Error cometido con 3/8.			*/
/*      intNumIntervalos -> Numero de subintervalos que utilizaremos.   */
/*      ptNomFich        -> Nombre del fichero en el que se guardaran   */
/*                          los resultados obtenidos.                   */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

typedef struct Datos

	{
	double	dblInicio,
		dblFinal,
		dblResulT,
		dblResulS,
		dblResul38,
		dblErrorT,
		dblErrorS,
		dblError38;

	int	intNumIntervalos;

	char 	*ptNomFich;
	} DatosIntgr;

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* Funcion que pide los datos necesarios para comenzar la integracion.  */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void PeticionDatos(DatosIntgr *ptstrDatos);

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

int intAlmacenarResultados(DatosIntgr *ptstrDatos);
