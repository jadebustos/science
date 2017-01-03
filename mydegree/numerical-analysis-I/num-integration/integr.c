#include <stdio.h>
#include <math.h>

#include "datos.h"
#include "trapecio.h"	/* REGLA DEL TRAPECIO COMPUESTA */
#include "simpson.h"	/* REGLA DE SIMPSON COMPUESTA */
#include "tres8.h"	/* REGLA DE LOS 3/8 COMPUESTA */

#define BIEN     0
#define ERR_FICH 1

/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */                                                                            
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

int main (void)

{
int	intOpcion = 0;

DatosIntgr	strSeno,
		strCoseno,
		strExp;

do

	{	/* INICIO while */

	printf("1 - Integrar la funcion seno.\n\n");
	printf("2 - Integrar la funcion coseno.\n\n");
	printf("3 - Integrar la funcion exponencial.\n\n");
	printf("0 - Finalizar.\n\n");

	printf("Opcion: ");
	scanf("%d", &intOpcion);
	}	/* FINAL while */

while ( intOpcion < 0 || intOpcion >= 4);

/* INICIALIZACION DE LOS NOMBRES DE LOS FICHEROS */

strSeno.ptNomFich   = "seno.dat";
strCoseno.ptNomFich = "coseno.dat";
strExp.ptNomFich    = "exp.dat";

switch ( intOpcion )

	{	/* INICIO switch */

	case 1:	/* SEN (x) */

		{
		/* PETICION DE DATOS AL USUARIO */

		PeticionDatos(&strSeno);
	
		/* INTEGRACION TRAPECIO */
		
		TrapecioCompuesto(&strSeno, sin);
		ErrorTrapecio(&strSeno, sin);

		/* INTEGRACION SIMPSON */

		SimpsonCompuesto(&strSeno, sin);
		ErrorSimpson(&strSeno, sin);

		/* INTEGRACION 3/8 */

		TresOctCompuesto(&strSeno, sin);
		ErrorTresOct(&strSeno, sin);

		/* ALMACENAMIENTO DE DATOS EN UN FICHERO */

		intOpcion = intAlmacenarResultados(&strSeno);

		if ( intOpcion != 0 )
			{
			printf("\nHubo algun error al abrir el fichero %s.\n",
				strSeno.ptNomFich);

			return(ERR_FICH);	/* FIN */
			}

		break;
		}

	case 2:	/* COS (x) */

		{
		/* PETICION DE DATOS AL USUARIO */

		PeticionDatos(&strCoseno);

		/* INTEGRACION TRAPECIO */

		TrapecioCompuesto(&strCoseno, cos);
		ErrorTrapecio(&strCoseno, cos);

		/* INTEGRACION SIMPSON */

		SimpsonCompuesto(&strCoseno, cos);
		ErrorSimpson(&strCoseno, cos);

		/* INTEGRACION 3/8 */

		TresOctCompuesto(&strCoseno, cos);
		ErrorTresOct(&strCoseno, cos);

		/* ALMACENAMIENTO DE DATOS EN UN FICHERO */

		intOpcion = intAlmacenarResultados(&strCoseno);

		if ( intOpcion != 0 )
			{	
			printf("\nHubo algun error al abrir el fichero %s.\n",
				strCoseno.ptNomFich);

			return (ERR_FICH);
			}

		break;
		}

	case 3: /* E^x */

		{
		/* PETICION DE DATOS AL USUARIO */

		PeticionDatos(&strExp);

		/* INTEGRACION TRAPECIO */

		TrapecioCompuesto(&strExp, exp);
		ErrorTrapecio(&strExp, exp);

		/* INTEGRACION SIMPSON */

		SimpsonCompuesto(&strExp, exp);
		ErrorSimpson(&strExp, exp);

		/* INTEGRACION 3/8 */

		TresOctCompuesto(&strExp, exp);
		ErrorTresOct(&strExp, exp);
	
		/* ALMACENAMIENTO DE DATOS EN UN FICHERO */

		intOpcion = intAlmacenarResultados(&strExp);

		if ( intOpcion != 0 )
			{
			printf("\nHubo algun error al abrir el fichero %s.\n",
				strExp.ptNomFich);

			return(ERR_FICH);
			}

		break;
		}

	}	/* FINAL switch */

return (BIEN);
}
