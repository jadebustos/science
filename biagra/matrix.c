
/*                                                                      */
/* Funcion que almacena la matriz identidad.                            */
/*                                                                      */
/* El orden de la matriz viene dado por el miembro intFilas de la       */
/* variable a la que apunta ptstrMatriz.				*/
/*                                                                      */

void MatrizIdentidad(Matriz *ptstrMatriz)

{
int	i,	/* CONTADOR */
	j;	/* CONTADOR */

for(i=0;i<(ptstrMatriz->intFilas);i++)

	{	/* INICIO PRIMER for */

	for(j=0;j<(ptstrMatriz->intFilas);j++)

		{	/* INICIO SEGUNDO for */

		if ( i == j )

			{	/* INICIO if */
			
			(ptstrMatriz->dblCoefi[i][i]) = 1.;

			}	/* FINAL if */

		else

			{	/* INICIO else */

			(ptstrMatriz->dblCoefi[i][j]) = .0;

			}	/* FINAL else */

		}	/* FINAL SEGUNDO for */

	}	/* FINAL PRIMER for */

return;
}

/*                                                                      */
/* Funcion que almacena la matriz de la homotecia de razon dblRazon.    */
/*                                                                      */
/* El orden de la matriz viene dado por el miembro intFilas de la       */
/* variable a la que apunta ptstrMatriz.				*/
/*                                                                      */

void MatrizHomotecia(Matriz *ptstrMatriz, double dblRazon)

{
int	i,	/* CONTADOR */
	j;	/* CONTADOR */

for(i=0;i<(ptstrMatriz->intFilas);i++)

	{	/* INICIO PRIMER for */

	for(j=0;j<(ptstrMatriz->intFilas);j++)

		{	/* INICIO SEGUNDO for */

		if ( i == j )
			(ptstrMatriz->dblCoefi[i][i]) = dblRazon;

		else
			(ptstrMatriz->dblCoefi[i][j]) = .0;

		}	/* FINAL SEGUNDO for */

	}	/* FINAL PRIMER for */

return;
}

/*                                                                      */
/* Funcion que almacena la matriz nula en dblMatriz.                    */
/*                                                                      */
/* Las filas y columnas de la matriz vienen dadas por los miembros	*/
/* intFilas e intColumnas de la variable a la que apunta ptstrMatriz.   */
/*                                                                      */

void MatrizNula(Matriz *ptstrMatriz)

{
int	i,	/* CONTADOR */
	j;	/* CONTADOR */

for(i=0;i<(ptstrMatriz->intFilas);i++)

	{	/* INICIO PRIMER for */

	for(j=0;j<(ptstrMatriz->intColumnas);j++)

		{	/* INICIO SEGUNDO for */

		(ptstrMatriz->dblCoefi[i][j]) = .0;

		}	/* FINAL SEGUNDO for */

	}	/* FINAL PRIMER for */

return;
}

/*                                                                      */
/* Funcion que almacena la matriz traspuesta de ptstrMatriz en          */
/* ptstrTras.   							*/
/*                                                                      */
/* Las filas y columnas de la matriz vienen dadas por los miembros	*/
/* intFilas e intColumnas de la variable a la que apunta ptstrMatriz.   */
/*                                                                      */

void MatrizTraspuesta(Matriz *ptstrMatriz, Matriz *ptstrTras)

{
int	i,	/* CONTADOR */
   	j;	/* CONTADOR */

for(i=0;i<(ptstrMatriz->intColumnas);i++)

	{	/* INICIO PRIMER for */
   
	for(j=0;j<(ptstrMatriz->intFilas);j++)
   
		{	/* INICIO SEGUNDO for */
      
		(ptstrTras->dblCoefi[i][j]) = (ptstrMatriz->dblCoefi[j][i]);
      
		}	/* FINAL SEGUNDO for */
   
	}	/* FINAL PRIMER for*/

return;
}

