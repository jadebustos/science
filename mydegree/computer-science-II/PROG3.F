C Este programa lee desde teclado los elementos de dos vectores
C reales de dimensión 3 y saca por pantalla su producto escalar

	PROGRAM prog3

	REAL x1, x2, x3, y1, y2, y3, proes

C Peticion de datos

	PRINT *,'Introduce las coordenadas del primer vector(x1,x2,x3):'
	READ *,x1,x2,x3

	PRINT *,'Introduce las coordenadas del segundo vector(y1,y2,y3):'
	READ *,y1,y2,y3

C Calculo del producto escalar

	proes = (x1*y1)+(x2*y2)+(x3*y3)

C Mostrar resultados

	PRINT *,'El producto escalar es',proes

	STOP
	END
