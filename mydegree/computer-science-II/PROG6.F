C Programa que lee los coeficientes reales de un polinomio de segundo
C orden y calcula sus raices reales

	PROGRAM prog5

	REAL a, b, c, x1, x2

C Peticion de datos

	PRINT *,'Programa para resolver ecuaciones de segundo grado.'
	
	PRINT *,'Introduce el coeficiente de grado dos:'
	READ *,a

	PRINT *,'Introduce el coeficiente de grado uno:'
	READ *,b

	PRINT *,'Introduce el termino independiente:'
	READ *,c

C Llama a la subrutina

	CALL raices(a,b,c,x1,x2)

C Imprime en pantalla las raices del polinomio

	PRINT *,'Las raices son las siguientes:'
	PRINT *,'x1 =',x1
	PRINT *,'x2 =',x2

	STOP
	END

	SUBROUTINE raices(a,b,c,x1,x2)

C Subrutina que cacula las raices de una ecuacion de segundo grado 

	REAL a,b,c,x1,x2,discr


C Calculo del discriminante

	discr = (b*b)-(4*a*c)

C Si el discriminante es menor que cero indicalo y fin

	IF (discr.LT.0)	THEN

		WRITE(*,*)'La ecuacion tiene raices complejas'
		STOP

	ELSE

		x1=((-b)+SQRT(discr))/(2*a)
		x2=((-b)-SQRT(discr))/(2*a)
	END IF

	RETURN
	END	
