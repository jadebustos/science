#include <stdio.h>
#include "matriz.c"

#define MIN_m   2    /* minimo valor de m para definir Cm */
#define MAX_m   7    /* maximo valor de m para definir Cm */

#define MIN_k   (1<<MIN_m) - MIN_m - 1    /* minima longitud de los mensajes */
#define MAX_k   (1<<MAX_m) - MAX_m - 1    /* maxima longitud de los mensajes */

#define MIN_n   (1<<MIN_m) - 1            /* minima longitud de los vectores */
#define MAX_n   (1<<MAX_m)                /* maxima longitud de los vectores */

MATRIZ H, Ht, G;           /* matriz control de paridad, su traspuesta y */
                           /* matriz generadora */
unsigned int n, k;         /* longitud de los vectores y de los mensajes */
unsigned char ampliado;    /* indica si el codigo es ampliado o no */
FILE *fichero;             /* fichero de salida de resultados */



/***************************************************************/

int Convertir_a_Entero (s)
char *s;
{
  int i = 0, n = 0;

  while (s[i])
  {
    if ((s[i] >= '0') && (s[i] <= '9'))
    {
      n = 10 * n + s[i] - '0';
      i++;
    }
    else
      return (0);
  }

  return (n);
}


/***************************************************************/

void Caracteristicas_Codigo (m, truncado)
unsigned char *m, *truncado;
{
  char respuesta[256];
  unsigned char definido = 0;

  do
  {
    printf ("    Codigo de Hamming estandar o truncado (e/t)? ");

    gets (respuesta);
    if (!(strcmp (respuesta, "e")))
    {
      do
      {
        printf ("    Valor de m para Cm (min.= %d, max. = %d)? ",MIN_m,MAX_m);

        gets (respuesta);
        if (*m = Convertir_a_Entero (respuesta))
        {
          if ((*m > MAX_m) || (*m < MIN_m))
            *m = 0;
        }
      }
      while (!(*m));

      definido++;
    }
    else
    {
      if (!(strcmp (respuesta, "t")))
      {
        do
        {
          printf ("    Truncar los vectores o los mensajes (n/k)? ");

          gets (respuesta);
          if (!(strcmp (respuesta, "n")))
          {
            do
            {
              printf ("    Valor de n (min.= %d, max. = %d)? ",MIN_n,MAX_n);

              gets (respuesta);
              if (n = Convertir_a_Entero (respuesta))
              {
                if ((n > MAX_n) || (n < MIN_n))
                  n = 0;
              }
            }
            while (!n);

            (*truncado)++;
          }
          else
          {
            if (!(strcmp (respuesta, "k")))
            {
              do
              {
                printf ("    Valor de k (min.= %d, max. = %d)? ",MIN_k,MAX_k);

                gets (respuesta);
                if (k = Convertir_a_Entero (respuesta))
                {
                  if ((k > MAX_k) || (k < MIN_k))
                    k = 0;
                }
              }
              while (!k);

              (*truncado)++;
            }
          }
        }
        while (!(*truncado));

        definido++;
      }
    }
  }
  while (!definido);

  definido--;

  if (n != 3)
  {
    do
    {
      printf ("    Ampliar el codigo para detectar errores dobles (s/n)? ");

      gets (respuesta);
      if (!(strcmp (respuesta, "s")))
      {
        ampliado++;
        definido++;
      }
      else
      {
        if (!(strcmp (respuesta, "n")))
        {
          definido++;
        }
      }
    }
    while (!definido);
  }
}

/***************************************************************/

void Calcular_n_k (m)
unsigned char m;
{
  unsigned int inf, i, nn;

  if (m)
  {
    n = (1<<m) - 1;
    k = (1<<m) - m - 1;
    if (ampliado) n++;
  }
  else
  {
    if (k)
    {
      inf = 0;
      i = 1;

      while (inf < k)
        inf += (1<<i++) - 1;

      n = k + i;
      if (ampliado) n++;
    }
    else
    {
      i = 2;

      if (ampliado)
        nn = n - 1;
      else
        nn = n;

      while ((1<<i) <= nn)
        i++;

      k = nn - i;
    }
  }
}



