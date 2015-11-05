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
/*                                                                      */
/* rngkutta.h     Jose Angel de Bustos Perez                            */
/*                                                                      */
/* Prototipos de funciones para inicializar variables para              */
/* la utilizacion de RK.                                                */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* IMPORTANTE!!!                                                        */
/*                                                                      */
/*     1) El autor no se responsabiliza de los posibles bugs(si los     */
/*        hubiera) ni del mal uso de esta biblioteca.                   */
/*                                                                      */
/*     2) Esta biblioteca ha sido desarrollada y testeada bajo LiNUX.   */
/*                                                                      */ 
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*									*/
/* 	      METODOS EXPLICITOS PARA PROBLEMAS ESCALARES		*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

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
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int RungeKuttaClasico(DatosRK *ptstrDatos);

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
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
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int MetodoHeun(DatosRK *ptstrDatos);

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
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
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int MetodoKutta(DatosRK *ptstrDatos);

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
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
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int EulerModificado(DatosRK *ptstrDatos);

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
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
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int EulerMejorado(DatosRK *ptstrDatos);
