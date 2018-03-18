#include <stdio.h>

#define NUMERO_SIMBOLOS 257
#define simbolo_EOF (NUMERO_SIMBOLOS - 1)
#define LIMITE_ACTUALIZACION 5

FILE *fich_ent, *fich_sal;

#include "huffman.c"

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
  Inicializar_lista_frecs ();
  Inicializar_tabla_simbolos ();
  Inicializar_arbol ();

  while ((ch = Leer_Simbolo ()) != simbolo_EOF)
  {
    fprintf (fich_sal, "%c", ch);
    Actualizar_Modelo (ch);
  }

  Cerrar_Ficheros ();
}

