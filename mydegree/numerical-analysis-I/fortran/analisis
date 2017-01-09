#    Calculo del limite de una funcion aplicando la definicion de limite   #
#    Fijando h=10^-6, el error permitido 10^-5.                            #
#    Recibe una cadena en f como funcion a buscar el limite, una referencia#
#    x, que es la variable en la que busca el valor del limite si lo hay y #
#    a, que es el punto al que tiende x.                                   #
#    si lim(x->a)(f).                                                      #
#                                                                          #
#                     limite(f,*x,a)                                       #
#                                                                          #
funcion limite(f,*x,a)
   local izda,dcha, h, Error
   Error=10^-6   #Margen de error entre el limite por la izda y por la dcha #
                 # de 10^-5 #
   h=5*10^-7     # Incremento de 10^-7         #
   x=a+h
   dcha=calcula(f)
   x=a-h
   izda=calcula(f)
   si abs(dcha-izda)<10^-5 x=(dcha+izda)/2 retornar 0 finsi
   si signo(dcha)<>signo(izda)
      x=0
   finsi
   si signo(dcha)=signo(izda)
      retornar 10^290*signo(izda)
   finsi
   retornar 1
fin
#    Calculo del limite de una funcion aplicando la definicion de limite   #
#    Fijando h=10^-6, el error permitido 10^-5.                            #
#    Recibe una cadena en f como funcion a buscar el limite, una referencia#
#    x, que es la variable en la que busca el valor del limite si lo hay y #
#    a, que es el punto al que tiende x.                                   #
#    si lim(x->a)(f).                                                      #
#                                                                          #
#                     limite(f,*x,a)                                       #
#                                                                          #
funcion derivada(f,*x,a)
   local n1, n2, h,  d1, d2
   h=10^-5       # Un incremento de e-12 #    
                  # Probablemente, ante pendientes muy grandes este metodo#
                  # no sea el mas adecuado. #
   x=a+h          # Derivada en un punto por la derecha. #

   n1=calcula(f)
   x=a
   n2=calcula(f)
   d1=(n1-n2)/(h)
   n2=calcula(f)
   x=a-h
   n1=calcula(f)
   d2=(n1-n2)/-h
   x=(d1+d2)/2 
   retornar 1
fin
#     Funcion que calcula el area que encierra una curva y dos puntos.   #
#     Integral definida entre los puntos a y b utilizando para ello el   #
#     metodo del trapecio. Recibe como parametros la funcion Str, la va- #
#     riable independiente x como referencia. El limite inferior, el li- #
#     mite superior y el numero de particiones.                          #
#                                                                        #
#           funcion trapecio(Str,*X,Li,Ls,Np)                            #
#                                                                        #
funcion trapecio(Str,*X,Li,Ls,Np)
   local i, step, fx1, suma, xi
   Np=abs(Np)
   si Li>Ls i=Li Li=Ls Ls=i finsi
   si Np=0||Np=1 step=abs(Li-Ls) sino step=Li+(Ls-Li)/Np finsi
   suma=0
   paratodo X=Li+step hasta Ls-step paso step
      suma=suma+calcula(Str)
   volver
   suma=suma*2
   X=Li
   suma=suma+calcula(Str)
   X=Ls
   suma=suma+calcula(Str)
   si Np<>0 suma=suma/(2*Np) sino suma=suma/2 finsi
   suma=suma*(Ls-Li)
   X=suma
   retornar suma
fin
