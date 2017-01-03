/*                                                                      */
/*                      (c) 1996 Jose Angel de Bustos Perez             */                                                                            
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */

/*-------------------------------------------------------------------------
              FUNCION QUE SIMULA EL LANZAMIENTO DE LOS DADOS
-------------------------------------------------------------------------*/

void dados(unsigned long int sum_num[])

{
int dado1; /* RESULTADO DEL LANZAMIENTO DEL PRIMER DADO */
int dado2; /* RESULTADO DEL LANZAMIENTO DEL SEGUNDO DADO */
int final; /* PUNTUACION ENTRE LOS DOS DADOS */

dado1 = num_aleatorio(6);
dado2 = num_aleatorio(6);

final = dado1 + dado2;

sum_num[final-2]+=1;

return;
}

