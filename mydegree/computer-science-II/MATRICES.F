C Programa que pide dos matrices cuadradas de orden 3 por teclado
C y calcula la suma el producto y los determinantes de las cuatro matrices

	PROGRAM prog9
	IMPLICIT NONE
	REAL matriz1(3,3), matriz2(3,3), sum(3,3), prod(3,3), valor

C 	Inicializacion de suma y prod

	DATA sum, prod /18*0./

C 	Peticion de datos de matriz1

	CALL pedir(matriz1)

C 	Peticion de datos de matriz2

	CALL pedir(matriz2)

C 	Multiplicacion de las dos matrices

	CALL multip(matriz1, matriz2, prod)

C 	Suma de las dos matrices

	CALL suma(matriz1, matriz2, sum)

C	Muestra el producto de las dos matrices

	WRITE(*,*)'El producto de las dos matrices es'

	CALL ver(prod)

C 	Muestra la suma de las dos matrices

	WRITE(*,*)'La suma es'

	CALL ver(sum) 
	
C	Muestra los determinantes

	CALL deter(matriz1, valor)

	WRITE(*,*)'Determinante de matriz1 ', valor

	CALL deter(matriz2, valor)

	WRITE(*,*)'Determinante de matriz2 ', valor	

	CALL deter(prod, valor)

	WRITE(*,*)'Determinante del producto ', valor

	CALL deter(sum, valor)

	WRITE(*,*)'Determinante de la suma ', valor

	STOP
	END

C Subrutina que multiplica dos matrices

	SUBROUTINE multip(matriz1, matriz2, prod)

	REAL matriz1(3,3), matriz2(3,3), prod(3,3)
	INTEGER i,j,k

	DO 60 i=1,3

		DO 50 j=1,3

			DO 200 k=1,3

			prod(i,j) = prod(i,j)+(matriz1(i,k)*matriz2(k,j))

200			CONTINUE


50		CONTINUE

60	CONTINUE 

	RETURN
	END

C Subrutina que suma dos matrices

	SUBROUTINE suma(matriz1, matriz2, sum)

	REAL matriz1(3,3), matriz2(3,3), sum(3,3)
	INTEGER i,j

	DO 80 i=1,3

		DO 70 j=1,3

		sum(i,j) = matriz1(i,j)+matriz2(i,j)

70	 	CONTINUE

80	 CONTINUE

	RETURN
	END

C Subroutina que imprime en pantalla una matriz

	SUBROUTINE ver(matriz)
	
	REAL matriz(3,3)
	INTEGER i,j

	DO 100 i=1,3

		DO 90 j=1,3
		
		WRITE(*,*)matriz(i,j),'  '
90		CONTINUE
	
	WRITE(*,*)' '

100	CONTINUE

	RETURN
	END

C	Subroutina que pide una matriz de 3x3 desde teclado 

	SUBROUTINE pedir(matriz) 

	REAL matriz(3,3)
	INTEGER i

	WRITE(*,*)'Introduce los coeficientes de matriz'

	DO 20 i=1,3

		DO 10 j=1,3
		
		WRITE(*,*)'Escribe el coeficiente ',i,' ',j
		READ(*,*)matriz(i,j)
		
10		CONTINUE

20	CONTINUE

	RETURN
	END

C   	Subroutina que calcula el determinante

	SUBROUTINE deter(matriz, valor)

	REAL matriz(3,3), valor

	valor = (matriz(1,1)*matriz(2,2)*matriz(3,3))
	valor = valor+(matriz(1,2)*matriz(2,3)*matriz(3,1))
	valor = valor+(matriz(3,2)*matriz(2,1)*matriz(1,3))	
	valor = valor-(matriz(1,3)*matriz(2,2)*matriz(3,1))
	valor = valor-(matriz(1,2)*matriz(2,1)*matriz(3,3))
	valor = valor-(matriz(3,2)*matriz(2,3)*matriz(1,1))

	RETURN
	END
