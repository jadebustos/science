C	Programa para calcular la solucion de la ecuacion x -0.8-.2*sin(x)
C	mediante el metodo de Newton-Raphson

	PROGRAM newton

	REAL apract, aprant, tol, a, b, error, valor, valder
	INTEGER nmi, i

C	Inicializaciones de variables 

	tol = 1.E-6
	a = .0
	b = 2*(3.141592654)
	error = 1. 
	nmi = 60

	WRITE(*,*)'Introduce aproximacion inicial: '
	READ(*,*) aprant

	DO 10 i=1,nmi

C	Valor de la funcion en el punto
	CALL funcion(aprant, valor)

C	Valor de la derivada en el punto
	CALL derivada(aprant, valder)

	apract=aprant-(valor/valder)

	error=ABS(aprant-apract)

	IF (error.LT.tol) THEN
	
		WRITE(*,*)'La raiz es ', apract
		STOP

	ENDIF
 	
	aprant=apract

10	CONTINUE

C	No se alcanzo convergencia

	WRITE(*,*)'No se alcanzo la convergencia.'
 
	STOP
	END

C	Calcula el valor de la funcion en un punto

	SUBROUTINE funcion(punto, valor)

	REAL punto, valor

	valor=punto-(.8)-((.2)*sin(punto))
	
	RETURN
	END

C	Calcula el valor de la derivada en un punto

	SUBROUTINE derivada(punto, valor)

	REAL punto, valor

	valor=1-((.2)*cos(punto))
	
	RETURN
	END
