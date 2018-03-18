#ifndef _TABLAES_H
   #define _TABLAES_H 1

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                 FUNCION QUE INICIALIZA LA TABLA ESTANDAR                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

int InicializarTablaEstandar(PalCod Tabla[][8]);

/*----------------------------------------------------------------------------*/
/*									      */
/* FUNCION COMPRUEBA LA PALABRA RECIBIDA Y CALCULA LA QUE SE TRANSMITIO.      */
/*									      */
/*----------------------------------------------------------------------------*/

void Decodificar(PalCod  Tabla[][8], PalCod *PalRec, int *intFila, int *intCol);

#endif
