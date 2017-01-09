#  funcion que calcula el determinante de una matriz cuadrada             #
#  Recibe como parametro una matriz cuadrada. Si no es cuadrada o no es   #
#  matriz, devuelve 0. En otro caso calcula el y lo devuelve determinante #
#  ------------------------------------------------------------           #
#               funcion determinante(A)                                   #
#  ------------------------------------------------------------           #
funcion determinante(A)
   si maxdims(A)<>2 retornar 0 finsi
   si profdim(A,1)<>profdim(A,2) retornar 0 finsi
   si profdim(A,1)=2 
      retornar A[1,1]*A[2,2]-A[1,2]*A[2,1] 
   finsi
   si profdim(A,1)=1 retornar A[1,1] finsi
   local det, i, mcomp, signo,hold
   signo=1
   det=0
   paratodo i=1 hasta profdim(A,1)    # A[1,i] * determinante(mcomp)   #
      hold=matrizmcomp(A,1,i,mcomp)
               #signo*determinante(mcomp) -> menor complementario a[i,1] #
      det=det+signo*determinante(mcomp)*A[1,i]
      signo=signo*-1                  # Cambiamos el signo en cada iteracion #
   volver
   retornar det
fin
#   funcion que calcula la matriz cuyo determinante es menor complementario      #
#   Recibe como parametros una matriz cuadrada, los subindices de fila, columna  #
#   Y una variable por referencia que se convierte en matriz cuadrada            #
#   Devuelve 0 en caso de error                                                  #
#   Devuelve 1 en case de que se hiciese bien                                    #
#  ------------------------------------------------------------         #
#               funcion matrizmcomp(A,i,j,*M)                           #
#  ------------------------------------------------------------         #
funcion matrizmcomp(A,i,j,*M)
   si maxdims(A)<>2 retornar 1 finsi
   si profdim(A,1)<>profdim(A,2)|profdim(A,2)<3 retornar 2 finsi
   array M[profdim(A,1)-1,profdim(A,2)-1]
   local h, k
   paratodo h=1 hasta profdim(A,1)             # Recorrido de filas   #
   si h<>i                                     # para omitir la fila  #
   paratodo k=1 hasta profdim(A,2)             # Recorrido de columna #
      si k<>j                                  # omitimos la columna  #
         si h>i&k>j M[h-1,k-1]=A[h,k] finsi  
         si h>i&k<j M[h-1,k]=A[h,k]   finsi    
         si h<i&k>j M[h,k-1]=A[h,k]   finsi
         si h<i&k<j M[h,k]=A[h,k] finsi
     finsi
   volver
   finsi
   volver
   retornar 0
fin
#   funcion que calcula la traspuesta de una matriz.                    #
#   Recibe como parametros una matriz, por valor y otra por referencia  #
#   devolviendo en la referencia la matriz traspuesta.                  #
#   Devuelve 0 en caso de error                                         #
#   Devuelve 1 en case de que se hiciese bien                           #
#  ------------------------------------------------------------         #
#               funcion traspuesta(A,*T)                                #
#  ------------------------------------------------------------         #
funcion traspuesta(A,*T)
   si maxdims(A)<>2 retornar 1 finsi
   local i,j
   array T[profdim(A,2),profdim(A,1)]
   paratodo i=1 hasta profdim(A,1)
   paratodo j=1 hasta profdim(A,2)
      T[j,i]=A[i,j]
   volver
   volver
fin
#   funcion que calcula la matriz conjugada de otra matriz.           #
#   Recibe como parametros una matriz por valor y otra por referencia #
#   devolviendo en la referencia la matriz adjunta.                   #
#   Devuelve 0 en caso de error                                       #
#   Devuelve 1 en case de que se hiciese bien                         #
#  ------------------------------------------------------------       #
#               funcion adjunta(A,*C)                                 #
#  ------------------------------------------------------------       #
funcion adjunta(A,*C)
   si maxdims(A)<>2 retornar 1 finsi
   si profdim(A,1)<>profdim(A,2) retornar 2 finsi
   array C[profdim(A,1),profdim(A,2)]
   local i,j, local aux,hold
   paratodo i=1 hasta profdim(A,1)
   paratodo j=1 hasta profdim(A,2)
      hold=matrizmcomp(A,i,j,aux)
      C[i,j]=A[i,j]*determinante(aux)
   volver
   volver
