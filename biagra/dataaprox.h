#ifndef _DATAAPROX_H
  #define _DATAAPROX_H

/*                                                                      */
/* Esta estructura la utilizaremos para manejar todos los datos         */
/* necesarios en la aproximacion de las raices de funciones.            */
/*                                                                      */
/* intNMI numero maximo de iteraciones.                                 */
/*                                                                      */
/* dblx0 aproximacion inicial.                                          */
/*                                                                      */
/* dblSolucion aproximacion obtenida a la raiz del polinomio.           */
/*                                                                      */
/* dblTol tolerancia con la que se quiere aproximar                     */
/* la raiz(error maximo).                                               */
/*                                                                      */
/* dblError error cometido en la aproximacion de la raiz, distancia     */
/* entre las dos ultimas aproximaciones de la solucion.                 */
/*                                                                      */
        
  typedef struct {
    int intNMI;
    double  dblx0,
            dblSolucion,
            dblTol,
            dblError;

  } DatosAprxFunc;

#endif
