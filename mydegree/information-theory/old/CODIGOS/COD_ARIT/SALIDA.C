

void Escribir_Bit (bit)
char bit;
{
  static unsigned char posicion = 1;
  static unsigned char buffer = 0;

  if (bit >= 0)
  {
    if (bit) buffer |= (1<<(8 - posicion));

    posicion++;
    if (posicion > 8)
    {
      fprintf (fich_sal, "%c", buffer);
      posicion = 1;
      buffer = 0;
    }
  }
  else
  {
    if (posicion != 1)
      fprintf (fich_sal, "%c", buffer);
  }
}



void Generar_Bit (bit)
unsigned char bit;
{
  /* Sacar el bit */

  Escribir_Bit (bit);

  /* Sacar tantos bits contrarios como bits pendientes */

  while (bits_pendientes > 0)  
  {
    Escribir_Bit (!bit);  
    bits_pendientes--;
  }
}



void Codificar_Simbolo (simbolo)
unsigned int simbolo;
{
  Tipo_Valor_Codigo longitud_intervalo;
  unsigned char codificado = 0;

  /* Longitud de la region de codigo actual */
  longitud_intervalo = lim_superior - lim_inferior + 1;

  /* Reescalar la region de codigo segun lo que corresponda a este simbolo */
  lim_superior = lim_inferior + 
                 (longitud_intervalo * frec_acum[simbolo])/frec_acum[0] - 1;
  lim_inferior = lim_inferior + 
                 (longitud_intervalo * frec_acum[simbolo + 1])/frec_acum[0];

  /* Bucle para la salida de bits */

  while (!codificado)
  {
    if (lim_superior < Mitad)
    {
      /* Sacar un 0 y expandir la mitad inferior */
      Generar_Bit (0);        
      lim_superior = 2 * lim_superior + 1;
      lim_inferior = 2 * lim_inferior;
    }
    else
    {
      if (lim_inferior >= Mitad)
      {
        /* Sacar un 1 y expandir la mitad superior */
        Generar_Bit (1);      
        lim_superior = 2 * (lim_superior - Mitad) + 1;
        lim_inferior = 2 * (lim_inferior - Mitad);
      }
      else
      {
        if (lim_inferior >= Primer_Cuarto && lim_superior < Tercer_Cuarto)
        {
          /* Acumular bits pendientes y expandir la mitad formada por el
             segundo y tercer cuartos */
          bits_pendientes++;
          lim_superior = 2 * (lim_superior - Primer_Cuarto) + 1;
          lim_inferior = 2 * (lim_inferior - Primer_Cuarto);
 
        }
        else
        {
          codificado = 1;
        }
      }
    }
  }
}



void Escribir_Bits_Pendientes ()
{
  bits_pendientes++;

  if (lim_inferior < Primer_Cuarto)
    Generar_Bit (0);
  else
    Generar_Bit (1);
}



void Escribir_Ultimo_Byte ()
{
  Escribir_Bit (-1);
}
