#include <math.h>

#include <biagra/struct.h>
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
/* complejo.c     Jose Angel de Bustos Perez                            */
/*                                                                      */
/* Prototipos de funciones relacionadas con los numeros complejos.      */
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
/*                                                                      */
/* Funcion que calcula la suma de dos numeros complejos y devuelve      */
/* dicha suma, como una estructura del tipo Complejo.                   */
/*                                                                      */
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

Complejo strSumaComplejos(Complejo strComp1, Complejo strComp2)

{
Complejo 	strResultado;

strResultado.dblReal = strComp1.dblReal + strComp2.dblReal;
strResultado.dblImag = strComp1.dblImag + strComp2.dblImag;

return(strResultado);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula la resta de dos numeros complejos y devuelve     */
/* dicha resta, como una estructura del tipo Complejo.                  */
/*                                                                      */
/*	strComp1 - strComp2						*/
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

Complejo strRestaComplejos(Complejo strComp1, Complejo strComp2)

{
Complejo 	strResultado;

strResultado.dblReal = strComp1.dblReal - strComp2.dblReal;
strResultado.dblImag = strComp1.dblImag - strComp2.dblImag;

return(strResultado);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula el producto de dos numeros complejos y devuelve  */
/* dicho producto, como una estructura del tipo Complejo.               */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

Complejo strProdComplejos(Complejo strComp1, Complejo strComp2)

{
Complejo 	strResultado;

strResultado.dblReal = ((strComp1.dblReal)*(strComp2.dblReal)) -
		((strComp1.dblImag)*(strComp2.dblImag));

strResultado.dblImag = ((strComp1.dblImag)*(strComp2.dblReal)) + 
		((strComp1.dblReal)*(strComp2.dblImag));

return(strResultado);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula la division de dos numeros complejos.            */
/*                                                                      */
/*	strComp1 * (strComp2)^(-1)					*/
/*									*/
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*		DIV_CERO division por cero.				*/
/*		TRUE Se efectuo con exito la division.			*/
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int DivComplejos(Complejo strComp1, Complejo strComp2,
 		Complejo *ptstrRes)
{
double 	dblDenominador;

if ( strComp2.dblReal == .0 && strComp2.dblImag == .0 ) /* DIVISION POR CERO */
	return (DIV_CERO); /* FIN */

else
   {        
   dblDenominador = ((strComp2.dblReal)*(strComp2.dblReal)) +
	 ((strComp2.dblImag)*(strComp2.dblImag));

   ptstrRes->dblReal = (((strComp1.dblReal)*(strComp2.dblReal)) +
		       ((strComp1.dblImag)*(strComp2.dblImag)))/dblDenominador;

   ptstrRes->dblImag = (((strComp1.dblImag)*(strComp2.dblReal)) - 
		       ((strComp1.dblReal)*(strComp2.dblImag)))/dblDenominador;
                       
   }

return(TRUE);	/* FIN */
}


/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula y devuelve el modulo de un numero complejo.      */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

double dblModulo(Complejo strComp)

{
double	dblRes =.0,
   	dblAux1 = .0,
        dblAux2 = .0;
        
dblAux1 = (strComp.dblReal)*(strComp.dblReal);
dblAux2 = (strComp.dblImag)*(strComp.dblImag);

dblRes = sqrt(dblAux1 + dblAux2);

return(dblRes);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula y devuelve el argumento de un numero complejo.   */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

double dblArgumento(Complejo strComp)

{

double	dblRes = .0;

if ( strComp.dblReal == 0 )
	{
	if ( strComp.dblImag >= 0 )
		dblRes = PI/2.;
	
	else
		dblRes = (3./2.)*PI;
	}

/* PRIMER CUADRANTE */

else if ( (strComp.dblReal) > 0 && (strComp.dblImag) >= 0 )	
	dblRes = atan((strComp.dblImag)/(strComp.dblReal));

/* SEGUNDO CUADRANTE */

else if ( (strComp.dblReal) < 0 && (strComp.dblImag) >= 0 )
	dblRes = PI - atan((-1.)*(strComp.dblImag)/(strComp.dblReal));

/* TERCER CUADRANTE */

else if ( (strComp.dblReal) < 0 && (strComp.dblImag) < 0 )
	dblRes = PI + atan((strComp.dblImag)/(strComp.dblReal));

/* CUARTO CUADRANTE */

else
	dblRes = ((2.)*PI) - atan((-1.)*(strComp.dblImag)/(strComp.dblReal));

return(dblRes);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula el opuesto, respecto de la suma, de un numero    */
/* complejo y lo devuelve.                                              */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

Complejo strOpuComplejo(Complejo strComp)

{
Complejo 	strResultado;

strResultado.dblReal = (-1.)*(strComp.dblReal);
strResultado.dblImag = (-1.)*(strComp.dblImag);

return(strResultado);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula el inverso, respecto del producto, de un numero  */
/* complejo y lo almacena en strRes.                                    */
/*                                                                      */
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*	DIV_CERO Division por cero.				        */
/*      TRUE Se calculo con exito.					*/
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int InvComplejo(Complejo strComp, Complejo *ptstrRes)

{
double 	dblDenominador;

if ( strComp.dblReal == 0 && strComp.dblImag == 0 ) /* DIVISION POR CERO */
	return(DIV_CERO);	/* FIN */
        
else
   {        
   dblDenominador = ((strComp.dblReal)*(strComp.dblReal))+
               	 ((strComp.dblImag)*(strComp.dblImag));

   ptstrRes->dblReal = (strComp.dblReal)/dblDenominador;
   ptstrRes->dblImag = ((-1.)*(strComp.dblImag))/dblDenominador;
   }

return(TRUE);	/* FIN */
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que calcula el complejo conjugado de un numero complejo y lo */
/* devuelve.                                                            */
/*									*/
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*                                                                      */
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

Complejo strComplejoConj(Complejo strComp)

{
Complejo 	strResultado;

strResultado.dblReal = strComp.dblReal;
strResultado.dblImag = (-1.)*(strComp.dblImag);

return(strResultado);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que pasa un numero complejo en coordenadas cartesianas a     */
/* coordenadas polares.                                                 */
/*                                                                      */
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

Polar strCartePolar(Complejo strComp)

{
Polar 	strResultado;
double	dblAux = .0;

dblAux = ((strComp.dblReal)*(strComp.dblReal)) +
         ((strComp.dblImag)*(strComp.dblImag));

strResultado.dblMod = sqrt(dblAux);

/* NUMEROS IMAGINARIOS PUROS */

if ( strComp.dblReal == 0 )
	{
	if ( strComp.dblImag >= 0 )
		strResultado.dblArg = PI/2.;
	
	else
		strResultado.dblArg = (3./2.)*PI;
	}

/* PRIMER CUADRANTE */

else if ( (strComp.dblReal) > 0 && (strComp.dblImag) >= 0 )	
	strResultado.dblArg = atan((strComp.dblImag)/(strComp.dblReal));

/* SEGUNDO CUADRANTE */

else if ( (strComp.dblReal) < 0 && (strComp.dblImag) >= 0 )
	strResultado.dblArg = PI + atan((strComp.dblImag)/(strComp.dblReal));

/* TERCER CUADRANTE */

else if ( (strComp.dblReal) < 0 && (strComp.dblImag) < 0 )
	strResultado.dblArg = PI + 
		atan((strComp.dblImag)/(strComp.dblReal));

/* CUARTO CUADRANTE */

else
	strResultado.dblArg = ((2.)*PI) + 
		atan((strComp.dblImag)/(strComp.dblReal));

return(strResultado);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*                                                                      */
/* Funcion que pasa un numero complejo en coordenadas polares a         */
/* coordenadas cartesianas.                                             */
/*                                                                      */
/*	B.I.A.G.R.A.	    Jose Angel de Bustos Perez			*/
/*									*/
/*	BIbliotecA de proGRamacion cientificA.				*/
/*									*/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

Complejo strPolarCarte(Polar strComp)

{
Complejo	strResultado;

strResultado.dblReal = (strComp.dblMod)*cos((strComp.dblArg));
strResultado.dblImag = (strComp.dblMod)*sin((strComp.dblArg));

return(strResultado);
}
