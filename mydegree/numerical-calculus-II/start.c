#include "struct.h"

#define NEWTON '1'
#define BROYDEN '2'
#define AMBOS '3'

extern struct datos;

void empezar(char metodo, struct datos *ptparametros, double *vector, 
             double *error_new, double *error_broy, int *ptnewton_ite,
             int *ptbroyden_ite)

{       

int control = 0;

if (metodo == NEWTON || metodo == AMBOS )
               
        {       /* INICIO "NEWTON" */

	*ptnewton_ite = hacer_newton(ptparametros, vector, error_new);

	switch (*ptnewton_ite)

                {       /* INICIO SWITCH */

                case -2:

                /* NO SE ALCANZO LA CONVERGENCIA EN EL NUMERO DE
                   ITERACIONES ESTABLECIDAS POR EL USUARIO */

                        {
                        error_convergencia (ptparametros->ite);
                        break;
                        }

                case -1:

                /* ERROR EN LA ASIGNACION DE MEMORIA */

                        {
                        errores_mem ();
                        break;
                        }

                case 0:

                /* SE HA INTENTADO RESOLVER UN SISTEMA
                   DE ECUACIONES QUE NO TIENE SOLUCION */

                        {
                        error_sis();
                        break;
                        }

                }       /* FIN SWITCH */


        }       /* FIN "NEWTON" */

if (metodo == BROYDEN || metodo == AMBOS)

        {       /* INICIO "BROYDEN" */

	*ptbroyden_ite = hacer_broyden(ptparametros, vector, error_broy);

	switch (*ptbroyden_ite)

                {       /* INICIO SWITCH */

                case -2:

                /* NO SE ALCANZO LA CONVERGENCIA EN EL NUMERO DE ITERACIONES
                   ESTABLECIDAS POR EL USUARIO */

                        {
                        error_convergencia (ptparametros->ite);
                        break;
                        }

                case -1:

                /* ERROR EN LA ASIGNACION DE MEMORIA */

                        {
                        errores_mem ();
                        break;
                        }

                case 0:

                /* SE HA INTENTADO RESOLVER UN SISTEMA DE ECUACIONES QUE NO
                   TIENE SOLUCION */

                        {
                        error_sis();
                        break;
                        }

                }       /* FIN SWITCH */

        }       /* FIN "BROYDEN" */


/* COMPARACION GRAFICA DE ERRORES SI SE HA CONSEGUIDO LA CONVERGENCIA CON
   AMBOS METODOS */

if ( (metodo == AMBOS) && (*ptnewton_ite > 0) && (*ptbroyden_ite > 0) )

        {

	control = hacer_graficas(*ptnewton_ite, error_new,
		  *ptbroyden_ite, error_broy);

        /* NO SE PUDO INICIALIZAR EL MODO GRAFICO */

        if ( control == 0 )

                {
                error_graficas ();
                }
        }

}
