#include <stdio.h>

#include "cod_arit.c"

/* Incluir modelo_f.c o modelo_a.c, segun se quiera comprimir con
   un modelo fijo o adaptativo */
#include "modelo_a.c"

#include "fich.c"
#include "salida.c"


main (argc, argv)
int argc;
char *argv[];
{
  unsigned char ch;

  Comprobar_Parametros (argc);
  Abrir_Ficheros (argv[1], argv[2]);

  Inicializar_Modelo ();

  while ((fscanf (fich_ent, "%c", &ch)) != EOF)
  {
    Codificar_Simbolo (ch);
    Actualizar_Modelo (ch);
  }

  Codificar_Simbolo (Simbolo_EOF);

  Escribir_Bits_Pendientes ();
  Escribir_Ultimo_Byte ();

  Cerrar_Ficheros ();
}

