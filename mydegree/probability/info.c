#include <conio.h>

/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */                                                                            
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*-------------------------------------------------------------------------
        FUNCION QUE PROPORCIONA INFORMACION SOBRE EL PROGRAMA
-------------------------------------------------------------------------*/

void informacion(void)

{
clrscr();

textcolor(WHITE);
gotoxy(5,3);
cprintf("Este programa dibuja la grafica de la probabilidad de obtener uno");
gotoxy(5,4);
cprintf("de los 11 resultados posibles que resultan de lanzar dos dados.");

gotoxy(5,6);
cprintf("La grafica en azul representa la probabilidad de obtener cada");
gotoxy(5,7);
cprintf("resultado, mientras la grafica verde representa la probabilidad");
gotoxy(5,8);
cprintf("de obtener cada resultado despues de un numero de experimentos.");
gotoxy(5,10);
cprintf("La grafica azul no va a variar segun incrementemos el numero de");
gotoxy(5,11);
cprintf("experimentos, mientras que la verde si lo hara.");
gotoxy(5,13);
cprintf("El proposito de este programa es ver, que, cuantos mas experimentos"),
gotoxy(5,14);
cprintf("realizemos la grafica verde(realizacion practica del experimento)");
gotoxy(5,15);
cprintf("se aproximara a la azul(verdaderas probabilidades).");
gotoxy(5,20);
cprintf("Pulsa una tecla para continuar.");

getch();

clrscr ();
gotoxy(5,3);
cprintf("Para continuar en el programa o realizar otro experimento");
gotoxy(5,4);
cprintf("presione \"c\", mientras para finalizar presione \"f\".");
gotoxy(5,6);
cprintf("Si durante la realizacion de los experimentos se presiona");
gotoxy(5,7);
cprintf("la tecla\"c\" se realizara otro experimento, es decir, el");
gotoxy(5,8);
cprintf("lanzamiento de los dos dados, para comprobar su suma, y");
gotoxy(5,9);
cprintf("modificar la grafica verde en funcion de los resultados");
gotoxy(5,10);
cprintf("obtenidos, si se quieren realizar mas rapido los experimentos");
gotoxy(5,11);
cprintf("entonces presione \"r\" y a continuacion teclee el numero de");
gotoxy(5,12);
cprintf("experimentos que quiere que se realizen cada vez que se presione");
gotoxy(5,13);
cprintf("la tecla \"c\".");
gotoxy(5,15);
cprintf("Si quiere superponer la grafica de la probabilidad de obtener");
gotoxy(5,16);
cprintf("cada resultado para contrastarla con la dada por los experimentos");
gotoxy(5,17);
cprintf("realizados, presione \"g\" y si vuelve a presionar \"g\" ver  la");
gotoxy(5,18);
cprintf("grafica dada por el numero de experimentos realizados.");
gotoxy(5,20);
cprintf("Pulsa una tecla para comenzar los experimentos(\"c\",\"f\"):");

}