/***************************************************************/

unsigned char Potencia_de_2 (p)
unsigned int p;
{
  unsigned int mascara;
  unsigned char i, unos;

  if (p == 0)
  {
    return (1);
  }
  else
  {
    mascara = 1;
    unos = 0;

    for (i = 1; (i <= (sizeof(unsigned int) * 8) && (unos <= 1)); i++)
    {
      if (mascara & p) unos++;
      mascara <<= 1;
    }

    return (unos == 1);
  }
}

/***************************************************************/

void Calcular_H ()
{
  unsigned int i, j, nn, mascara;

  Crear_Matriz (&H, n-k, n);

  Dimensiones_Matriz (H,&i,&j);

  if (ampliado)
  {
     nn = n - 1;

     for (i = 1; i <= n; i++)
     {
       Poner_Valor_en_Matriz (H, (n - k), i, 1);
     }
  }
  else
  {
    nn = n;
  }

  for (i = 1; i <= nn; i++)
  {
    mascara = 1;
    for (j = (nn - k); j >= 1; j--)
    {
      if (mascara & i)
        Poner_Valor_en_Matriz (H, j, i, 1);
      mascara <<= 1;
    }
  }
}

/***************************************************************/


void Calcular_G ()
{
  unsigned int i, j, f, nn;

  Crear_Matriz (&G, k, n);

  if (ampliado)
    nn = n - 1;
  else
    nn = n;

  i = 1;
  for (j = 3; j <= nn; j++)
  {
    if (!(Potencia_de_2 (j)))
    {
      Poner_Valor_en_Matriz (G, i++, j, 1);
    }
  }

  for (i = (nn - k); i >= 1; i--)
  {
    f = 1;

    for (j = 3; j <= nn; j++)
    {
      if (!(Potencia_de_2 (j)))
      {
        if (Valor_en_Matriz (H, i, j))
          Poner_Valor_en_Matriz (G, f, (1<<(nn - k - i)), 1);
        f++;
      }
    }
  }

  if (ampliado)
    for (i = 1; i <= k; i++)
      Poner_Valor_en_Matriz (G, i, n, (Peso_Fila(G, i) % 2));
}

/***************************************************************/

void Definir_Codigo ()
{
  unsigned char truncado = 0, m = 0;

  Destruir_Matriz (&H);
  Destruir_Matriz (&Ht);
  Destruir_Matriz (&G);

  n = k = ampliado = 0;

  printf ("> Caracteristicas del Codigo:\n");

  Caracteristicas_Codigo (&m, &truncado);

  if (fichero)
  {
    fprintf (fichero, "- defcod\n");
    fprintf (fichero, "> Caracteristicas del Codigo:\n");

    if (truncado)
    {
      if (n)
        fprintf (fichero, "    Hamming truncado por la longitud de los vectores.\n");
      else
        fprintf (fichero, "    Hamming truncado por la longitud de los mensajes.\n");
    }
    else
    {
      fprintf (fichero, "    Hamming estandar.\n");
      fprintf (fichero, "    Valor de m para Cm: %d.\n", m);
    }

    if (ampliado)
      fprintf (fichero, "    Ampliado para detectar errores dobles.\n");

    Calcular_n_k (m);

    fprintf (fichero, "    Longitud de los vectores: n = %d.\n", n);
    fprintf (fichero, "    Longitud de los mensajes: k = %d.\n", k);
  }
  else
  {
    Calcular_n_k (m);
  }

  printf ("    Longitud de los vectores: n = %d.\n", n);
  printf ("    Longitud de los mensajes: k = %d.\n", k);

  Calcular_H ();
  Matriz_Traspuesta (H, &Ht);
  Calcular_G ();
}


/***************************************************************/

