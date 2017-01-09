#    					 	        #
#   funcion factorial. 	                                # 
#   Recibe como parametro un numero y devuelve un valor #
#   que es el factorial de ese numero.		        #
#      si x<=1 devolvemos 1                             #
funcion factorial(x)
    si x<=1 resultado=1
    sino resultado=x
         resultado=resultado*factorial(x-1)
    finsi
    retornar resultado
fin
#                                                                   #
#  Funcion que recibe como paramtero una funcion y no devuelve nada #
#   simplemente la escribe por pantalla                             #
funcion escr_matriz(m) 
  local i,j
  si maxdims(m)<>2 retornar 1 finsi
  paratodo i=1 hasta profdim(m,1)
  paratodo j=1 hasta profdim(m,2)
     escribe m[i,j]," ";
  volver
  escribe ""
  volver
fin
#                                                                    #
# Funcion que devuelve el signo de una expresion.                    #
# Recibe como parametros un valor                                    #
# Devuelve -1 si es negativo, 0 si es 0 y 1 si es positivo           #
#              funcion signo(x)                                      #
funcion signo(x)
   si x<0 retornar -1 finsi
   si x>0 retornar 1 finsi
   retornar 0
fin
#   funcion que calcula el valor absoluto de una funcion #
#   abs(x)=x si x>=0. abs(x)=-x si x<0 #
#              funcion abs(x)          #
funcion abs(x)
  si x>=0 retornar x
  sino retornar -1*x
  finsi
fin
#  Funcion que calcula los maximos en x y en y en el modo   #
#  grafico, recibe como parametros dos referencias, mx, my  #
#                                                           #
#         Funcion Max_Graf(*MX,*MY)                         #
#                                                           #
funcion Max_Graf(*MX,*MY)
   local holdf
   holdf=mgrafico()
   MX=maxx()
   MY=maxy()
   holdf=mtexto()
fin
#  Funcion que calcula los puntos en 2D para luego dibujar  #
#  una funcion matematica o para cualquier otra cosa. Es    #
#  Recibe como parametros una funcion matematica, la varia- #
#  ble independiente, el numero de puntos en el eje X, y un #
#  array 2D para representar estos puntos en funcion de las #
#  'X' y de las 'Y'. Y el intervalo arepresentar en X       #
#                                                           #
#     funcion calcula_ptos2D(Str,*X,*Arr, MaxX,ex)          #
#                                                           #
funcion calcula_ptos2D(Str,*X,*Arr, MaxX,ex)
   si MaxX=0 retornar 1 finsi
   local step,i
   array Arr[MaxX]
   step=abs(ex)*2/MaxX 
   X=abs(ex)
   paratodo i=1 hasta MaxX
      Arr[i]=calcula(Str)
      X=X-step
   volver
fin
#  Funcion que traza una curva en 2D. Recibe como parametros#
#  un array con los puntos, los valores maximos en pantalla #
#  de los ejes X e Y y el maximo logico de las Y.           #
#                                                           #
#     funcion traza_2D(hold,mx,my,ey,c)                     #
#                                                           #
funcion traza_2D(hold,mx,my,ey,c)
   si mx=0 retornar 1 finsi
   local max, i,step, y1, dibujado
   local xt, xgrf, ygrf, yt, holdf
   xt=mx-1
   dibujado=0
   paratodo i=1 hasta mx
      y1=(my/2)-(my/2)*hold[i]/ey
      si (y1>0)&(y1<my)
        si dibujado<>0
           holdf=linea(xgrf,ygrf,xt,y1,c)
        sino
           si y1<=0
              ygrf=my
           sino
              ygrf=0
           finsi
           si i<>1
              holdf=linea(xt,ygrf,xt,y1,c)
           sino
              holdf=punto(xt,yt,c)
           finsi
        finsi
        xgrf=xt
        ygrf=y1
        dibujado=1
      sino
        si dibujado<>0
           si y1>my
              holdf=linea(xgrf,ygrf,xt,my,c)
           sino
              holdf=linea(xgrf,ygrf,xt,0,c)
           finsi
        finsi
        dibujado=0 
      finsi
      xt=xt-1
      hold[i]=ygrf
   volver
