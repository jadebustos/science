

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


void Generar_Bits_Simbolo (auxp)
PAREJA *auxp;
{
  if (auxp->FP)
  {
    Generar_Bits_Simbolo (auxp->FP);
    Escribir_Bit (auxp->etiqueta);
  }
}


void Codificar_Simbolo (simbolo)
unsigned int simbolo;
{
  PAREJA *auxp;

  auxp = tabla_simbolos[simbolo].FP;

  Generar_Bits_Simbolo (auxp);

  Escribir_Bit (tabla_simbolos[simbolo].etiqueta);
}


void Escribir_Ultimo_Byte ()
{
  Escribir_Bit (-1);
}


