#include <math.h>

#include "datos.h"

/* PROTOTIPO DE LA FUNCION QUE RESUELVE UNA ECUACION DIFERENCIAL UTILIZANDO
   EL METODO DE EULER */

void Euler (Datos *Var, double (*EDO)(double Punto, double FuncPunto),
		double (*DerEDO)(double Punto))

{
int	i;

double	Nueva,			     /* APROXIMACION NUEVA */
	Vieja = (Var->ValorInicio),  /* APROXIMACION ANTERIOR */
	Punto = (Var->Inicio);	     /* PUNTO EN EL QUE ESTAMOS INTEGRANDO */

for(i=1;i<(Var->Puntos);i++)

	{
	Punto = (Var->Inicio)+(i-1)*(Var->Paso);

	Nueva = Vieja+((Var->Paso)*((*EDO)(Punto, Vieja)));

	Vieja = Nueva;
	}

/* ACTUALIZACION DE LOS DATOS */

(Var->Solucion) = Nueva;
(Var->Final)    = Punto + (Var->Paso);

/* CALCULO DEL ERROR */

(Var->Error) = .0;

(Var->Error) = fabs((*DerEDO)(Var->Final));

(Var->Error) *= fabs((((Var->Final)-(Var->Inicio))*(Var->Paso))/2.);

return;
}
