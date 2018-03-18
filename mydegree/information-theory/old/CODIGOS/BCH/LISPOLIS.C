
/* MODULO DE TRATAMIENTO DE LA LISTA DE POLINOMIOS */


/* DEFINICION DE LA ESTRUCTURA */

/* Tipo de dato que apunta a un elemento de la lista */
typedef struct ELEM *EL_LIS_P;

/* Cada elemento de la lista consta de un polinomio
   y un puntero al siguiente elemento */
struct ELEM {
  POLINOMIO polinom;
  EL_LIS_P siguiente;
};

/* Tipo de dato de la lista */
typedef struct LISTA_P POLINOMIOS;

/* La lista tiene principio y final */
struct LISTA_P
{
  EL_LIS_P Principio;
  EL_LIS_P Fin;
};


/* FUNCIONES DE TRATAMIENTO */

void Crear_Lista_P (P)
POLINOMIOS *P;
{
  P->Principio = NULL;
  P->Fin = NULL;
}



unsigned int Es_Vacia_Lista_P (P)
POLINOMIOS P;
{
  return (P.Principio == NULL);
}



/* INSERCION DE UN ELEMENTO POR EL FINAL DE LA LISTA */

void Insertar_Polinomio_Lista_P (P, p)
POLINOMIOS *P;
POLINOMIO p;
{
  EL_LIS_P aux;

  if (aux = (EL_LIS_P) malloc (sizeof(struct ELEM)))
  {
    Copiar_Polinomio (p, &(aux->polinom));

    aux->siguiente = NULL;

    if (Es_Vacia_Lista_P (*P))
      P->Principio = aux;
    else
      (P->Fin)->siguiente = aux;

    P->Fin = aux;
  }
  else
  {
    printf ("Error: no hay memoria disponible.");
    exit (0);
  }
}



/* EXTRACCION DE UN ELEMENTO POR EL PRINCIPIO DE LA LISTA */

void Extraer_Polinomio_Lista_P (P, p)
POLINOMIOS *P;
POLINOMIO *p;
{
  EL_LIS_P aux;

  if (!Es_Vacia_Lista_P (*P))
  {
    aux = P->Principio;
    Copiar_Polinomio (aux->polinom, p);
    Destruir_Polinomio (&(aux->polinom));
    P->Principio = (P->Principio)->siguiente;
    free (aux);
  }
  else
  {
    printf ("Error: la lista de polinomios esta vacia.");
    exit (0);
  }
}


/* COMPROBAR SI EL POLINOMIO YA EXISTE EN LA LISTA */

unsigned char Existe_Polinomio_Lista_P (P, p)
POLINOMIOS P;
POLINOMIO p;
{
  EL_LIS_P aux;

  if (!Es_Vacia_Lista_P (P))
  {
    aux = P.Principio;

    while (aux)
    {
      if (Son_Iguales_Polinomios (p, aux->polinom))
        return (1);
      aux = aux->siguiente;
    }
    
    return (0);
  }
  else
  {
    return (0);
  }
}
