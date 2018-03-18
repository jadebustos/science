#include "struct.h"

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*         FUNCION PARA INICIALIZAR LA MATRIZ DE CONTROL DEL CODIGO           */
/*                                                                            */
/*----------------------------------------------------------------------------*/

void InicializarCheck(Matriz *MatrizControl)

{
/* PRIMERA FILA DE LA MATRIZ DE CONTROL */

MatrizControl->intElemento[0][0] = 1; MatrizControl->intElemento[0][3] = 1;
MatrizControl->intElemento[0][1] = 1; MatrizControl->intElemento[0][4] = 0;
MatrizControl->intElemento[0][2] = 0; MatrizControl->intElemento[0][5] = 0;

/* SEGUNDA FILA DE LA MATRIZ DE CONTROL */

MatrizControl->intElemento[1][0] = 1; MatrizControl->intElemento[1][3] = 0;
MatrizControl->intElemento[1][1] = 0; MatrizControl->intElemento[1][4] = 1;
MatrizControl->intElemento[1][2] = 1; MatrizControl->intElemento[1][5] = 0;

/* TERCERA FILA DE LA MATRIZ DE CONTROL */

MatrizControl->intElemento[2][0] = 0; MatrizControl->intElemento[2][3] = 0;
MatrizControl->intElemento[2][1] = 1; MatrizControl->intElemento[2][4] = 0;
MatrizControl->intElemento[2][2] = 1; MatrizControl->intElemento[2][5] = 1;

return;
}
