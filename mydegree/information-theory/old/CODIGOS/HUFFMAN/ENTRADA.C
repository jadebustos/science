


unsigned char Leer_Bit ()
{
  static unsigned char posicion = 1;
  static unsigned char buffer = 0;
  unsigned char ch;

  if (posicion == 1)
    if (fscanf (fich_ent, "%c", &buffer) == EOF)
    {
      printf ("Error: fichero de entrada no valido.");
      exit (0);
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

unsigned int Leer_Simbolo ()
{
  PAREJA *auxp;
  SIMBOLO *auxs;

  auxp = arbol;
  auxs = NULL;

  while (!auxs)
  {
    if (Leer_Bit ())
    {
      if ((auxp->BP1).es_simbolo)
        auxs = (auxp->BP1).PT.PS;
      else
        auxp = (auxp->BP1).PT.PP;
    }
    else
    {
      if ((auxp->BP0).es_simbolo)
        auxs = (auxp->BP0).PT.PS;
      else
        auxp = (auxp->BP0).PT.PP;
    }
  }

  return (auxs - tabla_simbolos);
}


