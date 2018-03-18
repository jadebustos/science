#ifndef _STRUCT_H
   #define _STRUCT_H 1

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                ESTRUCTURA DE DATOS PARA PALABRAS DEL CODIGO                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

typedef struct {
   int intLong,
       *intPalabra;	
   } PalCod;

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                   ESTRUCTURA DE DATOS PARA MATRICES                        */
/*                                                                            */
/*----------------------------------------------------------------------------*/

typedef struct {
  int intFilas,
      intCol,
      **intElemento;
  } Matriz;  

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                    ESTRUCTURA DE DATOS PARA VECTORES                       */
/*                                                                            */
/*----------------------------------------------------------------------------*/

typedef struct {
   int intFilas,
       *intElemento;
   } Vector;


/*----------------------------------------------------------------------------*/
/*									      */
/*                 ESTRUCTURA PARA ALMACENAR LOS SINDROMES                    */
/*									      */
/*----------------------------------------------------------------------------*/

typedef struct {
   int Lider[6],
       Sindrome[3];
   } Sindromes;

#endif
