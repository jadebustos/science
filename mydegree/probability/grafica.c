#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>

/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */                                                                            
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*--------------------------------------------------------------------------
                     FUNCION QUE DIBUJA LA GRAFICA
--------------------------------------------------------------------------*/

void dibujar_grafica(void)

{
setcolor(WHITE);

/* EJES DE COORDENADAS */

line(240,80,240,470);  /* X */
line(200,430,580,430); /* Y */

/* ROTULO DEL EJE Y DE COORDENADAS */

outtextxy(254,440,"2"); outtextxy(284,440,"3"); outtextxy(314,440,"4");
outtextxy(344,440,"5"); outtextxy(374,440,"6"); outtextxy(404,440,"7");
outtextxy(434,440,"8"); outtextxy(464,440,"9"); outtextxy(490,440,"10");
outtextxy(520,440,"11");        outtextxy(550,440,"12");

/* ESCALA */

outtextxy(225,424-obtencion_altura(1.),"1");
line(235,430-obtencion_altura(1.),240,430-obtencion_altura(1.));

outtextxy(205,424-obtencion_altura(1./2),"1/2");
line(235,430-obtencion_altura(1./2),240,430-obtencion_altura(1./2));

outtextxy(205,424-obtencion_altura(1./3),"1/3");
line(235,430-obtencion_altura(1./3),240,430-obtencion_altura(1./3));

outtextxy(205,424-obtencion_altura(1./4),"1/4");
line(235,430-obtencion_altura(1./4),240,430-obtencion_altura(1./4));

outtextxy(205,424-obtencion_altura(1./5),"1/5");
line(235,430-obtencion_altura(1./5),240,430-obtencion_altura(1./5));

outtextxy(205,424-obtencion_altura(1./6),"1/6");
line(235,430-obtencion_altura(1./6),240,430-obtencion_altura(1./6));

outtextxy(205,424-obtencion_altura(1./8),"1/8");
line(235,430-obtencion_altura(1./8),240,430-obtencion_altura(1./8));

outtextxy(197,424-obtencion_altura(1./12),"1/12");
line(235,430-obtencion_altura(1./12),240,430-obtencion_altura(1./12));

/* IMPRESION DE LAS PROBABILIDADES */

setcolor(WHITE);
outtextxy(1,300,"P(2) = 1/36");
outtextxy(1,310,"P(3) = 1/18");
outtextxy(1,320,"P(4) = 1/12");
outtextxy(1,330,"P(5) = 1/9");
outtextxy(1,340,"P(6) = 5/36");
outtextxy(1,350,"P(7) = 1/6");
outtextxy(1,360,"P(8) = 5/36");
outtextxy(1,370,"P(9) = 1/9");
outtextxy(1,380,"P(10) = 1/12");
outtextxy(1,390,"P(11) = 1/18");
outtextxy(1,400,"P(12) = 1/36");

}

/*-------------------------------------------------------------------------
        GRAFICA DE LA PROBABILIDAD DE LOS DIFERENTES RESULTADOS
-------------------------------------------------------------------------*/

void grafica(void)

{
/* prob[n] PROBABILIDAD DE QUE SALGA n+2 */

float prob[] = {
        1./36, 1./18, 1./12, 1./9, 5./36, 1./6,
        5./36, 1./9, 1./12, 1./18, 1./36
                 };
int i; /* CONTADOR */

setfillstyle(SOLID_FILL,LIGHTBLUE);

for (i=0;i<11;++i)
        {
        setcolor(WHITE);
        bar(241+(30*i),430-obtencion_altura(prob[i]),241+(30*(i+1)),430);
        rectangle(241+(30*i),430-obtencion_altura(prob[i]),241+(30*(i+1)),
                  430);
        }
}

/*-------------------------------------------------------------------------
     FUNCION QUE CALCULA LA ALTURA CORRESPONDIENTE A UNA PROBABILIDAD
-------------------------------------------------------------------------*/

