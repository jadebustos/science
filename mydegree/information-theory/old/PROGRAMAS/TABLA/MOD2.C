/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                      FUNCIONES PARA OPERAR EN Z/2                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* FUNCION PARA SUMAR ELEMENTOS EN Z/2, a,b PERTENECEN A Z/2 */

int SumaF2(int a, int b)

{
int Res[2][2];

Res[0][0] = 0; /* 0+0 */	Res[0][1] = 1; /* 0+1 */
Res[1][0] = 1; /* 1+0 */	Res[1][1] = 0; /* 1+1 */

return (Res[a][b]);
}

/* FUNCION PARA MULTIPLICAR ELEMENTOS EN Z/2, a,b PERTENECEN A Z/2 */

int ProdF2(int a, int b)

{
int Prod[2][2];

Prod[0][0] = 0; /* 0*0 */	Prod[0][1] = 0; /* 0*1 */
Prod[1][0] = 0; /* 1*0 */	Prod[1][1] = 1; /* 1*1 */

return (Prod[a][b]);
}

/* FUNCION PARA RESTAR ELEMENTOS EN Z/2, a,b PERTENECEN A Z/2 */

int DifF2(int a, int b)

{
int Dif[2][2];

Dif[0][0] = 0; /* 0-0 */	Dif[0][1] = 1; /* 0-1 */
Dif[1][0] = 1; /* 1-0 */	Dif[1][1] = 0; /* 1-1 */

return(Dif[a][b]);
}
