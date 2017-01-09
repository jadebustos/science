
#                                                           #
#   Funcion que calcula los coeficientes a partir de las    #
#   diferencias divididas y el producto polinomial que se   #
#   calculan en las diferentes fases del calculo del poli-  #
#   nomio interpolador de Newton                            #
#                                                           #
#              funcion coeficientes(bi,Prod,*Pol)           #
#                                                           #
funcion coeficientes(bi,Prod,*Pol)
   local n, i, j, k,m, suma, signo
   si maxdims(Prod)<>2 retornar 1 finsi 
   si maxdims(bi)<>1 retornar 2 finsi
   si profdim(Prod,1)<>profdim(Prod,2) retornar 3 finsi
   n=profdim(Prod,1)
   array Pol[n]
   array suma[n]
   paratodo i=1 hasta n
      paratodo j=i hasta n
         si j<>1 Prod[i,j]=Prod[i,j]+Prod[i,j-1] finsi
      volver
   volver
   array Pol[n]
   paratodo i=1 hasta n-1
      m=1 signo=-1 Pol[i]=bi[i]
      paratodo j=i hasta n-1
         Pol[i]=Pol[i]+Prod[m,j]*signo*bi[m+i]
         signo=signo*-1 m=m+1
      volver
   volver
   Pol[n]=bi[n]
fin
#                                                           #
#   Funcion que calcula las diferencias divididas para el   #
#   polinomio de interpolacion de Newton. Recibe como para- #
#   Recibe como parametros un array(valores de los puntos)  #
#   y una referencia a un nuevo array a crear.              #
#   Esta funcion la utiliza la funcion que nos da el poli-  #
#   nomio interpolador de newton.                           #
#                                                           #
#              funcion dif_div_newton(k,*hold)              #
#                                                           #
#                                                           #
funcion dif_div_newton(Y,*hold)
   si maxdims(Y)<>2 retornar 1 finsi #Es una tabla en NxM #
   si profdim(Y,1)<>2 retornar 2 finsi #Es pares ordenados (x,y)#
   local i,j, n, m, hold
   n=profdim(Y,2)
   array hold[n,n]
   paratodo i=1 hasta n
      hold[1,i]=Y[2,i]
   volver
   paratodo i=2 hasta n
      m=1
   paratodo j=i hasta n
      hold[i,j]=(hold[i-1,j]-hold[i-1,j-1])/(Y[1,j]-Y[1,m])
      m=m+1
   volver		
   volver
fin
#                                                           #
#   Funcion que calcula una tabla con los resultados de las #
#   multiplicaciones sucesivas (x-x0)(x-x1)...(x-xn)        #
#   Para lo que recibe una tabla de xi, y una referencia en #
#   la que devuelve un array solucion.                      #
#   Esta funcion la utiliza la funcion que nos da el poli-  #
#   nomio interpolador de newton.                           #
#                                                           #
#       funcion prod_polinom_newton(Xi,*Prod)               #
#                                                           #
#                                                           #
funcion prod_polinom_newton(Xi,*Prod)
   local n, i, j, k, h
   si maxdims(Xi)<>1 retornar 1 finsi
   n=profdim(Xi,1)
   array Prod[n,n]
   paratodo i=1 hasta n
      Prod[1,i]=Xi[i]
      paratodo j=2 hasta i 
         h=0
         paratodo k=j-1 hasta i-1
            h=h+Prod[j-1,k]*Prod[1,i]
         volver 
         Prod[j,i]=h
      volver
   volver
fin

#   Funcion que sin calcular el polinomio de newton nos da #
#   el valor estimado en un punto y el error de la funcion #
#   en el punto. Recibe como parametros un array de 2xN un #
#   punto en el que calcular el valor aproximado y         #
#   dos referencias, la primera sirve para devolver el     #
#   valor estimado y la segunda sirve para obtener el error#
#                                                          #
#      funcion ipolar_newton(Y,PX,*Val,*Err)               #
#                                                          #
funcion ipolar_newton(K,PX,*Val,*Err)
   local err, i, n, Fact, Pol, kx
   err=dif_div_newton(K,Fact)
   si err retornar err finsi
   n=profdim(K,2)
   array kx[n]
   paratodo i=1 hasta n
      kx[i]=K[1,i] #Metemos en un array las diferencias divididas#
   volver
   local DP, Y, EA
   Y=0 DP=1
   paratodo i=1 hasta n-1
      Y=Y+kx[i]*DP
      DP=DP*(PX-K[1,i])
      EA=DP*K[2,i+1]
      ?Y,EA
   volver
