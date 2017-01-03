C Programa que dado un numero nos dice si es bisiesto

	PROGRAM prog4

	INTEGER anno,cociente,resto

C Inicializacion de variables
	anno=-1

C Peticion de datos

	DO WHILE(anno.LT.0)
		PRINT *,'Introduce un anno para saber si es bisiesto:'
		READ *,anno
	END DO

	cociente=anno/4
	resto=anno-(cociente*4)

C Si resto es 0 entonces es multiplo de 4 

	IF(resto.NE.0) THEN
		PRINT *,'No es un anno bisiesto'
	ELSE
		cociente=anno/100
		resto=anno/(cociente*100)

C Si resto es 0 entonces es multiplo de 100

		IF(resto.EQ.0) THEN
			PRINT *,'No es un anno bisiesto'
		ELSE
			PRINT *,'Es un anno bisiesto'

		END IF

	END IF

	STOP
	END
