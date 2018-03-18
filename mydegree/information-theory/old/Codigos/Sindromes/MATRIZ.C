#include "struct.h"
#include "Mod2.h"

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*               FUNCION QUE MULTIPLICA MATRICES POR VECTORES                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/

void MulMatVec(Matriz *Mat, int Vec[], int Res[])

{
int i,j;

for(i=0;i<Mat->intFilas;i++)  { /* INICIO PRIMER for */

   for(j=0;j<Mat->intCol;j++) { /* INICIO SEGUNDO for */

      Res[i] = SumaF2(Res[i], ProdF2(Mat->intElemento[i][j], Vec[j]));

      } /* FINAL SEGUNDO for */

   } /* FINAL PRIMER for */

return;
}