int obtencion_altura(double probabilidad)

{
/* EL FACTOR DE CONVERSION UTILIZADO SERA EL SIGUIENTE:
   SI LA PROBABILIDAD ES 0.03 SU ALTURA EN LA GRAFICA SERA 0.03*350 */

int resultado;
resultado = ceil((probabilidad*350));

return (resultado);
}

/*------------------------------------------------------------------------
    FUNCION QUE DIBUJA LA GRAFICA EN FUNCION DE LOS RESULTADOS OBTENIDOS
-------------------------------------------------------------------------*/

void grafica_exp(unsigned long int sum_num[], unsigned long int n_exp)

{
unsigned long int k; /* CONTADOR */
float numero=n_exp;

setfillstyle(LTSLASH_FILL, GREEN);

for(k=0;k<11;++k)
        {
        setcolor(GREEN);
        bar(241+(30*k),430-obtencion_altura(sum_num[k]/numero),
            241+(30*(k+1)),430);
        setcolor(WHITE);
        rectangle(241+(30*k),430-obtencion_altura(sum_num[k]/numero),
                241+(30*(k+1)),430);
        }
}

/*-------------------------------------------------------------------------
          IMPRIME TEXTO EN EL MODO GRAFICO Y DEVUELVE LA TECLA 
                PULSADA QUE INDICA LA OPCION A REALIZAR  
-------------------------------------------------------------------------*/

char texto(unsigned long int *ptexpe, unsigned long int n_exp,
           unsigned long int sum_num[])

{
char res;   /* RESPUESTA */

/* VARIABLE DE CONTROL, SI VALE 0 LA GRAFICA DE LAS PROBABILIDADES ESTA
   EN OFF, MIENTRASQUE SI VALE 1 ESTA EN ON(SUPERPUESTA A LA DE LOS
   EXPERIMENTOS) */

unsigned int control = 0;

gotoxy(1,2);
printf("N§ de experimentos: %lu", n_exp);
gotoxy(1,4);
printf("Experimentos de %lu en %lu", *ptexpe, *ptexpe);

setcolor(GREEN);
outtextxy(1,150,"C");
outtextxy(1,170,"R");
outtextxy(1,190,"G");
outtextxy(1,210,"F");

setcolor(WHITE);
outtextxy(15,150,"Continuar");
outtextxy(15,170,"Aumentar el ritmo");
outtextxy(15,190,"Mostrar graf.prob (On/Off)");
outtextxy(15,210,"Finalizar");

setcolor(LIGHTBLUE);
outtextxy(191,190,"O");


res = 't';

do
        {
        if ( res == 'F')
                {
                res = 'F';
                return (res); /* FIN */
                }
        else if (res == 'R')
                {
                gotoxy(1,4);
                printf("                                             ");
                gotoxy(1,4);
                printf("Introduce nueva variacion: ");
                scanf("%ld", ptexpe);
                gotoxy(1,4);
                printf("                                   ");
                res = 'C';
                break;
                }
        else if ( res == 'G' )
                {
                do
                        {
                        if ( control == 0 ) /* SUPERPONER GRAFICA */
                                {
                                grafica ();
                                setcolor(LIGHTBLUE);
                                outtextxy(167,190,"O");
                                setcolor(WHITE);
                                outtextxy(191,190,"O");
                                control = 1;
                                }
                        else if ( control == 1 ) /* EXPERIMENTAL */
                                {
                                borrar (); /* BORRAR GRAFICA ANTERIOR */
                                grafica_exp(sum_num,n_exp);
                                setcolor(WHITE);
                                outtextxy(167,190,"O");
                                setcolor(LIGHTBLUE);
                                outtextxy(191,190,"O");
                                control = 0;
                                }

                        res = 't';
                        }

                while( res == 'G' );
                }

        res = leer_tecla ();
        }
while ( res != 'C' );

return (res);
}
