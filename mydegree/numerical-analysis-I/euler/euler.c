#include <stdio.h>
#include <math.h>

#include "datos.h"
#include "meteuler.h"

int main (void)

{
Datos	VarDatos;

double EDO    (double Punto, double FuncPunto);
double DerEDO (double Punto);

printf("Introduce el punto inicial de integracion: ");
scanf("%lf", &(VarDatos.Inicio));

printf("Introduce el punto final de integracion: ");
scanf("%lf", &(VarDatos.Final));

printf("Introduce el numero de puntos a utilizar: ");
scanf("%d", &(VarDatos.Puntos));

printf("Introduce el valor de la funcion en %lf: ", (VarDatos.Inicio));
scanf("%lf", &(VarDatos.ValorInicio));

/* CALCULAMOS EL PASO QUE VA A UTILIZAR EL METODO */

(VarDatos.Paso) = ((VarDatos.Final)-(VarDatos.Inicio))/((VarDatos.Puntos)-1);

/* RESOLVEMOS LA ECUACION DIFERENCIAL POR EL METODO DE EULER */

Euler(&VarDatos, EDO, DerEDO);

/* PRESENTAMOS POR PANTALLA LOS DATOS */

printf("\nEl valor de la funcion en el punto %lf es %.15lf.\n",
		VarDatos.Final, VarDatos.Solucion);

printf("El error cometido es %.15lf.\n", VarDatos.Error);
printf("Se ha utilizado un paso %e.\n", VarDatos.Paso);

return 0;
}

double EDO (double Punto, double FuncPunto)

{
double Valor;

Valor = -FuncPunto + Punto + 1.;

return (Valor);
}

double DerEDO (double Punto)

{
double	Valor;

Valor = exp(-Punto);

return (Valor);
}
