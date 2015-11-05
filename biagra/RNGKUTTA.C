#include <stdlib.h>

#include <biagra/struct.h>
#include <biagra/resmem.h>
#include <biagra/const.h>

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
/* rngkutta.c     Jose Angel de Bustos Perez                            */
/*                                                                      */
/* Funciones para inicializar variables para la utilizacion de RK.      */
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
/*	TRUE  Se inicializaron con exito los coeficientes.		*/
/*      ERR_AMEM Hubo un error en la asignacion de memoria.		*/
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int RungeKuttaClasico(DatosRK *ptstrDatos)

{
/* FUNCION QUE INICIALIZA LOS COEFICIENTES PARA UTILIZAR EL METODO
   "RUNGE-KUTTA" CLASICO PARA LA RESOLUCION NUMERICA DE E.D.O's */

int 	intEtapas = 4;	/* NUMERO DE ETAPAS DEL METODO */

/* RESERVA DE MEMORIA */

ptstrDatos->strCoefi.dblC = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblC == NULL )
	{
	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblB = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblB == NULL )
	{
	free(ptstrDatos->strCoefi.dblC);
	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblMatriz = (double **)dblPtAsigMemMatTrInf(intEtapas);

if ( ptstrDatos->strCoefi.dblMatriz == NULL )
	{
	free(ptstrDatos->strCoefi.dblB);
	free(ptstrDatos->strCoefi.dblC);
	FreeMemDblMat(ptstrDatos->strCoefi.dblMatriz, intEtapas);

	return (ERR_AMEM);	/* FIN */
	}

/* NUMERO DE ETAPAS DEL METODO */

ptstrDatos->strCoefi.intEtapas = intEtapas;

/* ESTE METODO ES UN METODO EXPLICITO */

ptstrDatos->intImplicito = FALSE;

/* COEFICIENTES b[i] */

ptstrDatos->strCoefi.dblB[0] = ptstrDatos->strCoefi.dblB[3] = 1./6.;
ptstrDatos->strCoefi.dblB[1] = ptstrDatos->strCoefi.dblB[2] = 1./3.;

/* COEFICIENTES c[i] */

ptstrDatos->strCoefi.dblC[0] = .0;
ptstrDatos->strCoefi.dblC[1] = ptstrDatos->strCoefi.dblC[2] = 1./2.;
ptstrDatos->strCoefi.dblC[3] = 1.;

/* COEFICIENTES a[i][j] */

ptstrDatos->strCoefi.dblMatriz[0][0] = .0;

ptstrDatos->strCoefi.dblMatriz[1][0] = 1./2.;
ptstrDatos->strCoefi.dblMatriz[1][1] = .0;

ptstrDatos->strCoefi.dblMatriz[2][0] = .0;
ptstrDatos->strCoefi.dblMatriz[2][1] = 1./2.;
ptstrDatos->strCoefi.dblMatriz[2][2] = .0;

ptstrDatos->strCoefi.dblMatriz[3][0] = .0;
ptstrDatos->strCoefi.dblMatriz[3][1] = .0;
ptstrDatos->strCoefi.dblMatriz[3][2] = 1.;
ptstrDatos->strCoefi.dblMatriz[3][3] = .0;

return (TRUE);
}

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

int MetodoHeun(DatosRK *ptstrDatos)

