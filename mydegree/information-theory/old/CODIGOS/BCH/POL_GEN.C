
/* PROGRAMA PARA EL CALCULO DE UN POLINOMIO GENERADOR DE UN CODIGO CICLICO */

#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include "primos.c"
#include "polinom.c"
#include "polipoli.c"
#include "lispolis.c"
#include "fich.c"


LISTA lista_primos;                     /* Lista de factores primos */
POLINOMIO primitivo, beta, generador;   /* Polinomio primitivo, elemento beta y polinomio generador */
POLINOMIOS lista_irreducibles;          /* Lista de los irreducibles de las potencias de beta, sobre Zp */



unsigned int Leer_Caracteristica_Cuerpo ()
{
  int p;

  do
  {
    printf ("\nCaracteristica del cuerpo (primo mayor o igual que 2): ");
    scanf ("%d",&p);
  }
  while (p < 2);

  return (p);
}



unsigned int Leer_Longitud_Palabras (p)
unsigned int p;
{
  int n;
  unsigned int primos_p_n = 0;

  do
  {
    printf ("Longitud de las palabras codigo (mayor o igual que 3 y primo con %u): ", p);
    scanf ("%d",&n);

    primos_p_n = (n > p) ? (n % p) : (p % n);
  }
  while ((n < 3) || (!primos_p_n));

  return (n);
}



unsigned int Leer_Numero_Errores (n)
unsigned int n;
{
  int t;
  unsigned int maxt;

  maxt = (n % 2) ? (n / 2) + 1 : (n / 2);

  do
  {
    printf ("\nNumero de errores a corregir (mayor que 0 y menor que %u): ", maxt);
    scanf ("%d",&t);

  }
  while ((t < 1) || (t >= maxt));

  return (t);
}



void Generar_Primos (raiz_n)
unsigned int raiz_n;
{
  unsigned int i;

  Crear_Lista (&lista_primos);

  /* Se inserta el primer primo distinto de 1 */
  Insertar_Elemento (&lista_primos, 2);

  /* Se generan los primos hasta raiz de n */
  for (i = 3; i <= raiz_n; i += 2)
  {
    /* Si i es primo, se inserta en la lista */
    if (Es_Primo (lista_primos, i))
      Insertar_Elemento (&lista_primos, i);
  }
}



void Descomponer_en_Primos (n)
unsigned int n;
{
  unsigned int cociente;

  /* Buscar el primer factor primo e incrementar su potencia en la lista de factores */
  cociente = Buscar_Factor (lista_primos, n);

  /* Seguir recursivamente hasta que lo que quede por descomponer sea 1 */
  if (cociente !=1)
    Descomponer_en_Primos (cociente);
}



/* CALCULO DE LA FI DE EULER DE n, QUE SERA EL GRADO DEL POLINOMIO PRIMITIVO */

unsigned int Fi_de_Euler (n)
unsigned int n;
{
  unsigned int factor, potencia;
  unsigned int fi_de_n = 1;

  /* Generar todos los primos hasta raiz cuadrada de n */
  Generar_Primos ((unsigned int) ceil (sqrt ((double) n)));

  /* Descomponer n en factores primos */
  Descomponer_en_Primos (n);

  while (!Es_Vacia (lista_primos))
  {
    Extraer_Elemento (&lista_primos, &factor, &potencia);

    if (potencia)
      fi_de_n *= ((unsigned int) pow ((double) factor, (double) (potencia - 1))) 
                 * (factor - 1);
  }

  printf ("\nFi de Euler (%u) = %u\n\n", n, fi_de_n); 

  return (fi_de_n);
}



/* CALCULO DE UN ELEMENTO beta DE Zp[x]/<p(x)> DE ORDEN n */

void Calcular_Beta (p, g, n)
unsigned int p, g, n;
{
  POLINOMIO alfa, q;
  unsigned int grado;

  /* Dado que p(x) es primitivo, una forma de calcular beta es como  
     el resto de la division de x^(((p^Fi (n)) - 1) / n) entre p(x) */

  printf ("beta = ");
  
  grado = (((unsigned int) pow ((double) p, (double) g)) - 1) / n;

  Crear_Polinomio (&alfa, grado);

  Poner_Valor_Polinomio (alfa, grado, 1);

  Dividir_Polinomios (alfa, primitivo, &q, &beta, p);

  Ver_Polinomio (beta, 'x'); 
  printf ("\n\n");

  Destruir_Polinomio (&alfa);
  Destruir_Polinomio (&q); 
}



/* CALCULO Y ALMACENAMIENTO DE LAS POTENCIAS DE LA POTENCIA ACTUAL DE beta, 
   DE LA FORMA (potencia_beta)^(p^j),
   CON j = 0, 1, ..., k - 1, 
   DONDE (potencia_beta)^(p^k) = potencia_beta */

