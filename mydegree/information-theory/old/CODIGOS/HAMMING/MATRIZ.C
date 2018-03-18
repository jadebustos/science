
/* matriz.c */
/* manejo de matrices y vectores de ceros y unos */

struct COMP_MATRIZ {
  unsigned int filas;
  unsigned int columnas;
  char *p_elems;
};

typedef struct COMP_MATRIZ MATRIZ;



void Inicializar_Matriz (m)
MATRIZ *m;
{
  m->filas = 0;
  m->columnas = 0;
  m->p_elems = NULL;
}


unsigned char Existe_Matriz (m)
MATRIZ m;
{
  return (m.p_elems != NULL);
}


void Crear_Matriz (m, filas, columnas)
MATRIZ *m;
unsigned int filas, columnas;
{
  char *aux;
  unsigned int num_elems;

  if ((filas > 0) && (columnas > 0))
  {
    m->filas = filas;
    m->columnas = columnas;
    num_elems = ((--columnas / 8) + 1) * filas;

    if (aux = (char *) malloc (num_elems))
    {
      m->p_elems = aux;

      while (num_elems--)
      {
        (*aux) = 0;
        aux++;
      }
    }
    else
    {
        printf ("Crear.Error: no hay memoria disponible.");
        exit (0);
    }
  }
  else
  {
    printf ("Crear_Matriz: Error de direccionamiento de la matriz.");
    exit (0);
  }
}


void Poner_Valor_en_Matriz (m, fila, columna, valor)
MATRIZ m;
unsigned int fila, columna;
unsigned char valor;
{
  char *aux;
  unsigned int num_elems;

  if ((fila > 0) && (fila <= m.filas) && (columna > 0) &&
      (columna <= m.columnas) && (Existe_Matriz (m)))
  {
    aux = m.p_elems;
    num_elems = (fila - 1) * (((m.columnas - 1) / 8) + 1) +
                 ((columna - 1) / 8);
    if (!valor)
    {
      *(aux + num_elems) &= ~(1 << (7 - (--columna % 8)));
    }
    else
    {
      *(aux + num_elems) |= (1 << (7 - (--columna % 8)));
    }
  }
  else
  {
    printf ("Poner.Error de direccionamiento de la matriz.");
    exit (0);
  }
}


unsigned char Valor_en_Matriz (m, fila, columna)
MATRIZ m;
unsigned int fila, columna;
{
  char *aux;
  unsigned int num_elems;

  if ((fila > 0) && (fila <= m.filas) && (columna > 0) &&
      (columna <= m.columnas) && (Existe_Matriz (m)))
  {
    aux = m.p_elems;
    num_elems = (fila - 1) * (((m.columnas - 1) / 8) + 1) +
                 ((columna - 1) / 8);
    if (*(aux + num_elems) & (1 << (7 - (--columna % 8))))
    {
      return (1);
    }
    else
    {
      return (0);
    }
  }
  else
  {
    printf ("Valor.Error de direccionamiento de la matriz.");
    exit (0);
  }
}


void Dimensiones_Matriz (m, filas, columnas)
MATRIZ m;
unsigned int *filas, *columnas;
{
  if (Existe_Matriz (m))
  {
    *filas = m.filas;
    *columnas = m.columnas;
  }
  else
  {
    printf ("Dim.Error: no existe la matriz.");
    exit (0);
  }
}

/*****************SACAR DEL MODULO*******************/
void Multiplicar_Matrices (m1, m2, m3)
MATRIZ m1, m2, *m3;
{
  unsigned int f1, c1, f2, c2, i, j, k;
  unsigned char s;

  Dimensiones_Matriz (m1, &f1, &c1);
  Dimensiones_Matriz (m2, &f2, &c2);

  if (c1 == f2)
  {
    Crear_Matriz (m3, f1, c2);

    for (i = 1; i <= f1; i++)
    {
      for (j = 1; j <= c2; j++)
      {
        s = 0;

        for (k = 1; k <= f2; k++)
        {
          if ((Valor_en_Matriz (m1, i, k)) * (Valor_en_Matriz (m2, k, j)))
            if (s)
              s--;
            else
              s++;
        }

        if (s)
          Poner_Valor_en_Matriz (*m3, i, j, 1);
      }
    }
  }
  else
  {
    printf ("Error: no se pueden multiplicar las matrices.");
    exit (0);
  }
}


/*****************SACAR DEL MODULO*******************/
void Matriz_Traspuesta (m, mt)
MATRIZ m, *mt;
{
  unsigned int f, c, i, j;

  Dimensiones_Matriz (m, &f, &c);

  Inicializar_Matriz (mt);
  Crear_Matriz (mt, c, f);

  for (i = 1; i <= f; i++)
  {
    for (j = 1; j <= c; j++)
    {
        if (Valor_en_Matriz (m, i, j))
          Poner_Valor_en_Matriz (*mt, j, i, 1);
    }
  }
}


void Poner_Fila_a_Cero (m, fila)
MATRIZ m;
unsigned int fila;
{
  char *aux;
  unsigned int num_elems;

  if ((fila > 0) && (fila <= m.filas) && (Existe_Matriz (m)))
  {
    aux = m.p_elems;
    num_elems = (((m.columnas - 1) / 8) + 1);
    aux += (fila - 1) * num_elems;

    while (num_elems--)
    {
      (*aux) = 0;
      aux++;
    }
  }
  else
  {
    printf ("Poner_a_cero.Error de direccionamiento de la matriz.");
    exit (0);
  }
}



unsigned int Peso_Fila (m, fila)
MATRIZ m;
unsigned int fila;
{
  char *aux;
  unsigned int num_elems, i, unos;

  if ((fila > 0) && (fila <= m.filas) && (Existe_Matriz (m)))
  {
    aux = m.p_elems;
    num_elems = (((m.columnas - 1) / 8) + 1);
    aux += (fila - 1) * num_elems;
    unos = 0;

    while (num_elems--)
    {
      for (i = 0; i <= 7; i++)
      {
        if ((1 << i) & (*aux)) unos++;
      }

      aux++;
    }

    return (unos);
  }
  else
  {
    printf ("Peso.Error de direccionamiento de la matriz.");
    exit (0);
  }
}



void Destruir_Matriz (m)
MATRIZ *m;
{
  char *aux;
  unsigned int num_elems;

  num_elems = ((--(m->columnas) / 8) + 1) * (m->filas);
  m->filas = 0;
  m->columnas = 0;
  aux = m->p_elems;
  m->p_elems = NULL;

  while (num_elems--)
  {
    free (aux);
    aux++;
  }
}

