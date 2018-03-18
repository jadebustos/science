
/* MODULO DE TRATAMIENTO DE POLI_POLIS,
   POLINOMIOS CUYOS COEFICIENTES SON TAMBIEN POLINOMIOS */

/* Los coeficientes de un polipoli se recalculan modulo el primitivo,
   para poder realizar la conversion de un polipoli a un polinomio */
extern POLINOMIO primitivo;  


/* DEFINICION DE LA ESTRUCTURA */

/* Cada polipoli consta de un grado
   y un puntero a sus coeficientes, que son polinomios en Zp[x] */
struct EL_POLI_POLI {
  unsigned int grado;
  POLINOMIO *coeficientes;
};

/* Tipo de dato de los polipolis */
typedef struct EL_POLI_POLI POLI_POLI;



/* FUNCIONES DE TRATAMIENTO */

void Crear_Poli_Poli (P, grado)
POLI_POLI *P;
unsigned int grado;
{
  POLINOMIO *aux;

  if (grado >= 0)
  {
    /* Se reserva memoria para grado + 1 coeficientes de tipo polinomio */
    if (aux = (POLINOMIO *) calloc (grado + 1, sizeof (POLINOMIO)))
    {
      P->grado = grado;
      P->coeficientes = aux;
    }
    else
    {
      printf ("Error: no hay memoria disponible.");
      exit (0);
    }
  }
  else
  {
    printf ("Error: el grado no es correcto.");
    exit (0);
  }
}



unsigned int Grado_Poli_Poli (P)
POLI_POLI P;
{
  if (P.coeficientes != NULL)
  {
    return (P.grado);
  }
  else
  {
    printf ("Error: el polinomio no existe.");
    exit (0);
  }
}



/* PONER COMO COEFICIENTE DE UN GRADO DETERMINADO UN POLINOMIO DADO */

void Poner_Valor_Poli_Poli (P, grado, Q)
POLI_POLI P;
unsigned int grado;
POLINOMIO Q;
{
  POLINOMIO *aux;

  if ((grado >= 0) && (grado <= (P.grado)) && (P.coeficientes != NULL) &&
      (Q.coeficientes != NULL))  
  {
      aux = P.coeficientes;
      aux += grado;

      if ((aux->coeficientes) != NULL)     
      {
        free (aux->coeficientes);        
        aux->coeficientes = NULL;       
        aux->grado = 0;                 
      }

      Copiar_Polinomio (Q, aux);
  }
  else
  {
    printf ("Error: el grado no es correcto o el polinomio no existe.");
    exit (0);
  }
}



/* DEVOLVER EN UN POLINOMIO DADO EL COEFICIENTE DE UN GRADO DETERMINADO */

void Valor_Poli_Poli (P, grado, Q)
POLI_POLI P;
unsigned int grado;
POLINOMIO *Q;
{
  POLINOMIO *aux;

  if ((grado >= 0) && (grado <= (P.grado)) && (P.coeficientes != NULL))
  {
      aux = P.coeficientes;
      aux += grado;

      Copiar_Polinomio (*aux, Q);
  }
  else
  {
    printf ("Error:  el grado no es correcto o el polinomio no existe.");
    exit (0);
  }
}



/* COPIAR UN POLIPOLI EN OTRO: Q = P */

void Copiar_Poli_Poli (P, Q)
POLI_POLI P, *Q;
{
  POLINOMIO *auxP, *auxQ;
  int grado;

  if (P.coeficientes != NULL)
  {
    grado = P.grado;
    Crear_Poli_Poli (Q, grado);

    auxP = P.coeficientes;
    auxQ = Q->coeficientes;

    do
    {
      Copiar_Polinomio (*auxP, auxQ);
      auxQ++; auxP++;
    }
    while (grado--);
  }
  else
  {
    printf ("Error: el polinomio a copiar no existe.");
    exit (0);
  }
}


/* VISUALIZAR UN POLIPOLI */

