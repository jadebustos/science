
unsigned char Leer_Bit ()
{
  static unsigned char posicion = 1;
  static unsigned char buffer = 0;
  static unsigned char bits_aleatorios = 0;
  unsigned char ch;

  if (posicion == 1)
    if (fscanf (fich_ent, "%c", &buffer) == EOF)
      if (bits_aleatorios == 0) bits_aleatorios = 1;

  if (bits_aleatorios)
  {
    /* Devolver bits arbitrarios despues del fin de fichero,
       pero como maximo 16 */

    if (bits_aleatorios > Bits_Codigo)
    {
      printf ("Fichero de entrada erroneo.\n");
      exit (0);
    }
    bits_aleatorios++;
  }   

  ch = buffer & (1<<(8 - posicion));

  posicion++;
   
  if (posicion > 8)
    posicion = 1;

  if (ch)
    return (1);
  else
    return (0);
}


void Leer_Primer_Valor ()
{
  unsigned char i;

  for (i = 1; i <= Bits_Codigo; i++)
  {
    valor_actual = 2 * valor_actual + Leer_Bit ();
  }
}


unsigned int Decodificar_Simbolo ()
{
  Tipo_Valor_Codigo longitud_intervalo;
  Tipo_Valor_Codigo acum;
  unsigned char decodificado = 0;
  unsigned int simbolo = 1;

  /* Longitud de la region de codigo actual */
  longitud_intervalo = lim_superior - lim_inferior + 1;

  /* Encontrar la frecuencia acumulada que corresponde al valor actual */
  acum = ((valor_actual - lim_inferior + 1) * frec_acum[0] - 1) /
         longitud_intervalo;

  /* Encontrar el simbolo que corresponde a esa frecuencia acumulada */
  while (frec_acum[simbolo] > acum) simbolo++;
  simbolo -= 1;

  /* Reescalar la region de codigo segun lo que corresponda a este simbolo */
  lim_superior = lim_inferior + 
                 (longitud_intervalo * frec_acum[simbolo])/frec_acum[0] - 1;
  lim_inferior = lim_inferior + 
                 (longitud_intervalo * frec_acum[simbolo + 1])/frec_acum[0];

  /* Bucle para la entrada de bits */

  while (!decodificado)
  {
    if (lim_superior < Mitad)
    {
      /* Expandir la mitad inferior */
      valor_actual = 2 * valor_actual + Leer_Bit ();       
      lim_superior = 2 * lim_superior + 1;
      lim_inferior = 2 * lim_inferior;
    }
    else
    {
      if (lim_inferior >= Mitad)
      {
        /* Expandir la mitad superior */
        valor_actual = 2 * (valor_actual - Mitad) + Leer_Bit ();     
        lim_superior = 2 * (lim_superior - Mitad) + 1;
        lim_inferior = 2 * (lim_inferior - Mitad);
      }
      else
      {
        if (lim_inferior >= Primer_Cuarto && lim_superior < Tercer_Cuarto)
        {
          /* Expandir la mitad formada por el segundo y tercer cuartos */
          valor_actual = 2 * (valor_actual - Primer_Cuarto) + Leer_Bit ();
          lim_superior = 2 * (lim_superior - Primer_Cuarto) + 1;
          lim_inferior = 2 * (lim_inferior - Primer_Cuarto);
        }
        else
        {
          decodificado = 1;
        }
      }
    }
  }

  return (simbolo);
}

