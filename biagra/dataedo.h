/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */                                                                            
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Esta estructura se utilizara en los metodos Runge-Kutta(E.D.O).      */
/*                                                                      */
/* Esta implementada para almacenar los coeficientes de un metodo R-K   */
/* segun la notacion matricial de Butcher.                              */
/*                                                                      */
/* Vamos a explicar cada miembro de la estructura.                      */
/*                                                                      */
/* Para ello supondremos que el metodo R-K tiene la formulacion:        */
/*                                                                      */
/* Y_(n) aproximacion del valor de la funcion Y en el punto x_n.        */
/* h paso constante.                                                    */
/* s numero de etapas del metodo                                        */
/*                                                                      */
/* El metodo sera el siguiente:                                         */
/*                                                                      */
/* Y_(n+1) = Y_(n) +h*(SUM[(b_i * k_i),{i=,1,s}])                       */
/*                                                                      */
/* k_i = f(x_n + (h*c_i),Y_(n) + h*(SUM[(a_ij * k_j),{j=,1,s}]) )       */
/*                                                                      */
/* SUM[a_ij,{j=,1,s}] = c_i                                             */
/*                                                                      */
/* Donde f(x,Y(x)) = Y' sera el P.V.I a resolver, junto con su          */
/* inicializacion correspondiente.                                      */
/*                                                                      */
/* Los miembros de la estructura son:                                   */
/*                                                                      */
/* intEtapas = Numero de etapas del metodo, en el caso anterior el      */
/*             metodo tiene s etapas.                                   */
/*                                                                      */
/* *dblC = Array unidimensional que contiene los c_i, es decir          */
/*         dblC[i] = c_(i+1)  0 <= i <= s-1 .                           */
/*                                                                      */
/* *dblB = Array unidimensional que contiene los b_i, es decir          */
/*         dblB[i] = b_(i+1)  0 <= i <= s-2 .                           */
/*                                                                      */
/* **dblMatriz = Array bidimensional que contiene los a_ij, es decir    */
/*               dblMatriz[i][j] = a_(i+1)(j+1)  0 <= i,j <= s .        */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/


typedef struct
	{
	double 	*dblC,
		*dblB,
		**dblMatriz;

	int	intEtapas;
	} ButcherArray;

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Esta estructura la utilizaremos para manejar todos los datos         */
/* necesarios en la implementacion de un metodo R-K(E.D.O.).            */
/*                                                                      */
/* strCoefi sera una variable de estructura del tipo ButcherArray, en   */
/* la cual estaran los coeficientes del metodo.                         */
/*                                                                      */
/* intNumAprox contendra el numero de aproximaciones que se realizaran  */
/* con el metodo, es decir contendra la dimension de dblPuntos.         */
/*                                                                      */
/* intImplicito indica si el metodo es un Runge-Kutta implicito en caso */
/* afirmativo tendra el valor 0 y en caso contrario un valor diferente  */
/* de 0.								*/
/*									*/
/* dblPaso almacenara el paso que se utiliza en el metodo.              */
/*                                                                      */
/* dblInicio es el primer punto en el que nos apoyamos para calcular    */
/* siguientes aproximaciones, es conocido el valor de la funcion en     */
/* dblInicio.                                                           */
/*                                                                      */
/* dblFinal es el ultimo punto para el que calcularemos una aproximacion*/
/* de la funcion.							*/
/*                                                                      */
/* dblPuntos almacenara los valores de la funcion en los diferentes     */
/* x_(i).                                                               */
/*                                                                      */
/* Supongamos que estamos calculando una aproximacion de Y en x_(i),    */
/* es decir estamos calculando Y_(i), entonces:                         */
/*                                                                      */
/* dblPuntos[i] = Y_(i)	                                                */
/*									*/
/* dblPuntos[0] = valor de Y en dblInicio. 				*/
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

typedef struct
	
	{
        int	intNumAprox,
		intImplicito;
        
	double 	*dblPuntos,
		dblPaso,
                dblInicio,
                dblFinal;

        ButcherArray strCoefi;
	} DatosRK;