{
/* FUNCION QUE INICIALIZA LOS COEFICIENTES PARA UTILIZAR EL METODO
   DE "HEUN" PARA LA RESOLUCION NUMERICA DE E.D.O's */

int 	intEtapas = 3;	/* NUMERO DE ETAPAS DEL METODO */

/* RESERVA DE MEMORIA */

ptstrDatos->strCoefi.dblC = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblC == NULL )
	{
	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblB = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblB == NULL )
	{
	free(ptstrDatos->strCoefi.dblC);
	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblMatriz = (double **)dblPtAsigMemMatTrInf(intEtapas);

if ( ptstrDatos->strCoefi.dblMatriz == NULL )
	{
	free(ptstrDatos->strCoefi.dblB);
	free(ptstrDatos->strCoefi.dblC);
	FreeMemDblMat(ptstrDatos->strCoefi.dblMatriz, intEtapas);
	return(ERR_AMEM);	/* FIN */
	}

/* NUMERO DE ETAPAS DEL METODO */

ptstrDatos->strCoefi.intEtapas = intEtapas;

/* ESTE METODO ES UN METODO EXPLICITO */

ptstrDatos->intImplicito = FALSE;

/* COEFICIENTES b[i] */

ptstrDatos->strCoefi.dblB[0] = 1./4.;
ptstrDatos->strCoefi.dblB[1] = .0;
ptstrDatos->strCoefi.dblB[2] = 3./4.;

/* COEFICIENTES c[i] */

ptstrDatos->strCoefi.dblC[0] = .0;
ptstrDatos->strCoefi.dblC[1] = 1./3.;
ptstrDatos->strCoefi.dblC[2] = 2./3.;

/* COEFICIENTES a[i][j] */

ptstrDatos->strCoefi.dblMatriz[0][0] = .0;

ptstrDatos->strCoefi.dblMatriz[1][0] = 1./3.;
ptstrDatos->strCoefi.dblMatriz[1][1] = .0;

ptstrDatos->strCoefi.dblMatriz[2][0] = .0;
ptstrDatos->strCoefi.dblMatriz[2][1] = 2./3.;
ptstrDatos->strCoefi.dblMatriz[2][2] = .0;

return (TRUE);
}

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
/*	TRUE     ->  Se inicializaron con exito los coeficientes.	*/
/*      ERR_AMEM ->  Hubo un error en la asignacion de memoria.		*/
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int MetodoKutta(DatosRK *ptstrDatos)

{
/* FUNCION QUE INICIALIZA LOS COEFICIENTES PARA UTILIZAR EL METODO
   DE "KUTTA" PARA LA RESOLUCION NUMERICA DE E.D.O's */

int 	intEtapas = 3;	/* NUMERO DE ETAPAS DEL METODO */

/* RESERVA DE MEMORIA */

ptstrDatos->strCoefi.dblC = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblC == NULL )
	{
	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblB = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblB == NULL )
	{
	free(ptstrDatos->strCoefi.dblC);
	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblMatriz = (double **)dblPtAsigMemMatTrInf(intEtapas);

if ( ptstrDatos->strCoefi.dblMatriz == NULL )
	{
	free(ptstrDatos->strCoefi.dblB);
	free(ptstrDatos->strCoefi.dblC);
	FreeMemDblMat(ptstrDatos->strCoefi.dblMatriz, intEtapas);

	return(ERR_AMEM);	/* FIN */
	}

/* NUMERO DE ETAPAS DEL METODO */

ptstrDatos->strCoefi.intEtapas = intEtapas;

/* ESTE METODO ES UN METODO EXPLICITO */

ptstrDatos->intImplicito = FALSE;

/* COEFICIENTES b[i] */

ptstrDatos->strCoefi.dblB[0] = 1./6.;
ptstrDatos->strCoefi.dblB[1] = 2./3.;
ptstrDatos->strCoefi.dblB[2] = 1./6.;

/* COEFICIENTES c[i] */

ptstrDatos->strCoefi.dblC[0] = .0;
ptstrDatos->strCoefi.dblC[1] = 1./2.;
ptstrDatos->strCoefi.dblC[2] = 1.;

/* COEFICIENTES a[i][j] */

ptstrDatos->strCoefi.dblMatriz[0][0] = .0;

ptstrDatos->strCoefi.dblMatriz[1][0] = 1./2.;
ptstrDatos->strCoefi.dblMatriz[1][1] = .0;

ptstrDatos->strCoefi.dblMatriz[2][0] = -1.;
ptstrDatos->strCoefi.dblMatriz[2][1] = 2.;
ptstrDatos->strCoefi.dblMatriz[2][2] = .0;

return (TRUE);
}

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
/*	TRUE     ->  Se inicializaron con exito los coeficientes.	*/
/*      ERR_AMEM ->  Hubo un error en la asignacion de memoria.		*/
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int EulerModificado(DatosRK *ptstrDatos)

