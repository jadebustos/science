

void Comprobar_Parametros (num_params)
int num_params;
{
  if (num_params != 3)
  {
    printf ("Sintaxis: comp <fichero_entrada> <fichero_salida> \n");
    exit (0);
  }
}


void Abrir_Ficheros (nombre_fich_ent, nombre_fich_sal)
char *nombre_fich_ent, *nombre_fich_sal;
{
  if ((fich_ent = fopen (nombre_fich_ent, "rb")) == NULL)
  {
    printf ("Imposible abrir el fichero de entrada. \n");
    exit (0);
  }

  if ((fich_sal = fopen (nombre_fich_sal, "wb")) == NULL)
  {
    printf ("Imposible abrir el fichero de salida. \n");
    exit (0);
  }
}


void Cerrar_Ficheros ()
{
  if (fclose (fich_ent))
    printf ("Imposible cerrar el fichero de entrada. \n");

  if (fclose (fich_sal))
    printf ("Imposible cerrar el fichero de salida. \n");
}