void Ver_Matriz (m)
MATRIZ *m;
{
  unsigned int i, j, filas, columnas;
  FILE *pf;

  if (! Existe_Matriz (*m))
  {
    printf ("> Error: No hay ningun codigo definido.\n");
  }
  else
  {
    Dimensiones_Matriz (*m, &filas, &columnas);

    if (fichero)
    {
      printf ("> Grabando resultados en el fichero de salida ...\n");
      pf = fichero;

      if (m == &H)
        fprintf (pf, "- verh\n");
      else
        fprintf (pf, "- verg\n");
    }
    else
    {
      pf = stdout;
    }

    if (m == &H)
    {
      fprintf (pf, "> Matriz Control de Paridad H:\n");
    }
    else
    {
      fprintf (pf, "> Matriz Generadora G:\n");
    }

    for (i = 1; i <= filas; i++)
    {
      fprintf (pf, "    ");

      for (j = 1; j <= n; j++)
        fprintf (pf, "%d", Valor_en_Matriz (*m, i, j));

      fprintf (pf, "\n");
    }
  }
}

/***************************************************************/

void Codificar_Vector (m, v)
MATRIZ m, *v;
{
  Multiplicar_Matrices (m, G, v);
}


/***************************************************************/

void Codificar ()
{
  unsigned int i;
  unsigned char valido;
  char respuesta[256], *s;
  MATRIZ m, v;
  FILE *pf;

  if (! Existe_Matriz (H))
  {
    printf ("> Error: No hay ningun codigo definido.\n");
  }
  else
  {
    Inicializar_Matriz (&v);

    printf ("> Codificacion de mensajes: \n");

    Inicializar_Matriz (&m);

    do
    {
      Crear_Matriz (&m, 1, k);

      printf ("    Vector Mensaje (%d posiciones): ", k);

      gets (respuesta);
      s = respuesta;
      valido = 1;
      i = 1;

      while ((valido) && (*s != '\0'))
      {
        if (i <= k)
        {
          if (*s == '1')
          {
            Poner_Valor_en_Matriz (m, 1, i, 1);
          }
          else
          {
            if (*s != '0')
              valido--;
          }
          i++;
          s++;
        }
        else
          valido--;
      }

      if ((!valido) || (--i != k))
        Destruir_Matriz (&m);
    }
    while (!Existe_Matriz (m));

    Codificar_Vector (m, &v);

    if (fichero)
    {
      printf ("    Grabando resultados en el fichero de salida ...\n");
      pf = fichero;

      fprintf (pf, "- codif\n");
      fprintf (pf, "> Codificacion de mensajes:\n");
      fprintf (pf, "    Vector Mensaje: %s\n", respuesta);
    }
    else
    {
      pf = stdout;
    }

    fprintf (pf, "    Vector Codigo: ");

    for (i = 1; i <= n; i++)
    {
      if (Valor_en_Matriz (v, 1, i))
        fprintf (pf, "1");
      else
        fprintf (pf, "0");
    }

    fprintf (pf, "\n");

    Destruir_Matriz (&m);
    Destruir_Matriz (&v);
  }
}



/***************************************************************/

void Codificar_Todo ()
{
  unsigned int i;
  unsigned char todos;
  MATRIZ m, v;
  FILE *pf;

  if (! Existe_Matriz (H))
  {
    printf ("> Error: No hay ningun codigo definido.\n");
  }
  else
  {

    Inicializar_Matriz (&v);

    Inicializar_Matriz (&m);
    Crear_Matriz (&m, 1, k);

    if (fichero)
    {
      printf ("> Grabando resultados en el fichero de salida ...\n");
      pf = fichero;

      fprintf (pf, "- codtodo\n");
    }
    else
    {
      pf = stdout;
    }

    fprintf (pf, "> Generacion del codigo:\n");
    todos = 0;

    do
    {
      if (Peso_Fila (m, 1) == k) todos++;

      Codificar_Vector (m, &v);

      fprintf (pf, "    ");   /* mostrar m y v */

      for (i = 1; i <= k; i++)
      {
        if (Valor_en_Matriz (m, 1, i))
          fprintf (pf, "1");
        else
          fprintf (pf, "0");
      }

      fprintf (pf, " -> ");

      for (i = 1; i <= n; i++)
      {
        if (Valor_en_Matriz (v, 1, i))
          fprintf (pf, "1");
        else
          fprintf (pf, "0");
      }

      fprintf (pf, "\n");

      if (!todos)   /* incrementar m */
      {
        i = k;
        while (Valor_en_Matriz (m, 1, i))
          i--;
        Poner_Valor_en_Matriz (m, 1, i, 1);
        i++;
        while (i <= k)
        {
          Poner_Valor_en_Matriz (m, 1, i, 0);
          i++;
        }
      }

      Destruir_Matriz (&v);
    }
    while ( !todos );

    Destruir_Matriz (&m);
  }
}


