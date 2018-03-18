
/* MODELO FUENTE ADAPTATIVO */


int frecs[Numero_Simbolos];


/* INICIALIZACION DEL MODELO */

void Inicializar_Modelo ()
{
  int i;

  /* Inicializar a unos la matriz de frecuencias */

  for (i = 0; i < Numero_Simbolos; i++)
  {
    frecs[i] = 1;
  }

  /* Inicializar la matriz de frecuencias acumuladas */

  frec_acum[Numero_Simbolos] = 0;

  for (i = Numero_Simbolos; i > 0; i--)       
  {                                      
    frec_acum[i - 1] = frec_acum[i] + frecs[i - 1];
  }

  /* Comprobar si los contadores estan dentro del limite */

  if (frec_acum[0] > Maxima_Frecuencia)          
  {  
    printf ("Error en los valores de las frecuencias.");  
    exit (0);
  }
}


/* ACTUALIZAR EL MODELO CUANDO SE RECIBE UN NUEVO SIMBOLO */

void Actualizar_Modelo (caracter)
unsigned char caracter;
{ 
  int i;
 
  /* Si los contadores de frecuencia estan en el maximo, se dividen
     a la mitad, con cuidado de que no se conviertan en cero, y se
     recalculan las frecuencias acumuladas */  
  if (frec_acum[0] == Maxima_Frecuencia)
  {
    for (i = 0; i < Numero_Simbolos; i++) 
      frecs[i] = (frecs[i] + 1) / 2; 

    frec_acum[Numero_Simbolos] = 0;
    for (i = Numero_Simbolos; i > 0; i--)       
    {                                      
      frec_acum[i - 1] = frec_acum[i] + frecs[i - 1];
    }   
  }

  /* Incrementar el contador de frecuencia del caracter y actualizar
     las frecuencias acumuladas */
  i = caracter;
  frecs[i] += 1;
  while (i >= 0)
  {
    frec_acum[i] += 1;
    i--;
  }  
}