fin
#   funcion que calcula la matriz conjugada de otra matriz.           #
#   Recibe como parametros una matriz por valor y otra por referencia #
#   devolviendo en la referencia la matriz conjugada.                 #
#   Devuelve 0 en caso de error                                       #
#  ------------------------------------------------------------       #
#               funcion conjugada(A,*C)                               #
#  ------------------------------------------------------------       #
funcion conjugada(A,*C)
   si maxdims(A)<>2 retornar 1 finsi
   si profdim(A,1)<>profdim(A,2) retornar 2 finsi
   array C[profdim(A,1),profdim(A,2)]
   local c,hold
   hold=traspuesta(c,C)
   hold=adjunta(A,c)
fin
#   funcion que calcula el producto de un numero real por una matriz  #
#   Recibe como parametros una matriz por referencia y un numero      #
#   devolviendo en la referencia la matriz producto                   #
#   Devuelve 0 en caso de error.				      #
#  ------------------------------------------------------------       #
#               funcion  rXmatriz(*A,r)                               #
#  ------------------------------------------------------------       #
funcion rXmatriz(*A,r)
   si maxdims(A)<>2 retornar 1 finsi
   local i, j
   paratodo i=1 hasta profdim(A,1)
   paratodo j=1 hasta profdim(A,2)
      A[i,j]=A[i,j]*r
   volver
   volver
fin
#   funcion que suma matrices de la misma dimension                   #
#   Recibe como parametros dos matrices por valor y una referencia    #
#   devolviendo en la referencia la matriz suma                       #
#   devuelve 0 en caso de error                                       #
#  ------------------------------------------------------------       #
#               funcion  sumamatriz(A1,A2,*S)                         #
#  ------------------------------------------------------------       #
funcion sumamatriz(A1,A2,*S)
   si maxdims(A1)<>2 retornar 1 finsi
   si maxdims(A2)<>2 retornar 1 finsi
   si profdim(A1,1)<>profdim(A2,1)|profdim(A1,2)<>profdim(A2,2)
      retornar 2
   finsi
   local i,j
   array S[profdim(A1,1),profdim(A2,1)]
   paratodo i=1 hasta profdim(A1,1)
   paratodo j=1 hasta profdim(A1,2)
      S[i,j]=A1[i,j]+A2[i,j]
   volver
   volver
fin
#   funcion que hace el producto de dos matrices                       #
#   Recibe como paramteros dos matrices y una referencia               #
#   devolviendo en la referencia la matriz resultante del producto     #
#   devuelve 0 en caso de error                                        #
#  ------------------------------------------------------------        #
#               funcion  prodmatriz(A1,A2,*P)                          #
#  ------------------------------------------------------------        #
funcion prodmatriz(A1,A2,*P)
   si maxdims(A1)<>2|maxdims(A2)<>2 retornar 1 finsi
   si profdim(A1,2)<>profdim(A2,1) retornar 2 finsi
   local i,j,k,suma
   array P[profdim(A1,1),profdim(A2,2)]   
   paratodo i=1 hasta profdim(P,1)
   paratodo j=1 hasta profdim(P,2)
      suma=0
      paratodo k=1 hasta profdim(A1,2)
         suma=suma+A1[i,k]*A2[k,j]
      volver
      P[i,j]=suma
   volver
   volver
fin
#   funcion que calcula la inversa de una matiz cuadrada               #
#   Recibe como paramteros una matriz y una referencia                 #
#   devolviendo en la referencia la inversa                            #
#   devuelve 0 en caso de error                                        #
#  ------------------------------------------------------------        #
#               funcion  matrizinversa(A,*I)                           #
#  ------------------------------------------------------------        #
funcion matrizinversa(A,*I)
   si maxdims(A)<>2 retornar 1 finsi # No es una matriz #
   si profdim(A,1)<>profdim(A,2) retornar 1 finsi # No es cuadrada #
   local det
   det=determinante(A) # si el determinante es 0 no tienen matriz inversa #
   si det=0 retornar 2 finsi
   array I[profdim(A,1),profdim(A,2)]
   local mcomp,i ,j, t,hold
   hold=traspuesta(A,t)
   paratodo i=1 hasta profdim(A,1)
   paratodo j=1 hasta profdim(A,2)
      hold=matrizmcomp(t,i,j,mcomp)
      I[i,j]=determinante(mcomp)*(-1)^(i+j)/det
   volver
   volver
