

unsigned long frecs[NUMERO_SIMBOLOS];


void Inicializar_Modelo ()
{
  unsigned int i;

  for (i = 0; i < NUMERO_SIMBOLOS; i++)
  { 
    frecs[i] = 1;
  }
}


void Actualizar_Modelo (simbolo)
unsigned int simbolo;
{
  PAREJA *auxp1, *auxp2;
  unsigned char etiq1, etiq2, es_simb, salir;
  unsigned long acum;

  struct {
    struct {
      unsigned char es_simbolo;
      union {
        SIMBOLO *PS;
        PAREJA *PP;
      } PT;
    } BP;

    unsigned long acum;
  } E1, E2;


  if (++(tabla_simbolos[simbolo].contador_actualizacion) ==
      LIMITE_ACTUALIZACION)
  {
    tabla_simbolos[simbolo].contador_actualizacion = 0;

    auxp1 = tabla_simbolos[simbolo].FP;
    etiq1 = tabla_simbolos[simbolo].etiqueta;

    while (auxp1)
    {
      if (etiq1)
      {
        (auxp1->acum1)++;
        acum = auxp1->acum1;
        es_simb = (auxp1->BP1).es_simbolo;
      }
      else
      {
        (auxp1->acum0)++;
        acum = auxp1->acum0;
        es_simb = (auxp1->BP0).es_simbolo;
      }

      auxp2 = auxp1;
      etiq2 = etiq1;

      /* mover auxp2 */

      salir = 0;

      while (!salir)
      {
        if (etiq2)
        {
          if (auxp2->acum0 >= acum) 
            salir++;
        }
        else
        {
          if (auxp2->sig_pareja)
          {
            if ((auxp2->sig_pareja)->acum1 >= acum)
              salir++;
          }
          else
          {
            salir++;
          }
        }

        if (!salir)
        {
          if (etiq2)
          {
            etiq2 = 0;
          }
          else
          {
            if (auxp2->sig_pareja)
            {
              auxp2 = auxp2->sig_pareja;
              etiq2 = 1;
            }
            else
            {
              salir++;
            }
          }
        }
      }

      if ((auxp1 != auxp2) || (etiq1 != etiq2))
      {
        /* cambiar contenido y punteros */

        if (etiq1)
        {
          E1.acum = auxp1->acum1;
          E1.BP.es_simbolo = (auxp1->BP1).es_simbolo;
          if (E1.BP.es_simbolo)
            E1.BP.PT.PS = (auxp1->BP1).PT.PS;
          else
            E1.BP.PT.PP = (auxp1->BP1).PT.PP;
        }
        else
        {
          E1.acum = auxp1->acum0;
          E1.BP.es_simbolo = (auxp1->BP0).es_simbolo;
          if (E1.BP.es_simbolo)
            E1.BP.PT.PS = (auxp1->BP0).PT.PS;
          else
            E1.BP.PT.PP = (auxp1->BP0).PT.PP;
        }

        if (etiq2)
        {
          E2.acum = auxp2->acum1;
          E2.BP.es_simbolo = (auxp2->BP1).es_simbolo;
          if (E2.BP.es_simbolo)
            E2.BP.PT.PS = (auxp2->BP1).PT.PS;
          else
            E2.BP.PT.PP = (auxp2->BP1).PT.PP;

          auxp2->acum1 = E1.acum;
          (auxp2->BP1).es_simbolo = E1.BP.es_simbolo;
          if (E1.BP.es_simbolo)
            (auxp2->BP1).PT.PS = E1.BP.PT.PS;
          else
            (auxp2->BP1).PT.PP = E1.BP.PT.PP;
        }
        else
        {
          E2.acum = auxp2->acum0;
          E2.BP.es_simbolo = (auxp2->BP0).es_simbolo;
          if (E2.BP.es_simbolo)
            E2.BP.PT.PS = (auxp2->BP0).PT.PS;
          else
            E2.BP.PT.PP = (auxp2->BP0).PT.PP;

          auxp2->acum0 = E1.acum;
          (auxp2->BP0).es_simbolo = E1.BP.es_simbolo;
          if (E1.BP.es_simbolo)
            (auxp2->BP0).PT.PS = E1.BP.PT.PS;
          else
            (auxp2->BP0).PT.PP = E1.BP.PT.PP;
        }

        if (etiq1)
        {
          auxp1->acum1 = E2.acum;
          (auxp1->BP1).es_simbolo = E2.BP.es_simbolo;
          if (E2.BP.es_simbolo)
            (auxp1->BP1).PT.PS = E2.BP.PT.PS;
          else
            (auxp1->BP1).PT.PP = E2.BP.PT.PP;
        }
        else
        {
          auxp1->acum0 = E2.acum;
          (auxp1->BP0).es_simbolo = E2.BP.es_simbolo;
          if (E2.BP.es_simbolo)
            (auxp1->BP0).PT.PS = E2.BP.PT.PS;
          else
            (auxp1->BP0).PT.PP = E2.BP.PT.PP;
        }

        if (E1.BP.es_simbolo)
        {
          (E1.BP.PT.PS)->FP = auxp2;
          (E1.BP.PT.PS)->etiqueta = etiq2;
        }
        else
        {
          (E1.BP.PT.PP)->FP = auxp2;
          (E1.BP.PT.PP)->etiqueta = etiq2;
        }

        if (E2.BP.es_simbolo)
        {
          (E2.BP.PT.PS)->FP = auxp1;
          (E2.BP.PT.PS)->etiqueta = etiq1;
        }
        else
        {
          (E2.BP.PT.PP)->FP = auxp1;
          (E2.BP.PT.PP)->etiqueta = etiq1;
        }
      }

      auxp1 = auxp2->FP;
      etiq1 = auxp2->etiqueta;
    }
  }
}