fin

#   Funcion que calcula la recta de regresion de una nube de #
#   puntos. Se le pasa como parametros un array de 2xN y una #
#   referencia en la que devuelve la recta resultado de la   #
#   regresion lineal.                                        #
#                                                            #	
#       funcion regresion_lineal(K,*R)                       #
#                                                            #
funcion regresion_lineal(K,*R)
   si maxdims(K)<>2 retornar 1 finsi
   local n,i,Sx,Sy,S2x, XY, A, Xm, Ym
   array A[2]
   n=profdim(K,2)
   paratodo i=1 hasta n
     Sx=Sx+K[1,i]
     S2x=S2x+K[1,i]*K[1,i]
     Sy=Sy+K[2,i]
     XY=XY+K[1,i]*K[2,i]
   volver
   Ym=Sy/n
   Xm=Sx/n
   A[2]=-(n*XY-Sx*Sy)/(n*S2X-Sx*Sx)
   A[1]=Ym-A[2]*Xm
   polinomio(A,x,R)
fin
#    Funcion  que calcula la curva de regresion de una nube de #
#    puntos. Se le pasa como parametros un array de 2xN una    #
#    referencia en la que se devuelve un polinomio y el orden  #
#    del polinomio que nos va a dar la curva de regresion.     #
#    Nota: Es extremadamente lento en caso de ser de muy alto  #
#          orden.(hasta 4 es aceptable)                        #
#                                                              #
#          funcion regresion_polinomial(K,*R,orden)            #
#                                                              #
funcion regresion_polinomial(K,*R,orden)
   si maxdims(K)<>2 retornar 1 finsi
   local i,j,l, r,Np,A, Coef, Sol, Incog, ret
   Np=profdim(K,2) 
   array A[orden+1,orden+2]
   paratodo i=1 hasta orden+1
      paratodo j=1 hasta orden+1
         r=i+j-2
         paratodo l=1 hasta Np
            A[i,j]=A[i,j]+K[1,l]^r
         volver 
      volver 
   paratodo l=1 hasta Np
      A[i,orden+2]=A[i,orden+2]+K[2,l]*K[1,l]^(i-1)
   volver
   volver
   array Coef[orden+1,orden+1]
   array Sol[orden+1]
   array Incog[Orden+1]
   paratodo i=1 hasta orden+1
      paratodo j=1 hasta orden+1
         Coef[i,j]=A[i,j]
      volver
      Sol[i]=A[i,j]
   volver
   ret=Gauss(Coef,Sol,Incog)
   ret=polinomio(Incog,x,R)
fin

#                                                           #
#   Funcion de interpolacion con las diferencias divididas  #
#   de Newton. Recibe como parametros un array y[2,n] y una #
#   referencia S en la que se dara el el polinomio de inter-#
#   polacion.                                               #
#   y[1,n] se refiere al eje x                              #
#   y[2,n] se refiere la eje y                              #
#                                                           #
# f(xn)=Cf1+Cf2(x-x1)+Cf3(x-x1)(x-x2)+...+Cfn(x-x1)...(x-xn)#
#                                                           #
#         funcion polinomio_newton(Y,*S)                    #
#                                                           #
funcion polinomio_newton(Y,*S)
   local err, i, n, Fact, Pol, Cfi, P, kx, ret
   err=dif_div_newton(Y,Fact)
   si err retornar err finsi
   n=profdim(Y,2)
   array kx[n]
   paratodo i=1 hasta n
      kx[i]=Y[1,i]
   volver
   err=prod_polinom_newton(kx,Pol)
   si err retornar err finsi
   array Cfi[n] #Coeficientes...#
   paratodo i=1 hasta n
      Cfi[i]=Fact[i,i]
   volver
   ret=coeficientes(Cfi,Pol,P)
   ret=polinomio(P,x,S)
fin