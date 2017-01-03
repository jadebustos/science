/* PROTOTIPO DE LA FUNCION QUE RESUELVE UNA ECUACION DIFERENCIAL UTILIZANDO
   EL METODO DE EULER */

void Euler (Datos *Var, double (*EDO)(double Punto, double FuncPunto),
		double (*DerEDO)(double Punto));