/***************************************************************/

char Decodificar_Vector (v, m, sd)
MATRIZ v, *m, *sd;
{
  unsigned int s, i, j, suma, nn;

  Multiplicar_Matrices (v, Ht, sd);

  if (ampliado)
  {
    s = n - k - 1;
    nn = n - 1;
  }
  else
  {
    s = n - k;
    nn = n;
  }

  suma = 0;

  for (i = s; i >= 1; i--)
    if (Valor_en_Matriz (*sd, 1, i))
      suma += 1<<(s-i);

  if (ampliado)
  {
    if (Valor_en_Matriz (*sd, 1, n-k))
    {
      if (suma > nn)
      {
        return (-2);
      }
      else
      {
        if (!suma)
          suma = n;

        Poner_Valor_en_Matriz (v, 1, suma, !(Valor_en_Matriz (v, 1, suma)));
      }
    }
    else
    {
      if (suma)
        return (-1);
    }
  }
  else
  {
    if (suma)
    {
      if (suma > n)
        return (-1);
      else
        Poner_Valor_en_Matriz (v, 1, suma, !(Valor_en_Matriz (v, 1, suma)));
    }
  }

  j = 1;

  for (i = 3; i <= nn; i++)
  {
    if (! Potencia_de_2 (i))
    {
      Poner_Valor_en_Matriz (*m, 1, j, Valor_en_Matriz (v, 1, i));
      j++;
    }
  }

  return (suma);
}


/***************************************************************/

void Decodificar ()
{
  unsigned int i;
  unsigned char valido;
  char respuesta[256], *s, resultado;
  MATRIZ m, v, sd;
  FILE *pf;

  if (! Existe_Matriz (Ht))
  {
    printf ("> Error: No hay ningun codigo definido.\n");
  }
  else
  {
    Inicializar_Matriz (&m);
    Crear_Matriz (&m, 1, k);
    Inicializar_Matriz (&sd);

    printf ("> Decodificacion de mensajes: \n");

    Inicializar_Matriz (&v);

    do
    {
      Crear_Matriz (&v, 1, n);

      printf ("    Vector Codigo (%d posiciones): ", n);

      gets(respuesta);
      s = respuesta;
      valido = 1;
      i = 1;

      while ((valido) && (*s != '\0'))
      {
        if (i <= n)
        {
          if (*s == '1')
          {
            Poner_Valor_en_Matriz (v, 1, i, 1);
          }
          else
          {
            if (*s != '0')
              valido--;
          }
          i++;
          s++;
        }
        else
          valido--;
      }

      if ((!valido) || (--i != n))
        Destruir_Matriz (&v);
    }
    while (!Existe_Matriz (v));

    resultado = Decodificar_Vector (v, &m, &sd);

    if (fichero)
    {
      printf ("    Grabando resultados en el fichero de salida ...\n");
      pf = fichero;

      fprintf (pf, "- decod\n");
      fprintf (pf, "> Decodificacion de vectores:\n");
      fprintf (pf, "    Vector Codigo: %s\n", respuesta);
    }
    else
    {
      pf = stdout;
    }


    fprintf (pf, "    Sindrome: ");

    for (i = 1; i <= n-k; i++)
    {
      if (Valor_en_Matriz (sd, 1, i))
        fprintf (pf, "1");
      else
        fprintf (pf, "0");
    }

    if (resultado > 0)
      fprintf (pf, " => %d", resultado);
    fprintf (pf, "\n");

    if (resultado == -2)
    {
      fprintf (pf,"    ");
      fprintf (pf,"Detectado un error impar al menos triple no corregible.\n");     }
    else
    {
      if (resultado == -1)
      {
        fprintf (pf,"    ");
        fprintf (pf, "Detectado un error al menos doble no corregible.\n");
      }
      else
      {
        fprintf (pf, "    Vector Mensaje: ");

        for (i = 1; i <= k; i++)
        {
          if (Valor_en_Matriz (m, 1, i))
            fprintf (pf, "1");
          else
            fprintf (pf, "0");
        }

        fprintf (pf, "\n");
      }
    }

    Destruir_Matriz (&m);
    Destruir_Matriz (&v);
    Destruir_Matriz (&sd);
  }
}