void Ver_Poli_Poli (P, c1, c2)
POLI_POLI P;
/* c1 es la indeterminada del polipoli y c2 la de sus coeficientes */
unsigned char c1, c2;
{
  unsigned int i;
  POLINOMIO Q;

  if (P.coeficientes != NULL)
  {
    for (i = P.grado; i >= 2; i--)
    {
      printf("(");
      Valor_Poli_Poli (P, i, &Q);
      Ver_Polinomio (Q, c2);
      Destruir_Polinomio (&Q);
      printf(")%c^%d + ", c1, i);
    }

    if (P.grado >= 1)   
    {                  
      printf("(");
      Valor_Poli_Poli (P, 1, &Q);
      Ver_Polinomio (Q, c2);
      Destruir_Polinomio (&Q);
      printf(")%c + ", c1);
    }

    printf("(");
    Valor_Poli_Poli (P, 0, &Q);
    Ver_Polinomio (Q, c2);
    Destruir_Polinomio (&Q);
    printf(")\n");
  }
  else
  {
    printf ("Error: el polinomio no existe.");
    exit (0);
  }
}



/* LIBERAR LA MEMORIA RESERVADA PARA UN POLIPOLI Y SUS COEFICIENTES */

void Destruir_Poli_Poli (P)
POLI_POLI *P;
{
  POLINOMIO *aux;
  int i;

  if (P->coeficientes != NULL)
  {
    aux = P->coeficientes;
    i = P->grado;  
                       
    do
    {
      Destruir_Polinomio (aux);
      aux++;
    }
    while (i--);

    free (P->coeficientes);
    P->coeficientes = NULL;
    P->grado = 0;
  }
  else
  {
    printf ("Error: el polinomio no existe.");
    exit (0);
  }
}



/* SUMA DE POLIPOLIS: R = P + Q */

void Sumar_Poli_Poli (P, Q, R, p)
POLI_POLI P, Q, *R;
unsigned int p;
{
  unsigned int num_coef_P, num_coef_Q, num_coef_R;
  POLINOMIO *auxP, *auxQ, *auxR;

  if ((P.coeficientes != NULL) && (Q.coeficientes != NULL))
  {
    num_coef_P = P.grado + 1;
    num_coef_Q = Q.grado + 1;

    if (num_coef_P < num_coef_Q)
      num_coef_R = num_coef_Q;
    else
      num_coef_R = num_coef_P;

    Crear_Poli_Poli (R, num_coef_R - 1);

    auxP = P.coeficientes;                        
    auxQ = Q.coeficientes;                        
    auxR = R->coeficientes;                      

    /* Sumar los coeficientes del mismo grado hasta el grado menor */

    do
    {
      Sumar_Polinomios (*auxP, *auxQ, auxR, p);
      auxR++; auxP++; auxQ++;
      num_coef_P--;
      num_coef_Q--;
    }
    while (num_coef_P && num_coef_Q);

    /* Completar con los coeficientes restantes del polinomio mayor */

    if (num_coef_P)
    {
      while (num_coef_P)
      {
        Copiar_Polinomio (*auxP, auxR);
        auxR++; auxP++;
        num_coef_P--;
      }
    }
    else
    {
      if (num_coef_Q)
      {
        while (num_coef_Q)
        {
          Copiar_Polinomio (*auxQ, auxR);
          auxR++; auxQ++;
          num_coef_Q--;
        }
      }
    }

    /* Reajustar el grado y eliminar ceros como coeficientes principales */

    auxR--;

    while ((R->grado) && ((auxR->grado) == 0) &&     
           ((*(auxR->coeficientes)) == 0))
    {
      Destruir_Polinomio (auxR);
      auxR--;
      (R->grado)--;
    }

    R->coeficientes = (POLINOMIO *) realloc ((char *) R->coeficientes, (R->grado + 1) * sizeof (POLINOMIO));
  }
  else
  {
    printf ("Error: imposible sumar los polinomios.");
    exit (0);
  }
}



/* RESTA DE POLIPOLIS: R = P - Q */

