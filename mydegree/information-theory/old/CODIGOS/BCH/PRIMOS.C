

/* MODULO DE TRATAMIENTO DE LA LISTA DE NUMEROS PRIMOS */


/* DEFINICION DE LA ESTRUCTURA */

/* Tipo de dato que apunta a un elemento de la lista */
typedef struct ELEMENTO *ELEM_LISTA;

/* Cada elemento de la lista consta de un numero primo, su potencia 
   (para indicar cuantas veces aparece al descomponer en factores primos
   un numero dado) y un puntero al siguiente elemento */
struct ELEMENTO {
  unsigned int primo;
  unsigned int potencia;
  ELEM_LISTA siguiente;
};

/* Tipo de dato de la lista */
typedef struct COMP_LISTA LISTA;

/* La lista tiene principio y final */
struct COMP_LISTA
{
  ELEM_LISTA Principio;
  ELEM_LISTA Fin;
};


/* FUNCIONES DE TRATAMIENTO */

void Crear_Lista (L)
LISTA *L;
{
  L->Principio = NULL;
  L->Fin = NULL;
}



unsigned int Es_Vacia (L)
LISTA L;
{
  return (L.Principio == NULL);
}



/* INSERCION DE UN ELEMENTO POR EL FINAL DE LA LISTA */

void Insertar_Elemento (L, i)
LISTA *L;
unsigned int i;
{
  ELEM_LISTA aux;

  if (aux = (ELEM_LISTA) malloc (sizeof(struct ELEMENTO)))
  {
    aux->primo = i;
    aux->potencia = 0;
    aux->siguiente = NULL;

    if (Es_Vacia (*L))
      L->Principio = aux;
    else
      (L->Fin)->siguiente = aux;
    
    L->Fin = aux;
  }
  else
  {
    printf ("Error: no hay memoria disponible.");
    exit (0);
  }
}


/* EXTRACCION DE UN ELEMENTO POR EL PRINCIPIO DE LA LISTA */

void Extraer_Elemento (L, f, p)
LISTA *L;
unsigned int *f;
unsigned int *p;
{
  ELEM_LISTA aux;

  if (!Es_Vacia (*L))
  {
    aux = L->Principio;
    *f = aux->primo;
    *p = aux->potencia;

    L->Principio = (L->Principio)->siguiente;
    free (aux);
  }
  else
  {
    printf ("Error: la lista es vacia.");
    exit (0);
  }
}



/* CRIBA DE ERATOSTENES: UN NUMERO i ES PRIMO SI NO ES DIVISIBLE POR
   NINGUNO DE LOS PRIMOS ANTERIORES A EL DESDE 2 HASTA RAIZ CUADRADA DE i */

unsigned int Es_Primo (L, i)
LISTA L;
unsigned int i;
{
  ELEM_LISTA aux;
  unsigned int raiz_i;

  if (!Es_Vacia (L))
  {
    raiz_i = (unsigned int) ceil (sqrt ((double) i));
    aux = L.Principio;

    while ((aux) && ((aux->primo) <= raiz_i))
    {
      if (i % (aux->primo))
        aux = aux->siguiente;
      else
         return (0);
    }
   
    return (1);
  }
  else
  {
    printf ("Error: la lista es vacia.");
    exit (0);
  }
}



/* BUSQUEDA Y ALMACENAMIENTO DE FACTORES PRIMOS Y SUS POTENCIAS */

unsigned int Buscar_Factor (L, i)
LISTA L;
unsigned int i;
{
  ELEM_LISTA aux;
  unsigned int raiz_i;

  if (!Es_Vacia (L))
  {
    raiz_i = (unsigned int) ceil (sqrt ((double) i));
    aux = L.Principio;

    /* Buscar el primer factor primo que divide a i */
    while ((aux) && ((aux->primo) <= raiz_i))
    {
      if (i % (aux->primo))
        aux = aux->siguiente;
      else
      {
        (aux->potencia)++;

        /* Se devuelve el cociente, para seguir descomponiendo recursivamente */
        return (i / (aux->primo));
      }
    }

    /* El numero recibido i es primo; lo buscamos en la lista */
    while ((aux) && ((aux->primo) != i))
    {
       aux = aux->siguiente;
    }

    /* Si existe, se incrementa su potencia.
       Si no existe, se inserta con potencia 1 */
    if (aux)
      (aux->potencia)++;
    else
    {
      Insertar_Elemento (&L, i);
      (L.Fin)->potencia = 1;
    }

    /* Condicion de parada de la recursividad */
    return (1);    
  }
  else
  {
    printf ("Error: la lista es vacia.");
    exit (0);
  }
}
