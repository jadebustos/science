#                                                                        #
#   Funcion que calcula una raiz de una ecuacion basandose en el metodo  #
#   de la biseccion. Recibe como parametros una cadena que representa la #
#   funcion, la variable de la funcion, dos puntos con distinto signo y  #
#   por en la variable de la funcion, en esta devuelve el resultado      #
#                                                                        #
#          funcion biseccion(Str,*X,X0,X1)                               #
#                                                                        #
funcion biseccion(Str,*X,X0,X1)
   local fx0, fx1, med, fmed
   si X1=X0 retornar 2 finsi # No existe un intervalo #
   si X1<X0 med=X1 X1=X0 X0=med finsi
   X=X0
   fx0=calcula(Str)
   X=X1
   fx1=calcula(Str)
   si signo(fx1)=0 X=X1 retornar 0 finsi
   si signo(fx0)=0 X=X0 retornar 0 finsi
   si signo(fx0)=signo(fx1) #La funcion no cambia de signo#
      retornar 1            #y no podemos asegurar que haya una raiz#
   finsi                           
   med=(X1+X0)/2
   X=med
   fmed=calcula(Str)
   si fmed=0 retornar 0 finsi
   si abs(fx0-fx1)<ErrorP 
       retornar 0 
   finsi
   si signo(fx0)<>signo(fmed) X1=med sino X0=med finsi
   retornar biseccion(Str,X,X0,X1)
fin
#                                                                        #
#   Funcion que calcula una raiz de una ecuacion basandose en el metodo  #
#   de la regla falsa. Recibe como parametros una cadena que representa  #
#   la funcion, la variable de la funcion, dos puntos con distinto signo #
#   y en la variable de la funcion, en esta devuelve el resultado        #
#                                                                        #
#          funcion reglafalsa(Str,*X,X0,X1)                              #
#                                                                        #
funcion reglafalsa(Str,*X,X0,X1)
   local fx0, fx1, med, fmed
   si X1=X0 retornar 2 finsi # No existe un intervalo #
   si X1<X0 med=X1 X1=X0 X0=med finsi # Utilizo med como auxiliar. #
   X=X0
   fx0=calcula(Str)
   X=X1
   fx1=calcula(Str)
   si signo(fx1)=0 X=X1 retornar 0 finsi
   si signo(fx0)=0 X=X0 retornar 0 finsi
   si signo(fx0)=signo(fx1) #La funcion no cambia de signo#
      retornar 1            #y no podemos asegurar que haya una raiz#
   finsi
   med=X1-fx1*(X0-X1)/(fx0-fx1)
   X=med
   fmed=calcula(Str)
   si fmed=0 retornar 0 finsi
   si abs(fx0-fx1)<ErrorP retornar 0 finsi
   si signo(fx0)<>signo(fmed) X1=med sino X0=med finsi
   retornar reglafalsa(Str,X,X0,X1)
fin

#                                                                        #
#   Funcion que busca el numero de raices de una ecuacion en un intervalo#
#   Recibe como parametros una cadena que representa la ecuacion         #
#   la varibale independiente de la ecuacion, dos puntos(intervalo), y   #
#   una referencia. En esta referencia, en forma de array se devuelven   #
#   las soluciones. Este es solo un remedio parcial.                     #
#   NOTA: Es posible que se pase alguna solucion si estan muy proximas.  #
#   Al aumentar la longitud del intervalo, aumenta la imprecision, ademas#
#   de aumentar el tiempo que consume la funcion.                        #
#   NOTA: El numero maximo de soluciones son 200                         #
#                                                                        #
#          funcion incrementos(Str,*X,*Sol,X0,X1)                        #
#                                                                        #
funcion incrementos(Str,*X,*Sol,X0,X1)
   local fx0, fx1, incr, tmp, Xn
   local i, num_sol
   array tmp[200]
   incr=0.1   # Incremento. Podemos definir otra cosa, lo que se quiera #
   si X0>X1 i=X0 X0=X1 X1=i finsi
   Xn=X0
   X=Xn
   fx0=calcula(Str)
   paratodo i=X0 hasta X1 paso incr 
      Xn=Xn+incr
      X=Xn fx1=calcula(Str)
      si signo(fx0)<>signo(fx1)         
         num_sol=num_sol+1
         tmp[num_sol]=Xn
      finsi
      fx0=fx1
   volver
   si num_sol=0 retornar 1 finsi
   array Sol[num_sol]
   paratodo i=1 hasta num_sol
      si i=1 
         si !biseccion(Str,X,X0,tmp[i])
            Sol[i]=X
         sino retornar 2
         finsi
      finsi
      si i<>1
         si !biseccion(Str,X,tmp[i-1],tmp[i])
            Sol[i]=X
         sino retornar 2
         finsi
      finsi
   volver
   retornar 0
fin