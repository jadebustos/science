C Programa que calcula la suma de la serie 1/n hasta el término
C i-ésimo

	PROGRAM prog7
	
	REAL res
	INTEGER i, n

C Inicializacion de variables

	data res,i,n /3*0/

C Peticion de datos

	PRINT *,'Programa que calcula la suma de la serie 1/n'

	DO WHILE(n.LT.1)
		PRINT *,'Hasta que termino?'
		READ *,n
	END DO

C Calculo de la suma de la serie

	DO i=1,n
		res=res+(1./i)
	END DO

C Mostrar resultados

	PRINT *,'La suma de la serie hasta el termino',n,' es',res
	STOP
	END
