       PROGRAM prog1

C Se pide desde teclado el radio de un circulo y muestra por
C pantalla el �rea del circulo

       REAL radio, area

C Peticion de datos
 
       PRINT *,'Introduce el radio del circulo: '
       READ *,radio

C Calculo del �rea del circulo

       area=3.14159*(radio**radio)

C Mostrar los resultados

       PRINT *,'El �rea del circulo es',area

       STOP
       END
