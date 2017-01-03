/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */                                                                            
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula el valor del polinomio dblPoli(de grado intGrado)*/
/* en el punto dblPunto, la funcion devuelve dicho valor.               */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

double dblEvaluarPolinomio(double *dblPoli, int intGrado, double dblPunto);

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que multiplica el polinomio dblPoli1(de grado intGrado1) por */
/* el polinomio dblPoli2(de grado intGrado2) y lo almacena en           */
/* dblResultado.                                                        */
/*                                                                      */
/* La funcion supone que se ha reservado memoria para *dblResultado,    */
/* y que todos sus elementos estan inicializados a cero.                */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void MultPoli(double *dblPoli1, int intGrado1, double *dblPoli2, 
	int intGrado2, double *dblResultado);

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula la expresion de un polinomio dadas su raices.    */
/*                                                                      */
/* La funcion devuelve los codigos:					*/
/*                                                                      */
/*	-1 HUBO UN ERROR DE MEMORIA.					*/
/*	0 SE CALCULO CON EXITO						*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int intExpre(double *dblRaices, int intNumero, double *dblRes);

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula el valor m\'aximo del polinomio dblPoli          */
/* (de grado intGrado), en valor absoluto, en el intervalo [dblA, dblB] */
/* utilizando intN puntos en dicho intervalo. La funcion devuelve dicho */
/* valor.                                                               */
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

double dblMaxPol(double *dblPoli, int intGrado, double dblA, double dblB,
		int intN);
