#ifndef _MEM_H
   #define _MEM_H 1

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*               FUNCIONES PARA RESERVAR MEMORIA DINAMICAMENTE                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* FUNCION QUE RESERVA MEMORIA PARA PALABRAS DEL CODIGO */

int ResMemCod(PalCod *Palabra);

/*----------------------------------------------------------------------------*/
/*									      */
/* FUNCION QUE RESERVA MEMORIA PARA UN ARRAY BIDIMENSIONAL, DEL TIPO int,     */
/* DE intFilas FILAS Y intCol COLUMNAS Y DEVUELVE SU DIRECCION.               */
/*									      */
/*----------------------------------------------------------------------------*/

int **intPtAsigMemMat(int intFilas, int intCol);

#endif
