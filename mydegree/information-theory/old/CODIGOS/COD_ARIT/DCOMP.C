#include <stdio.h>

#include "cod_arit.c"

/* Incluir modelo_f.c o modelo_a.c, segun se quiera comprimir con
   un modelo fijo o adaptativo */
#include "modelo_a.c"

#include "fich.c"
#include "entrada.c"


main (argc, argv)
int argc;
char *argv[];
{
  unsigned int ch = 0;

  Comprobar_Parametros (argc);
  Abrir_Ficheros (argv[1], argv[2]);

  Inicializar_Modelo ();
  Leer_Primer_Valor ();

  while ((ch = Decodificar_Simbolo ()) != Simbolo_EOF)
  {
    fprintf (fich_sal, "%c", ch);
    Actualizar_Modelo (ch);
  }

  Cerrar_Ficheros ();
}