void Restar_Poli_Poli (P, Q, R, p)
POLI_POLI P, Q, *R;
unsigned int p;
{
  unsigned int num_coef_P, num_coef_Q, num_coef_R;
  POLINOMIO *auxP, *auxQ, *auxR, cero;

  if ((P.coeficientes != NULL) && (Q.coeficientes != NULL))
  {
    num_coef_P = P.grado + 1;
    num_coef_Q = Q.grado + 1;

    if (num_coef_P < num_coef_Q)
      num_coef_R = num_coef_Q;
    else
      num_coef_R = num_coef_P;

    Crear_Poli_Poli (R, num_coef_R - 1);

    auxP = P.coeficientes;     
    auxQ = Q.coeficientes;     
    auxR = R->coeficientes;     

    /* Restar los coeficientes del mismo grado hasta el grado menor */

    do
    {
      Restar_Polinomios (*auxP, *auxQ, auxR, p);
      auxR++; auxP++; auxQ++;
      num_coef_P--;
      num_coef_Q--;
    }
    while (num_coef_P && num_coef_Q);

    /* Completar con los coeficientes restantes del polinomio mayor */

    if (num_coef_P)
    {
      while (num_coef_P)
      {
        Copiar_Polinomio (*auxP, auxR);
        auxR++; auxP++;
        num_coef_P--;
      }
    }
    else
    {
      if (num_coef_Q)
      {
        Crear_Polinomio (&cero, 0);

        while (num_coef_Q)
        {
          Restar_Polinomios (cero, *auxQ, auxR, p);
          auxR++; auxQ++;
          num_coef_Q--;
        }

        Destruir_Polinomio (&cero);
      }
    }

    /* Reajustar el grado y eliminar ceros como coeficientes principales */

    auxR--;

    while ((R->grado) && (auxR->grado == 0) &&
           ((*(auxR->coeficientes)) == 0))
    {
      Destruir_Polinomio (auxR);
      auxR--;
      (R->grado)--;
    }

    R->coeficientes = (POLINOMIO *) realloc ((char *) R->coeficientes, (R->grado + 1) * sizeof (POLINOMIO));
  }
  else
  {
    printf ("Error: imposible restar los polinomios.");
    exit (0);
  }
}



/* PRODUCTO DE POLIPOLIS: R = P * Q */

void Multiplicar_Poli_Poli (P, Q, R, p)
POLI_POLI P, Q, *R;
unsigned int p;
{
  POLINOMIO *auxP, *auxQ, *auxR, temp1, temp2;
  unsigned int i = 0, j = 0;

  if ((P.coeficientes != NULL) && (Q.coeficientes != NULL))
  {
    Crear_Poli_Poli (R, P.grado + Q.grado);

    auxQ = Q.coeficientes;

    while (i <= Q.grado)
    {
      auxP = P.coeficientes;
      auxR = (R->coeficientes + i);
      j = 0;

      while (j <= P.grado)
      {
        Multiplicar_Polinomios (*auxP, *auxQ, &temp1, p);
       
        if (auxR->coeficientes)
        {
          Sumar_Polinomios (*auxR, temp1, &temp2, p);
          Destruir_Polinomio (auxR);
          Copiar_Polinomio (temp2, auxR); 
          Destruir_Polinomio (&temp2);
 
        }
        else
          Copiar_Polinomio (temp1, auxR);

  
        Destruir_Polinomio (&temp1);
        
        j++;
        auxP++;
        auxR++;
      }

      i++;
      auxQ++;
    }
  }
  else
  {
    printf ("Error: imposible multiplicar los polinomios.");
    exit (0);
  }
}


/* CONVERSION DE UN POLIPOLI EN UN POLINOMIO,
   SI SUS COEFICIENTES SON POLINOMIOS DE GRADO CERO */

void PoliPoli_a_Polinomio (P, Q, p)
POLI_POLI P;
POLINOMIO *Q;
unsigned int p;
{
  POLINOMIO *aux, cociente, resto;
  int grado;

  if (P.coeficientes != NULL)
  {
    grado = P.grado;
    aux = P.coeficientes + grado;
    Crear_Polinomio (Q, grado);   

    do
    {
      if (aux->grado != 0)
      {
        /* El polipoli debe estar en (Zp[x]/<p(x)>)[y],
           por tanto se divide cada uno de sus coeficientes entre p(x)
           y se toma el resto */
        Dividir_Polinomios (*aux, primitivo, &cociente, &resto, p);

        if (resto.grado == 0)
        {
          Poner_Valor_Polinomio (*Q, grado, *(resto.coeficientes));
        }
        else
        {
          printf ("Error: el coeficiente del polinomio no tiene grado cero.");
          exit (0);
        }

        Destruir_Polinomio (&cociente);
        Destruir_Polinomio (&resto);
      }
      else
      {
        Poner_Valor_Polinomio (*Q, grado, *(aux->coeficientes));
      }
      aux--;
    }
    while (grado--);
  }
  else
  {
    printf ("Error: el polinomio no existe.");
    exit (0);
  }
}
