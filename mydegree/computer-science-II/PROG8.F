C Programa que calcula la suma de los numeros naturales impares
C comprendidos entre dos numeros min y max que se le pasan por
C teclado

	PROGRAM prog8

	INTEGER i, min, max, suma, cociente, resto

C Inicializacion de variables 

	data i,max,suma,cociente,resto /5*0/
	min=-1
	
C Peticion de datos

	PRINT *,'Calculo de la suma de los numeros naturales impares'
     	PRINT *,'comprendidos entre dos numeros naturales.'

	DO WHILE ((min.LT.0).OR.(max.LT.0))
		PRINT *,'Introduce el minimo:'
		READ *,min
		
		PRINT *,'Introduce el maximo:'
		READ *,max
	END DO

C La forma de comenzar la suma depende de si el minimo es par o impar

	cociente=min/2
	resto=min-(cociente*2)

C Si el resto es 1 es impar

	IF (resto.EQ.1) THEN
		i=min+2
		
		DO WHILE(i.LT.max)
		suma=suma+i
C Incrementar i en dos unidades para que vaya de impar en impar
		i=i+2		
		END DO

	ELSE
		i=min+1

		DO WHILE(i.LT.max)
		suma=suma+i
C Incrementar en dos unidades para que vaya de par en par
		i=i+2
		END DO	
	
	END IF

C Mostrar resultados

	PRINT *,'El resultado de la suma es:',suma
	STOP
	END 