/***************************************************************/

void Decodificar_Todo ()
{
  unsigned int i;
  unsigned char todos;
  char resultado;
  MATRIZ m, v, sd;
  FILE *pf;

  if (! Existe_Matriz (H))
  {
    printf ("> Error: No hay ningun codigo definido.\n");
  }
  else
  {
    Inicializar_Matriz (&m);
    Crear_Matriz (&m, 1, k);

    Inicializar_Matriz (&v);
    Crear_Matriz (&v, 1, n);

    Inicializar_Matriz (&sd);

    if (fichero)
    {
      printf ("> Grabando resultados en el fichero de salida ...\n");
      pf = fichero;

      fprintf (pf, "- dectodo\n");
    }
    else
    {
      pf = stdout;
    }

    fprintf (pf, "> Decodificacion del espacio vectorial: \n");
    todos = 0;

    do
    {
      if (Peso_Fila (v, 1) == n) todos++;

      fprintf (pf, "    ");   /* mostrar v */

      for (i = 1; i <= n; i++)
      {
        if (Valor_en_Matriz (v, 1, i))
          fprintf (pf, "1");
        else
          fprintf (pf, "0");
      }

      resultado = Decodificar_Vector (v, &m, &sd);

      fprintf (pf, " -> ");

      for (i = 1; i <= n-k; i++)    /* mostrar sd */
      {
        if (Valor_en_Matriz (sd, 1, i))
          fprintf (pf, "1");
        else
          fprintf (pf, "0");
      }

      if (resultado > 0)                /* mostrar posicion */
      {
        fprintf (pf, " => %d", resultado);
        Poner_Valor_en_Matriz (v, 1, resultado,
                               !Valor_en_Matriz (v, 1, resultado));
      }
      fprintf (pf, " => ");

      if (resultado == -2)             /* mostrar m o error */
      {
        fprintf(pf,"Detectado un error impar al menos triple no corregible.");
      }
      else
      {
        if (resultado == -1)
        {
          fprintf (pf, "Detectado un error al menos doble no corregible.");
        }
        else
        {
          for (i = 1; i <= k; i++)
          {
            if (Valor_en_Matriz (m, 1, i))
              fprintf (pf, "1");
            else
              fprintf (pf, "0");
          }
        }
      }

      fprintf (pf, "\n");

      if (!todos)   /* incrementar v */
      {
        i = n;
        while (Valor_en_Matriz (v, 1, i))
          i--;
        Poner_Valor_en_Matriz (v, 1, i, 1);
        i++;
        while (i <= n)
        {
          Poner_Valor_en_Matriz (v, 1, i, 0);
          i++;
        }
      }

      Destruir_Matriz (&sd);
    }
    while ( !todos );

    Destruir_Matriz (&m);
    Destruir_Matriz (&v);
  }
}



/**************************************************************/

unsigned int Es_Igual_Vector_a_Fila (v, m, fila)
MATRIZ v, m;
unsigned int fila;
{
  unsigned int film, colm, filv, colv, j, igual;

  Dimensiones_Matriz (m, &film, &colm);
  Dimensiones_Matriz (v, &filv, &colv);

  if ((fila <= film) && (colv == colm))
  {
    j = 1;
    igual = 1;
    while ((igual) && (j <= colm))
    {
      igual = (Valor_en_Matriz (v, 1, j) == Valor_en_Matriz (m, fila, j));
      j++;
    }
  }
  else
  {
    printf ("Error de direccionamiento de la matriz\n");
    exit (0);
  }
  return (igual);
}



