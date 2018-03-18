
/* MODULO DE TRATAMIENTO DE POLINOMIOS */


/* DEFINICION DE LA ESTRUCTURA */

/* Cada polinomio consta de un grado
   y un puntero a sus coeficientes, que son elementos de Zp */
struct ELEM_POLI {
  unsigned int grado;
  char *coeficientes;
};

/* Tipo de dato de los polinomios */
typedef struct ELEM_POLI POLINOMIO;



/* FUNCIONES DE TRATAMIENTO */

void Crear_Polinomio (P, grado)
POLINOMIO *P;
unsigned int grado;
{
  char *aux;

  if (grado >= 0)
  {
    /* Se reserva memoria para grado + 1 coeficientes */
    if (aux = (char *) calloc (grado + 1, 1))
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



unsigned int Grado_Polinomio (P)
POLINOMIO P;
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



/* PONER COMO COEFICIENTE DE UN GRADO DETERMINADO UN VALOR DADO */

void Poner_Valor_Polinomio (P, grado, valor)
POLINOMIO P;
unsigned int grado;
unsigned int valor;
{
  char *aux;

  if ((grado >= 0) && (grado <= (P.grado)) && (P.coeficientes != NULL))
  {
      aux = P.coeficientes;
      aux += grado;
      (*aux) = valor;
  }
  else
  {
    printf ("Error: el grado no es correcto o el polinomio no existe.");
    exit (0);
  }
}



/* DEVOLVER EN UN VALOR DADO EL COEFICIENTE DE UN GRADO DETERMINADO */

unsigned int Valor_Polinomio (P, grado)
POLINOMIO P;
unsigned int grado;
{
  char *aux;

  if ((grado >= 0) && (grado <= (P.grado)) && (P.coeficientes != NULL))
  {
      aux = P.coeficientes;
      aux += grado;
      return (*aux);
  }
  else
  {
    printf ("Error: el grado no es correcto o el polinomio no existe.");
    exit (0);
  }
}



/* COPIAR UN POLINOMIO EN OTRO: Q = P */

void Copiar_Polinomio (P, Q)
POLINOMIO P, *Q;
{
  char *auxP, *auxQ;
  int grado;

  if (P.coeficientes != NULL)
  {
    grado = P.grado;
    Crear_Polinomio (Q, grado);

    auxP = P.coeficientes;
    auxQ = Q->coeficientes;

    do
    {
      (*auxQ) = (*auxP);
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



/* VISUALIZAR UN POLINOMIO */

void Ver_Polinomio (P, c)
POLINOMIO P;
/* c es la indeterminada del polinomio */
char c;
{
  unsigned int i;

  if (P.coeficientes != NULL)
  {
    for (i = P.grado; i >= 2; i--)
      printf("%u%c^%d + ", Valor_Polinomio (P, i), c, i);

    if (P.grado >= 1)
      printf("%u%c + ", Valor_Polinomio (P, 1), c);

    printf("%u", Valor_Polinomio (P, 0));
  }
  else
  {
    printf ("Error: el polinomio no existe.");
    exit (0);
  }
}



/* COMPROBAR SI DOS POLINOMIOS SON IGUALES: A == B */

unsigned int Son_Iguales_Polinomios (A, B)
POLINOMIO A, B;
{
  char *auxA, *auxB;
  unsigned int igual;
  int grado;

  if ((A.coeficientes != NULL) && (B.coeficientes != NULL))
  {
    /* Dos polinomios son iguales si tienen el mismo grado ... */
    if (A.grado == B.grado)
    {
      grado = A.grado;
      auxA = A.coeficientes;
      auxB = B.coeficientes;

      /* ... y los mismos coeficientes */
      do
      {
        igual = ((*auxA) == (*auxB));
        auxA++; auxB++;
      }
      while ((grado--) && (igual));

      return (igual);
    }
    else
    {
      return (0);
    }
  }
  else
  {
    printf ("Error: los polinomios no existen.");
    exit (0);
  }
}



/* LIBERAR LA MEMORIA RESERVADA PARA UN POLINOMIO */

void Destruir_Polinomio (P)
POLINOMIO *P;
{
  if (P->coeficientes != NULL)
  {
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



/* SUMA DE POLINOMIOS: R = P + Q (LOS COEFICIENTES SE OPERAN MODULO p) */

void Sumar_Polinomios (P, Q, R, p)
POLINOMIO P, Q, *R;
unsigned int p;
{
  unsigned int num_coef_P, num_coef_Q, num_coef_R;
  char *auxP, *auxQ, *auxR;

  if ((P.coeficientes != NULL) && (Q.coeficientes != NULL))
  {
    num_coef_P = P.grado + 1;
    num_coef_Q = Q.grado + 1;

    if (num_coef_P < num_coef_Q)
      num_coef_R = num_coef_Q;
    else
      num_coef_R = num_coef_P;

    Crear_Polinomio (R, num_coef_R - 1);

    auxP = P.coeficientes;
    auxQ = Q.coeficientes;
    auxR = R->coeficientes;

    /* Sumar los coeficientes del mismo grado hasta el grado menor */

    do
    {
      (*auxR) = ((*auxP) + (*auxQ)) % p;
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
        (*auxR) = (*auxP);
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
          (*auxR) = (*auxQ);
          auxR++; auxQ++;
          num_coef_Q--;
        }
      }
    }

    /* Reajustar el grado y eliminar ceros como coeficientes principales */

    auxR--;

    while ((R->grado) && ((*auxR) == 0))
    {
      auxR--;
      (R->grado)--;
    }
    R->coeficientes = realloc (R->coeficientes, R->grado + 1);
  }
  else
  {
    printf ("Error: imposible sumar los polinomios.");
    exit (0);
  }
}



/* RESTA DE POLINOMIOS: R = P - Q (LOS COEFICIENTES SE OPERAN MODULO p) */

void Restar_Polinomios (P, Q, R, p)
POLINOMIO P, Q, *R;
unsigned int p;
{
  unsigned int num_coef_P, num_coef_Q, num_coef_R;
  char *auxP, *auxQ, *auxR;
  int r;

  if ((P.coeficientes != NULL) && (Q.coeficientes != NULL))
  {
    num_coef_P = P.grado + 1;
    num_coef_Q = Q.grado + 1;

    if (num_coef_P < num_coef_Q)
      num_coef_R = num_coef_Q;
    else
      num_coef_R = num_coef_P;

    Crear_Polinomio (R, num_coef_R - 1);

    auxP = P.coeficientes;
    auxQ = Q.coeficientes;
    auxR = R->coeficientes;

    /* Restar los coeficientes del mismo grado hasta el grado menor */

    do
    {
      if ((r = (*auxP) - (*auxQ)) < 0) r += p;
      (*auxR) = r;
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
        (*auxR) = (*auxP);
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
          (*auxR) = (p - (*auxQ)) % p;
          auxR++; auxQ++;
          num_coef_Q--;
        }
      }
    }

    /* Reajustar el grado y eliminar ceros como coeficientes principales */

    auxR--;

    while ((R->grado) && ((*auxR) == 0))
    {
      auxR--;
      (R->grado)--;
    }
    R->coeficientes = realloc (R->coeficientes, R->grado + 1);
  }
  else
  {
    printf ("Error: imposible restar los polinomios.");
    exit (0);
  }
}



/* PRODUCTO DE POLINOMIOS: R = P * Q (LOS COEFICIENTES SE OPERAN MODULO p) */

void Multiplicar_Polinomios (P, Q, R, p)
POLINOMIO P, Q, *R;
unsigned int p;
{
  char *auxP, *auxQ, *auxR;
  unsigned int i = 0, j = 0;

  if ((P.coeficientes != NULL) && (Q.coeficientes != NULL))
  {
    Crear_Polinomio (R, P.grado + Q.grado);

    auxQ = Q.coeficientes;

    while (i <= Q.grado)
    {
      auxP = P.coeficientes;
      auxR = (R->coeficientes + i);
      j = 0;

      while (j <= P.grado)
      {
        (*auxR) = ((*auxR) + ((*auxP) * (*auxQ))) % p;
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



/* DIVISION DE POLINOMIOS: A = B*C + R (LOS COEFICIENTES SE OPERAN MODULO p) */

void Dividir_Polinomios (A, B, C, R, p)
POLINOMIO A, B, *C, *R;
unsigned int p;
{
  /* A es el dividendo, B el divisor, C el cociente y R el resto */
  /* A(x) = B(x)*C(x) + R(x) */

  POLINOMIO m, r;
  char *auxA, *auxR, *auxm, *auxB;
  unsigned int a, b;
  int i, j;

  if ((A.coeficientes != NULL) && (B.coeficientes != NULL))
  {
    if ((B.grado == 0) && (*(B.coeficientes) == 0))  /* El divisor es cero */
    {
      printf ("Error: imposible dividir por cero.");
      exit (0);
    }
    else
    {
      if (A.grado < B.grado)
      {
        /* Caso 1: grado A(x) < grado B(x) */
        /* C(x) = 0, R(x) = A(x) */

        Crear_Polinomio (C, 0);

        Copiar_Polinomio (A, R);
      }
      else
      {
        /* Caso 2: grado A(x) >= grado B(x) */

        /* R(x) = A(x) */

        Copiar_Polinomio (A, R);

        Crear_Polinomio (C, A.grado - B.grado);

        while (R->grado >= B.grado)
        {
           /* Codigo que sustituye a: a = Valor_Polinomio (*R, R->grado); */
           a = *(R->coeficientes + R->grado);


           /* Codigo que sustituye a: b = Valor_Polinomio (B, B.grado); */
           b = *(B.coeficientes + B.grado);


           i = 1;

           while (((i * b) % p) != a)
             i++;

           /* Codigo que sustituye a: Poner_Valor_Polinomio (*C,  R->grado - B.grado, i); */
           *(C->coeficientes + R->grado - B.grado) = i;


           /* Codigo que sustituye a: Multiplicar_Polinomios(q, B, &m, p); */
           Crear_Polinomio (&m, R->grado);
           auxm = m.coeficientes + m.grado;
           auxB = B.coeficientes + B.grado;
           j = B.grado;

           do
           {
             (*auxm) = ((*auxB) * i) % p;
             auxm--;
             auxB--;
           }
           while (j--);


           Restar_Polinomios (*R, m, &r, p);

           /* Codigo que sustituye a: Destruir_Polinomio (&m); */
           free (m.coeficientes);
           m.coeficientes = NULL;


           /* Codigo que sustituye a: Destruir_Polinomio (R); */
           free (R->coeficientes);
           R->coeficientes = NULL;

           R->grado = r.grado;
           R->coeficientes = r.coeficientes;
        }
      }
    }
  }
  else
  {
    printf ("Error: imposible dividir los polinomios.");
    exit (0);
  }
}



/* POTENCIA DE POLINOMIOS: B = A^potencia (LOS COEFICIENTES SE OPERAN MODULO p) */

void Potencia_Polinomio (A, potencia, B, p)
POLINOMIO A;
unsigned int potencia;
POLINOMIO *B;
unsigned int p;
{
  POLINOMIO R;
  unsigned int i;

  if (A.coeficientes != NULL)
  {
    Crear_Polinomio (B, 0);
    Poner_Valor_Polinomio (*B, 0, 1);

    if (potencia != 0)
    {
      for (i = 1; i <= potencia; i++)
      {
        Multiplicar_Polinomios (A, *B, &R, p);
        Destruir_Polinomio (B);
        Copiar_Polinomio (R, B);
      }
    }
  }
  else
  {
    printf ("Error: el polinomio no existe.");
    exit (0);
  }
}

