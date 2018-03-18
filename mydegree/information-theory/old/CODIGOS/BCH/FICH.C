
extern POLINOMIO primitivo;   /* Polinomio primitivo leido del fichero */


void Abrir_Fichero (fich, nombre_fich)
FILE **fich;
char *nombre_fich;
{
  if ((*fich = fopen (nombre_fich, "r")) == NULL)
  {
    printf ("Imposible abrir el fichero. \n");
    exit (0);
  }
}



void Cerrar_Fichero (fich)
FILE **fich;
{
  if (fclose (*fich))
    printf ("Imposible cerrar el fichero. \n");
}



/* CONSTRUIR UN VALOR ENTERO HASTA ENCONTRAR BLANCO, RETORNO O EOF */

int Leer_Numero (fich, numero)
FILE *fich;
unsigned int *numero;
{
  unsigned char ch = 0;
  
  *numero = 0;

  while ((fscanf (fich, "%c", &ch) != EOF) && (ch != '\n') && (ch != ' '))
    (*numero) = (*numero)*10 + (ch - '0');

  if (ch == ' ')
    return (1);      /* blanco */
  else
    if (ch == '\n')
      return (0);    /* retorno */
    else
      return (-1);   /* EOF */
}



/* SI EXISTE EN EL FICHERO UN POLINOMIO PRIMITIVO DE GRADO g SOBRE Zp,
   SE ALMACENA EN LA VARIABLE primitivo. */

void Buscar_Primitivo_en_Fichero (p, g)
unsigned int p, g;
{
  unsigned int grado, numero = 0, retornos;
  int cod_err;
  FILE *fichero;

  Crear_Polinomio (&primitivo, g);

  Abrir_Fichero (&fichero, "primitiv.txt");

  grado = Grado_Polinomio (primitivo);

  /* Avanzar hasta donde comienzan los primitivos sobre Zp */
  while ((Leer_Numero (fichero, &numero) != EOF) && (numero < p));

  if (numero != p)
  {
    printf ("La tabla no contiene polinomios sobre Z%u.\n", p);
    exit (0);
  }

  retornos = 0;

  /* Avanzar hasta el comienzo del primitivo de grado g */
  while (retornos != (grado - 2))
  {
    cod_err = Leer_Numero (fichero, &numero);

    if (cod_err == EOF)
    {
      printf ("La tabla no contiene el primitivo de grado %u sobre Z%u.\n", grado, p);
      exit (0);
    }

    if (cod_err == 0)
      retornos++;

    if (numero >= p)    
    {
      printf ("La tabla no contiene el primitivo de grado %u sobre Z%u.\n", grado, p);
      exit (0);
    }
  }
 

  /* Almacenar el polinomio en la variable primitivo */
  do
  {
    cod_err = Leer_Numero (fichero, &numero);

    if (((cod_err == EOF) || (cod_err == 0)) && (grado != 0))
    {
      printf ("Error: el polinomio primitivo es incorrecto.\n");
      exit (0);
    }

    Poner_Valor_Polinomio (primitivo, grado, numero); 
  }
  while (grado--);

  printf ("p(x) = ");
  Ver_Polinomio (primitivo, 'x'); 
  printf ("\n\n");

  Cerrar_Fichero (&fichero);
}