/*****************************************************************/

void Comprobar_Sindrome (sd, v, ts, llevamos)
MATRIZ *sd, v, ts;
unsigned int *llevamos;
{
  unsigned int j, encontrada;
  FILE *pf;

  Multiplicar_Matrices (v, Ht, sd);

  encontrada = 0;
  j = 1;
  while ((!encontrada) && (j <= (*llevamos)))
  {
    encontrada = (Es_Igual_Vector_a_Fila (*sd, ts, j));
    j++;
  }

  if (fichero)
  {
    pf = fichero;
  }
  else
  {
    pf = stdout;
  }

  if (!encontrada)
  {
    fprintf (pf, "    ");
    for (j = 1; j <= n; j++)
      fprintf (pf, "%d", Valor_en_Matriz (v, 1, j));
    fprintf (pf, " -> ");
    (*llevamos)++;
    for (j = 1; j <= n-k; j++)
    {
      if (Valor_en_Matriz (*sd, 1, j))
      {
        Poner_Valor_en_Matriz (ts, (*llevamos), j, 1);
        fprintf (pf, "1");
      }
      else
      {
        fprintf (pf, "0");
      }
    }

    fprintf (pf, "\n");
  }
  Destruir_Matriz (sd);
}





/************************************************************/


Tabla_de_Sindrome ()
{
  unsigned int i, j, l, terminado, unos, llevamos;
  MATRIZ ts, v, sd;
  FILE *pf;

  if (! Existe_Matriz (H))
  {
    printf ("> Error: No hay ningun codigo definido.\n");
  }
  else
  {
    if (fichero)
    {
      printf ("> Grabando resultados en el fichero de salida ...\n");
      pf = fichero;

      fprintf (pf, "- tabsin\n");
    }
    else
    {
      pf = stdout;
    }

    fprintf (pf, "> Tabla de sindrome:\n");

    Inicializar_Matriz (&ts);
    Crear_Matriz (&ts, 1<<(n-k), n-k);

    Inicializar_Matriz (&v);
    Crear_Matriz (&v, 1, n);

    Inicializar_Matriz (&sd);
    Crear_Matriz (&sd, 1, n-k);

    fprintf (pf, "    ");
    for (i = 1; i <= n; i++)
      fprintf (pf, "%d", Valor_en_Matriz (v, 1, i));
    fprintf (pf, " -> ");
    for (i = 1; i <= n-k; i++)
      fprintf (pf, "%d", Valor_en_Matriz (sd, 1, i));
    fprintf (pf, "\n");

    for (i = 1; i <= n; i++)
    {
      Poner_Valor_en_Matriz (v, 1, i, 1);

      fprintf (pf, "    ");
      for (j = 1; j <= n; j++)
        fprintf (pf, "%d", Valor_en_Matriz (v, 1, j));
      fprintf (pf, " -> ");
      for (j = 1; j <= n-k; j++)
      {
        if (Valor_en_Matriz (Ht, i, j))
        {
          Poner_Valor_en_Matriz (ts, i+1, j, 1);
          fprintf (pf, "1");
        }
        else
        {
          fprintf (pf, "0");
        }
      }

      fprintf (pf, "\n");
      Poner_Valor_en_Matriz (v, 1, i, 0);
    }

    llevamos = n+1;
    Destruir_Matriz (&sd);

    for (i = 2; ((i <= n-1) && (llevamos != 1<<(n-k))); i++)
    {
      for (j = 1; j <= i; j++) Poner_Valor_en_Matriz (v, 1, j, 1);
      Comprobar_Sindrome (&sd, v, ts, &llevamos);

      terminado = 0;
      l = i;

      while ((!terminado) && (llevamos != 1<<(n-k)))
      {
        for (j = l;  ((j <= n-1) && (llevamos != 1<<(n-k))); j++)
        {
          Poner_Valor_en_Matriz (v, 1, j, 0);
          Poner_Valor_en_Matriz (v, 1, j+1, 1);
          Comprobar_Sindrome (&sd, v, ts, &llevamos);
        }

        if (llevamos != 1<<(n-k))
        {
          unos = 0;
          j = n;

          while (Valor_en_Matriz (v, 1, j))
          {
            unos++;
            Poner_Valor_en_Matriz (v, 1, j, 0);
            j--;
          }

          if (unos != i)
          {
            while (!Valor_en_Matriz (v, 1, j)) j--;

            Poner_Valor_en_Matriz (v, 1, j, 0);
            j++;
            Poner_Valor_en_Matriz (v, 1, j, 1);
            j++;

            while (unos--)
            {
              Poner_Valor_en_Matriz (v, 1, j, 1);
              j++;
            }

            l = j - 1;
            Comprobar_Sindrome (&sd, v, ts, &llevamos);
          }
          else
          {
            terminado++;
          }
        }
      }
    }

    if (llevamos != 1<<(n-k))
    {
      for (i = 1; i <= n; i++)
        Poner_Valor_en_Matriz (v, 1, i, 1);
      Comprobar_Sindrome (&sd, v, ts, &llevamos);
    }
  }
}



