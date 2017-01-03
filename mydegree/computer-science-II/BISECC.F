C	Programa para calcular la solucion de la ecuacion x -0.8-.2*sin(x)
C	mediante el metodo de la biseccion 

	PROGRAM biseccion 

	REAL apract, vala, tol, a, b, dista, valor
	INTEGER nmi, i

C	Inicializaciones de variables 

	tol = 1.E-6
	a = .0
	b = 2*(3.141592654)
	dista = 1. 
	nmi = 60

	WRITE(*,*)'Introduce aproximacion inicial: '
	READ(*,*) aprant

	DO 10 i=1,nmi

	dista = (b-a)/2

	apract=a+dista

C	Valor de la funcion en el punto
	CALL funcion(apract, valor)

	IF ((dista.LT.tol).OR.(valor.EQ.0)) THEN
	
		WRITE(*,*)'La raiz es ', apract
		STOP

	ENDIF

C	Valor en el extremo

	CALL funcion(a, vala)

	IF ((vala*valor).GT.0) THEN

		a = apract

	ELSE

		b = apract
	
	ENDIF	
 	
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
