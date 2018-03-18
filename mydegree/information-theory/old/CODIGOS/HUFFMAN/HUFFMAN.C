
extern unsigned long frecs[257];


typedef struct PAR PAREJA;

typedef struct {
  PAREJA *FP;
  unsigned char etiqueta;
  unsigned int contador_actualizacion;
} SIMBOLO;

SIMBOLO tabla_simbolos[NUMERO_SIMBOLOS];


struct PAR {
  PAREJA *FP;

  unsigned char etiqueta;

  struct {
    unsigned char es_simbolo;
    union {
      SIMBOLO *PS;
      PAREJA *PP;
    } PT;
  } BP0;

  unsigned long acum0;

  struct {
    unsigned char es_simbolo;
    union {
      SIMBOLO *PS;
      PAREJA *PP;
    } PT;
  } BP1;

  unsigned long acum1;

  PAREJA *sig_pareja;
};


typedef struct COMP_FREC ELEM_FREC;

struct COMP_FREC {
  struct {
    unsigned char es_simbolo;
    union {
      unsigned int valor_ascii;
      PAREJA *PP;
    } sub_elem;
  } sub_elem_frec;

  unsigned long valor_frec;

  ELEM_FREC *sig_elem_frec;
};

ELEM_FREC *lista_frecs;

PAREJA *arbol;


void Colocar_primero_lista_frecs ()
{
  ELEM_FREC *aux, *temp;

  if ((lista_frecs->sig_elem_frec) &&
      ((lista_frecs->sig_elem_frec)->valor_frec <= (lista_frecs->valor_frec)))
  {
    aux = lista_frecs->sig_elem_frec;

    while ((aux->sig_elem_frec) &&
           ((aux->sig_elem_frec)->valor_frec <= (lista_frecs->valor_frec)))
      aux = aux->sig_elem_frec;

    temp = aux->sig_elem_frec;
    aux->sig_elem_frec = lista_frecs;
    lista_frecs = lista_frecs->sig_elem_frec;
    (aux->sig_elem_frec)->sig_elem_frec = temp;
  }
}


void Inicializar_lista_frecs ()
{
  ELEM_FREC *aux;
  unsigned int i;

  lista_frecs = NULL;

  for (i = 0; i <= (NUMERO_SIMBOLOS - 1); i++)
  {
    if (aux = (ELEM_FREC *) malloc (sizeof (ELEM_FREC)))
    {
      (aux->sub_elem_frec).es_simbolo = 1;
      (aux->sub_elem_frec).sub_elem.valor_ascii = i;
      aux->valor_frec = frecs[i];

      aux->sig_elem_frec = lista_frecs;
      lista_frecs = aux;
      Colocar_primero_lista_frecs ();
    }
    else
    {
      printf ("Error: no hay memoria disponible.");
      exit (0);
    }
  }
}


void Inicializar_tabla_simbolos ()
{
  unsigned int i;

  for (i=0; i <= (NUMERO_SIMBOLOS - 1); i++)
  {
    tabla_simbolos[i].FP = NULL;
    tabla_simbolos[i].etiqueta = 2;
    tabla_simbolos[i].contador_actualizacion = 0;
  }
}


void Inicializar_arbol ()
{
  PAREJA *auxp, *auxpant;
  ELEM_FREC *aux;
  unsigned long acum;

  auxpant = NULL;

  while (lista_frecs->sig_elem_frec)
  {
    if (auxp = (PAREJA *) malloc (sizeof (PAREJA)))
    {
      auxp->sig_pareja = NULL;
      if (auxpant) auxpant->sig_pareja = auxp;

      auxp->FP = NULL;

      auxp->etiqueta = 2;

      auxp->acum1 = lista_frecs->valor_frec;
      if ((lista_frecs->sub_elem_frec).es_simbolo)
      {
        (auxp->BP1).es_simbolo = 1;
        (auxp->BP1).PT.PS =
          &(tabla_simbolos[(lista_frecs->sub_elem_frec).sub_elem.valor_ascii]);

         tabla_simbolos[(lista_frecs->sub_elem_frec).sub_elem.valor_ascii].etiqueta = 1;
         tabla_simbolos[(lista_frecs->sub_elem_frec).sub_elem.valor_ascii].FP = auxp;
      }
      else
      {
        (auxp->BP1).es_simbolo = 0;
        (auxp->BP1).PT.PP = (lista_frecs->sub_elem_frec).sub_elem.PP;
        ((auxp->BP1).PT.PP)->FP = auxp;
        ((auxp->BP1).PT.PP)->etiqueta = 1;
      }

      acum = lista_frecs->valor_frec;
      aux = lista_frecs;
      lista_frecs = aux->sig_elem_frec;
      free (aux);

      auxp->acum0 = lista_frecs->valor_frec;
      if ((lista_frecs->sub_elem_frec).es_simbolo)
      {
        (auxp->BP0).es_simbolo = 1;
        (auxp->BP0).PT.PS =
          &(tabla_simbolos[(lista_frecs->sub_elem_frec).sub_elem.valor_ascii]);

         tabla_simbolos[(lista_frecs->sub_elem_frec).sub_elem.valor_ascii].etiqueta = 0;
         tabla_simbolos[(lista_frecs->sub_elem_frec).sub_elem.valor_ascii].FP = auxp;
      }
      else
      {
        (auxp->BP0).es_simbolo = 0;
        (auxp->BP0).PT.PP = (lista_frecs->sub_elem_frec).sub_elem.PP;
        ((auxp->BP0).PT.PP)->FP = auxp;
        ((auxp->BP0).PT.PP)->etiqueta = 0;
      }

      (lista_frecs->valor_frec) += acum;
      (lista_frecs->sub_elem_frec).es_simbolo = 0;
      (lista_frecs->sub_elem_frec).sub_elem.PP = auxp;

      Colocar_primero_lista_frecs ();

      auxpant = auxp;
    }
    else
    {
      printf ("Error: no hay memoria disponible.");
      exit (0);
    }
  }

  arbol = auxp;
  free (lista_frecs);
}


