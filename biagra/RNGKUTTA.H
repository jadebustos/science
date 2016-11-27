/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/*	B.I.A.G.R.A.	(c) 1998 Jose Angel de Bustos Perez		*/
/*			 <jadebustos@gmail.com>         		*/
/*									*/
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* 	      METODOS EXPLICITOS PARA PROBLEMAS ESCALARES		*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

/*                                                                      */
/* Funcion que inicializa los coeficientes del RUNGE-KUTTA CLASICO,     */
/* metodo de cuatro etapas, la funcion asigna memoria a los punteros de */
/* la estructura DatosRK, por lo que es necesario que no esten          */
/* dimensionados cuando se le pase como parametro la variable de        */
/* estructura a la funcion.                                             */
/*                                                                      */
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*	TRUE     -> Se inicializaron con exito los coeficientes.	*/
/*      ERR_AMEM -> Hubo un error en la asignacion de memoria.		*/
/*                                                                      */

int RungeKuttaClasico(DatosRK *ptstrDatos);

/*                                                                      */
/* Funcion que inicializa los coeficientes del metodo de HEUN,          */
/* metodo RUNGE-KUTTA de tres etapas, la funcion asigna memoria a los   */
/* punteros de la estructura DatosRK, por lo que es necesario que no    */
/* esten dimensionados cuando se le pase como parametro la variable de  */
/* estructura a la funcion.                                             */
/*                                                                      */
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*	TRUE     -> Se inicializaron con exito los coeficientes.	*/
/*      ERR_AMEM -> Hubo un error en la asignacion de memoria.		*/
/*                                                                      */

int MetodoHeun(DatosRK *ptstrDatos);

/*                                                                      */
/* Funcion que inicializa los coeficientes del metodo de KUTTA,         */
/* metodo RUNGE-KUTTA de tres etapas, la funcion asigna memoria a los   */
/* punteros de la estructura DatosRK, por lo que es necesario que no    */
/* esten dimensionados cuando se le pase como parametro la variable de  */
/* estructura a la funcion.                                             */
/*                                                                      */
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*	TRUE     -> Se inicializaron con exito los coeficientes.	*/
/*      ERR_AMEM -> Hubo un error en la asignacion de memoria.		*/
/*                                                                      */

int MetodoKutta(DatosRK *ptstrDatos);

/*                                                                      */
/* Funcion que inicializa los coeficientes del metodo de EULER          */
/* MODIFICADO, metodo RUNGE-KUTTA de dos etapas, la funcion asigna      */
/* memoria a los punteros de la estructura DatosRK, por lo que es       */
/* necesario que no esten dimensionados cuando se le pase como          */
/* parametro la variable de estructura a la funcion.                    */
/*                                                                      */
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*	TRUE     -> Se inicializaron con exito los coeficientes.	*/
/*      ERR_AMEM -> Hubo un error en la asignacion de memoria.		*/
/*                                                                      */

int EulerModificado(DatosRK *ptstrDatos);

/*                                                                      */
/* Funcion que inicializa los coeficientes del metodo de EULER MEJORADO */
/* metodo RUNGE-KUTTA de dos etapas, la funcion asigna memoria a los    */
/* punteros de la estructura DatosRK, por lo que es necesario que no    */
/* esten dimensionados cuando se le pase como parametro la variable de  */
/* estructura a la funcion.                                             */
/*                                                                      */
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*	TRUE     -> Se inicializaron con exito los coeficientes.	*/
/*      ERR_AMEM -> Hubo un error en la asignacion de memoria.		*/
/*                                                                      */

int EulerMejorado(DatosRK *ptstrDatos);