void Construir_Potencias_Beta (potencias_beta, potencia_beta, pot, p)
POLINOMIOS *potencias_beta;
POLINOMIO potencia_beta;
unsigned int pot, p;
{
  unsigned int i, exp;
  unsigned char iguales;
  POLINOMIO temp1, temp2, cociente, resto;

  Crear_Lista_P (potencias_beta);
  Insertar_Polinomio_Lista_P (potencias_beta, potencia_beta);

  i = 1;
  iguales = 0;

  Copiar_Polinomio (potencia_beta, &temp1);

  while (!iguales)
  {
    exp = ((unsigned int) pow ((double) p, (double) i));

    /* potencia_beta^(p^j) = (potencia_beta^(p^(j - 1)))^p,
       es decir, se eleva la anterior a p */ 
    Potencia_Polinomio (temp1, p, &temp2, p);
    Dividir_Polinomios (temp2, primitivo, &cociente, &resto, p);

    if (pot != 1)
      printf ("(beta^%u)^%u = ", pot, exp);         
    else
      printf ("beta^%u = ", exp); 

    Ver_Polinomio (resto, 'x');             

    if (!Son_Iguales_Polinomios (potencia_beta, resto))
    {
      Insertar_Polinomio_Lista_P (potencias_beta, resto);
      Destruir_Polinomio (&temp1);
      Copiar_Polinomio (resto, &temp1);
      printf ("\n");
    }
    else
    {
      if (pot != 1)
        printf (" = beta^%u\n", pot);
      else
        printf (" = beta\n");
      Destruir_Polinomio (&temp1);
      iguales++;
    }

    Destruir_Polinomio (&temp2);
    Destruir_Polinomio (&cociente);
    Destruir_Polinomio (&resto);
    i++;
  }
}



/* EL IRREDUCIBLE DE LA POTENCIA ACTUAL DE beta ES UN POLINOMIO DE (Zp[x]/p(x))[y],
   QUE SE CALCULA COMO EL PRODUCTO DE TODOS LOS FACTORES DE LA FORMA
   (y - (potencia_beta)^j) CON j = 1, ..., k - 1 */

void Construir_Irreducible (potencias_beta, pot, p)
POLINOMIOS *potencias_beta;
unsigned int pot, p;
{
  POLI_POLI A, B, C;
  POLINOMIO uno, cero, temp1, temp2, irreducible;
  unsigned int i = 0, exp;

  Crear_Polinomio (&cero, 0);
  Crear_Polinomio (&uno, 0);
  Poner_Valor_Polinomio (uno, 0, 1);

  Crear_Poli_Poli (&A, 0);
  Poner_Valor_Poli_Poli (A, 0, uno);

  while (!Es_Vacia_Lista_P (*potencias_beta))
  {
    Extraer_Polinomio_Lista_P (potencias_beta, &temp1);
    Restar_Polinomios (cero, temp1, &temp2, p);
    Crear_Poli_Poli (&B, 1);
    Poner_Valor_Poli_Poli (B, 0, temp2);
    Poner_Valor_Poli_Poli (B, 1, uno);

    Multiplicar_Poli_Poli (A, B, &C, p);
    Destruir_Poli_Poli (&A);

    Copiar_Poli_Poli (C, &A);
 
    Destruir_Poli_Poli (&B);  
    Destruir_Poli_Poli (&C);
    Destruir_Polinomio (&temp1);
    Destruir_Polinomio (&temp2);
    i++;      
  }

  PoliPoli_a_Polinomio (A, &irreducible, p);
  Destruir_Poli_Poli (&A);

  exp = ((unsigned int) pow ((double) p, (double) i - 1)); 

  if (pot != 1)
  {
    printf("Irr (beta^%u, Z%u) = [y - beta^%u]", pot, p, pot);

    if (exp != 1)
      printf(" ... [y - (beta^%u)^%u]", pot, exp);  

    printf(" =\n                 = ");     
  }
  else
  {
    printf("Irr (beta, Z%u) = [y - beta]", p);  

    if (exp != 1)
      printf(" ... [y - beta^%u]", exp); 

    printf(" =\n               = ");
  }

  Ver_Polinomio (irreducible, 'y'); 
  printf ("\n");       
  
  if (!Existe_Polinomio_Lista_P (lista_irreducibles, irreducible))
    Insertar_Polinomio_Lista_P (&lista_irreducibles, irreducible);

  Destruir_Polinomio (&irreducible);
}



/* PARA TODO j = 1, ..., i - 1, 
   SI i/j ES POTENCIA DE p,
   ENTONCES EL IRREDUCIBLE DE beta^i Y EL DE beta^j SON IGUALES */