/***************************************************************/
void Ayuda ()
{
  printf ("> Lista de comandos:\n");
  printf ("    defcod  : define un nuevo codigo de Hamming.\n");
  printf ("    verg    : muestra la matriz generadora del codigo.\n");
  printf ("    verh    : muestra la matriz control de paridad del codigo.\n");
  printf ("    codif   : codifica un vector mensaje dado.\n");
  printf ("    codtodo : genera todo el codigo.\n");
  printf ("    decod   : decodifica un vector dado.\n");
  printf ("    dectodo : decodifica todo el espacio vectorial.\n");
  printf ("    tabsin  : muestra la tabla de sindrome del codigo.\n");
  printf ("    fin     : finaliza la ejecucion del programa.\n");
  printf ("    ?       : muestra la lista de comandos.\n");
}


/***************************************************************/

void Control_Comandos ()
{
  char comando[256];
  char salir = 0;

  do
  {
    printf("- ");

    gets (comando);
    if (!strcmp (comando, "defcod"))
      Definir_Codigo ();
    else
      if (!strcmp (comando, "verg"))
        Ver_Matriz (&G);
      else
        if (!strcmp (comando, "verh"))
          Ver_Matriz (&H);
        else
          if (!strcmp (comando, "codif"))
            Codificar ();
          else
            if (!strcmp (comando, "codtodo"))
              Codificar_Todo ();
            else
              if (!strcmp (comando, "decod"))
                Decodificar ();
              else
                if (!strcmp (comando, "dectodo"))
                  Decodificar_Todo ();
                else
                  if (!strcmp (comando, "tabsin"))
                    Tabla_de_Sindrome ();
              /**** printf ("> %s\n", comando);******/
                  else
                    if (!strcmp (comando, "?"))
                      Ayuda ();
                    else
                      if (!strcmp (comando, "fin"))
                      {
                        salir++;
                      }
                      else
                        if (strcmp (comando, "\0"))
                          printf ("> Teclee un comando o '?' para ayuda.\n");
  }
  while (!salir);
}


/***************************************************************/



unsigned char Comprobar_Argumento (argc, argv)
int argc;
char *argv[];
{
  if (argc > 2)
  {
    printf ("Sintaxis: %s [nombre_de_fichero]\n", argv[0]);
    return (0);
  }
  else
  {
    if (argc == 2)
    {
      if ((fichero = fopen (argv[1], "w")) == NULL)
      {
        printf ("Error en la apertura del fichero.\n");
        return (0);
      }
    }
    else
    {
      fichero = NULL;
    }

    return (1);
  }
}


/***************************************************************/

void Cerrar_Fichero ()
{
  if (fichero)
  {
    if (fclose (fichero))
    {
      printf ( "Imposible cerrar el fichero.\n" );
    }
  }
}



/***************************************************************/




main (argc, argv)
int argc;
char *argv[];
{
  if (Comprobar_Argumento (argc , argv))
  {
    Inicializar_Matriz (&H);
    Inicializar_Matriz (&Ht);
    Inicializar_Matriz (&G);

    Control_Comandos ();
    Cerrar_Fichero ();
  }
}