{
/* FUNCION QUE INICIALIZA LOS COEFICIENTES PARA UTILIZAR EL METODO
   DE "EULER MODIFICADO" PARA LA RESOLUCION NUMERICA DE E.D.O's */

int 	intEtapas = 2;	/* NUMERO DE ETAPAS DEL METODO */

/* RESERVA DE MEMORIA */

ptstrDatos->strCoefi.dblC = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblC == NULL )
	{
	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblB = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblB == NULL )
	{
	free(ptstrDatos->strCoefi.dblC);

	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblMatriz = (double **)dblPtAsigMemMatTrInf(intEtapas);

if ( ptstrDatos->strCoefi.dblMatriz == NULL )
	{
	free(ptstrDatos->strCoefi.dblB);
	free(ptstrDatos->strCoefi.dblC);
	FreeMemDblMat(ptstrDatos->strCoefi.dblMatriz, intEtapas);

	return(ERR_AMEM);	/* FIN */
	}

/* NUMERO DE ETAPAS DEL METODO */

ptstrDatos->strCoefi.intEtapas = intEtapas;

/* ESTE METODO ES UN METODO EXPLICITO */

ptstrDatos->intImplicito = FALSE;

/* COEFICIENTES b[i] */

ptstrDatos->strCoefi.dblB[0] = .0;
ptstrDatos->strCoefi.dblB[1] = 1.;

/* COEFICIENTES c[i] */

ptstrDatos->strCoefi.dblC[0] = .0;
ptstrDatos->strCoefi.dblC[1] = 1./2.;

/* COEFICIENTES a[i][j] */

ptstrDatos->strCoefi.dblMatriz[0][0] = .0;

ptstrDatos->strCoefi.dblMatriz[1][0] = 1./2.;
ptstrDatos->strCoefi.dblMatriz[1][1] = .0;

return (TRUE);
}

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

int EulerMejorado(DatosRK *ptstrDatos)

{
/* FUNCION QUE INICIALIZA LOS COEFICIENTES PARA UTILIZAR EL METODO
   DE "EULER MEJORADO" PARA LA RESOLUCION NUMERICA DE E.D.O's */

int 	intEtapas = 2;	/* NUMERO DE ETAPAS DEL METODO */

/* RESERVA DE MEMORIA */

ptstrDatos->strCoefi.dblC = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblC == NULL )
	{
	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblB = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblB == NULL )
	{
	free(ptstrDatos->strCoefi.dblC);

	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblMatriz = (double **)dblPtAsigMemMatTrInf(intEtapas);

if ( ptstrDatos->strCoefi.dblMatriz == NULL )
	{
	free(ptstrDatos->strCoefi.dblB);
	free(ptstrDatos->strCoefi.dblC);
	FreeMemDblMat(ptstrDatos->strCoefi.dblMatriz, intEtapas);

	return(ERR_AMEM);	/* FIN */
	}

/* NUMERO DE ETAPAS DEL METODO */

ptstrDatos->strCoefi.intEtapas = intEtapas;

/* ESTE METODO ES UN METODO EXPLICITO */

ptstrDatos->intImplicito = FALSE;

/* COEFICIENTES b[i] */

ptstrDatos->strCoefi.dblB[0] = 1./2.;
ptstrDatos->strCoefi.dblB[1] = 1./2.;

/* COEFICIENTES c[i] */

ptstrDatos->strCoefi.dblC[0] = .0;
ptstrDatos->strCoefi.dblC[1] = 1.;

/* COEFICIENTES a[i][j] */

ptstrDatos->strCoefi.dblMatriz[0][0] = .0;

ptstrDatos->strCoefi.dblMatriz[1][0] = 1.;
ptstrDatos->strCoefi.dblMatriz[1][1] = .0;

return (TRUE);
}