unsigned int Irreducible_Calculado (i, p)
unsigned int i, p;
{
  unsigned int j = 1, a;

  while (j < i)
  {
    if ((i % j) == 0)
    {
      a = i / j;

      while (((a % p) == 0)  &&  ((a = (a / p)) > p));

      if ((a == p) || (a == 1)) 
        return (j);
    }

    j++;
  }

  return (0);
}



/* CALCULO DE LOS IRREDUCIBLES DE LAS POTENCIAS DE beta, DESDE 1 HASTA 2t, EN Zp */

void Construir_Lista_Irreducibles (t, p)
unsigned int t, p;
{
  unsigned int i, num_irreducibles, pot;
  POLINOMIO potencia_beta, cociente, resto;
  POLINOMIOS potencias_beta;

  Crear_Lista_P (&lista_irreducibles);

  i = 1;
  num_irreducibles = 2 * t;

  while (i <= num_irreducibles)
  {
    if (i != 1)
      printf ("\nIrr (beta^%u, Z%u) :\n", i, p);  
    else
      printf ("\nIrr (beta, Z%u) :\n", p);

    if (pot = Irreducible_Calculado (i, p))
    {
      /* Los irreducibles ya conocidos no se calculan */
      printf ("Irr (beta^%u, Z%u) = ", i, p);

      if (pot != 1)  
        printf ("Irr (beta^%u, Z%u)\n", pot, p);
      else
        printf ("Irr (beta, Z%u)\n", p);      
    }
    else
    {
      /* Calculo de la potencia i-esima de beta, modulo p(x) */
      Potencia_Polinomio (beta, i, &potencia_beta, p);
      Dividir_Polinomios (potencia_beta, primitivo, &cociente, &resto, p);

      if (i != 1)
        printf ("beta^%u = ", i);  
      else
        printf ("beta = ");

      Ver_Polinomio (resto, 'x');          
      printf ("\n");                          

      /* Calculo y almacenamiento de las potencias de la potencia i-esima de beta, 
         de la forma (potencia i-esima de beta)^(p^j),
         con j = 0, 1, ..., k - 1, 
         donde (potencia i-esima de beta)^(p^k) = potencia i-esima de beta */
      Construir_Potencias_Beta (&potencias_beta, resto, i, p);

      /* El irreducible es un polinomio de (Zp[x]/p(x))[y], que se calcula como
         el producto de todos los factores de la forma
         (y - (potencia i-esima de beta)^j) con j = 1, ..., k - 1 */
      Construir_Irreducible (&potencias_beta, i, p);

      Destruir_Polinomio (&potencia_beta);
      Destruir_Polinomio (&cociente);
      Destruir_Polinomio (&resto);
    }

    i++;
  }
}



/* EL GENERADOR ES EL PRODUCTO DE TODOS LOS IRREDUCIBLES DISTINTOS */

void Construir_Polinomio_Generador (t, p)
unsigned int t, p; 
{
  POLINOMIO temp1, temp2;

  Crear_Polinomio (&generador, 0);
  Poner_Valor_Polinomio (generador, 0, 1);


  while (!Es_Vacia_Lista_P (lista_irreducibles))
  {
    Extraer_Polinomio_Lista_P (&lista_irreducibles, &temp1);
    Multiplicar_Polinomios (generador, temp1, &temp2, p);
    Destruir_Polinomio (&generador);

    Copiar_Polinomio (temp2, &generador);

    Destruir_Polinomio (&temp1);
    Destruir_Polinomio (&temp2);      
  }

  printf ("\ng(y) = m.c.m. [Irr (beta, Z%u), ..., Irr (beta^%u, Z%u)] =\n", p, 2*t, p); 
  printf ("     = ");
  Ver_Polinomio (generador, 'y'); 
  printf ("\n\n");
}



main ()
{
  unsigned int n;  /* Longitud de las palabras codigo */
  unsigned int p;  /* Caracteristica del cuerpo */
  unsigned int g;  /* Grado del polinomio primitivo sobre Zp */
  unsigned int t;  /* Distancia minima de las palabras codigo */


  p = Leer_Caracteristica_Cuerpo ();
  n = Leer_Longitud_Palabras (p);

  g = Fi_de_Euler (n);

  Buscar_Primitivo_en_Fichero (p, g);

  Calcular_Beta (p, g, n);

  t = Leer_Numero_Errores (n);

  Construir_Lista_Irreducibles (t, p);

  Construir_Polinomio_Generador (t, p);

  Destruir_Polinomio (&primitivo);
  Destruir_Polinomio (&beta);
  Destruir_Polinomio (&generador);
}