fin
#  Funcion que dibuja una funcion matematica. Recibe como   #
#  parametros una funcion, una variable dependiente X(ref.) #
#  y unos margenes x,y simetricos(desde -x..x y -y..y)      #
#       funcion dibuja(Str,*X,ex,ey)                        #
#                                                           #
funcion dibuja(Str,*X,ex,ey)
   local mx, my,hold,holdf
   holdf=Max_Graf(mx,my)
   holdf=calcula_ptos2D(Str,X,hold,mx,ex)
   holdf=mgrafico()
   holdf=ejes(ex,ey)
   holdf=traza_2D(hold,mx,my,ey,2)
   vgatecla 
   holdf=mtexto()
fin
#  Funcion que dibuja 2 funciones... #
funcion dibuja2f(Str1,Str2,*X,ex,ey)
   local c, mx, my
   local hold1,hold2,max,i,step, holdf
   holdf=Max_Graf(mx,my)
   holdf=calcula_ptos2D(Str1,X,hold1,mx,ex)
   holdf=calcula_ptos2D(Str2,X,hold2,mx,ex)
   holdf=mgrafico()
   holdf=ejes(ex,ey)
   holdf=traza_2D(hold1,mx,my,ey,2)
   holdf=traza_2D(hold2,mx,my,ey,4)
   vgatecla 
   holdf=mtexto()
fin
#   Funcion que recibe como parametros un array de 2xN, el maximo en #
#   x, el maximo en y y dibuja el conjunto de puntos.                #
#                                                                    #
#        funcion dibuja_puntos(K,ex,ey,mx,my)                        #
#                                                                    #
funcion traza_puntos(K,ex,ey,mx,my,c)
   si maxdims(K)<>2 retornar 1 finsi
   si mx=0 retornar 2 finsi
   local i,n,x1,y1, holdf
   n=profdim(K,2)
   paratodo i=1 hasta n
      y1=(my/2)-(my/2)*K[2,i]/ey
      x1=(mx/2)+(mx/2)*K[1,i]/ex
      hodlf=linea(x1-2,y1-2,x1+2,y1+2,c)
      holdf=linea(x1+2,y1-2,x1-2,y1+2,c)
   volver
fin
##
#   Funcion que dibuja un conjunto de puntos. #
funcion dibuja_puntos(K)
   local c, mx, my,i, Np, ex,ey
   local hold1,step, X, holdf
   Np=profdim(K,2)
   holdf=Max_Graf(mx,my)
   si mx=0 retornar 2 finsi
   paratodo i=1 hasta Np
      si abs(K[1,i]>ex) ex=abs(K[1,i]) finsi
      si abs(K[2,i]>ey) ey=abs(K[2,i]) finsi
   volver
   ex=ex+1
   ey=ey+1
   holdf=calcula_ptos2D(Str,X,hold1,mx,ex)
   holdf=mgrafico()
   holdf=ejes(ex,ey)
   holdf=traza_puntos(K,ex,ey,mx,my,4)
   vgatecla
   holdf=mtexto()  
fin
#   Funcion que recibe como parametros un array de 2xN y una funcion #
#   y dibuja los puntos y la funcion. Su utilidad es ver los puntos  #
#   pasados como parametros a un algoritmo de regresion y la recta o #
#   curva de regresion. Ademas recibe una referencia a la variable   #
#   independiente de la curva.                                       #
#                                                                    #
#            funcion dibuja_ptos_curva(K,Str,*X)                     #
#                                                                    #
funcion dibuja_ptos_curva(K,Str,*X)
   si maxdims(K)<>2 retornar 1 finsi
   local c, mx, my,i, Np, ex,ey
   local hold1,step, holdf
   Np=profdim(K,2)
   holdf=Max_Graf(mx,my)
   si mx=0 retornar 2 finsi
   paratodo i=1 hasta Np
      si abs(K[1,i]>ex) ex=abs(K[1,i]) finsi
      si abs(K[2,i]>ey) ey=abs(K[2,i]) finsi
   volver
   ex=ex+1
   ey=ey+1
   holdf=calcula_ptos2D(Str,X,hold1,mx,ex)
   holdf=mgrafico()
   holdf=ejes(ex,ey)
   holdf=traza_2D(hold1,mx,my,ey,2)
   holdf=traza_puntos(K,ex,ey,mx,my,4)
   vgatecla
   holdf=mtexto()   
fin