fin
#     Resuelve un sistema de ecuaciones de Kramer           #
#    Recibe como parametros una matriz de coeficientes,     #
#    un vector de soluciones, una referencia de incognitas  #
#    devuelve 0 si el sistema de ecuaciones no es de kramer #
#  -------------------------------------------------        #
#               funcion Kramer(A,S,*I)                      #
#  --------------------------------------------------       #
funcion kramer(A,S,*I) 
   si maxdims(A)<>2 retornar 1 finsi
   si maxdims(S)<>1 retornar 2 finsi # es un vector de soluciones #
   si profdim(A,1)<>profdim(A,2) retornar 1 finsi #no es cuadrada #
   si profdim(S,1)<>profdim(A,1) retornar 3 finsi #no es de kramer#
   local det
   det=determinante(A)
   si det=0 retornar 0 finsi # El determinante no puede ser nulo #
   array I[profdim(A,1)]
   local i,j, aux, d
   array aux[profdim(A,1)]
   paratodo i=1 hasta profdim(A,1)
   paratodo j=1 hasta profdim(A,1) #En este bucle sustituimos la columna#
      aux[j]=A[j,i]
      A[j,i]=S[j]
   volver
   d=determinante(A)
   paratodo j=1 hasta profdim(A,1) #En este bucle deshacemos la sustit.#
      A[j,i]=aux[j]
   volver
   I[i]=d/det
   volver
fin 
#    Resuelve uns sistema de ecuaciones por gauss simple    #
#    Recibe como parametros una matriz de coeficientes,     #
#    un vector de soluciones, una referencia de incognitas  #
#    devuelve 0 si el sistema de ecuaciones no es de kramer #
#  -------------------------------------------------        #
#               funcion Gauss(A,S,*I)                       #
#  --------------------------------------------------       #
funcion Gauss(A,S,*I)
   si maxdims(A)<>2||maxdims(S)<>1 retornar 1 finsi
   si profdim(A,1)<>profdim(A,2) retornar 2 finsi
   local i,j,k, h, constdiv, Np, const, total
   Np=profdim(S,1)
   array I[Np]
   paratodo i=1 hasta Np 
      I[Np]=1 
   volver
   paratodo i=1 hasta Np
      constdiv=A[i,i]
      paratodo h=i+1 hasta Np     
         const=A[h,i]
         paratodo j=i hasta Np
            A[h,j]=(A[h,j]-((A[i,j]/constdiv)*const))
         volver
         S[h]=S[h]-((S[i]/constdiv) * const)
      volver
   volver
   paratodo i=Np hasta 1 paso -1
        total = 0
	paratodo h=i+1 hasta Np
	       total = total + (A[i,h] * I[h])		
        volver
	I[i] = ((S[i] - total)/A[i,i])
   volver
fin
#      Funcion de hacer ceros...                                  #
#  Recibe como parametros una matriz cuadrada y una referencia en #
#  la que se devuelve la matriz triangular que se calcule.        #
#                                                                 #
#          funcion hacer_ceros(A,*R)                              #
#                                                                 #
funcion hacer_ceros(A,*R)
   si maxdims(A)<>2||profdim(A,1)<>profdim(A,2) retornar 1 finsi
   local i,j,h,const,constdiv,Np
   Np=profdim(A,1)
   array R[Np,Np]
   paratodo i=1 hasta Np
   paratodo j=1 hasta Np
      R[i,j]=A[i,j]
   volver volver
   paratodo i=1 hasta Np
      constdiv=R[i,i]
      paratodo h=i+1 hasta Np     
         const=R[h,i] 
         paratodo j=i hasta Np
            R[h,j]=(R[h,j]-((R[i,j]/constdiv)*const))
         volver
      volver
   volver
fin
#  Funcion de diagonalizar una matriz cuadrada.???                #
#  Recibe como parametros una matriz cuadrada y una referencia en #
#  la que se devuelve la matriz diagonal que se calcule.          #
#                                                                 #
#           funcion diagonalizar(A,*R)                            #
#                                                                 #
funcion diagonalizar(A,*R)
   si maxdims(A)<>2||profdim(A,1)<>profdim(A,2) retornar 1 finsi
   local T, Np,hold
   Np=profdim(A,1)
   array T[Np,Np]
   hold=hacer_ceros(A,R)
   hold=traspuesta(R,T)
   hold=hacer_ceros(T,R)
fin