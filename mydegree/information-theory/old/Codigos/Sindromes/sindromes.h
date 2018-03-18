#ifndef _SINDROMES_H
   #define _SINDROMES_H 1

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*             FUNCION QUE INICIALIZA LOS SINDROMES DEL CODIGO                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

void InicializarSindromes(Matriz *MatrizControl);

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*          PROCESADOR DE ERROR PARA EL CODIGO DE TRIPLE REPETICION           */
/*                                                                            */
/*----------------------------------------------------------------------------*/

int ProcError(PalCod *PalRec, PalCod *PalOk, PalCod *Sindr, Sindromes Tabla[]);

#endif
