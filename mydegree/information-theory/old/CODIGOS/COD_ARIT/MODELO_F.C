
/* MODELO FUENTE FIJO */


int frecs[Numero_Simbolos] = {

   1,   1,   1,   1,   1,   1,   1,   1,   1,   1, 124,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,

/*      !    "    #    $    %    &    '    (    )    *    +    ,    -    .    / */
1236,   1,  21,   9,   3,   1,  25,  15,   2,   2,   2,   1,  79,  19,  60,   1,

/* 0    1    2    3    4    5    6    7    8    9    :    ;    <    =    >    ? */
  15,  15,   8,   5,   4,   7,   5,   4,   4,   6,   3,   2,   1,   1,   1,   1,

/* @    A    B    C    D    E    F    G    H    I    J    K    L    M    N    O */
   1,  24,  15,  22,  12,  15,  10,   9,  16,  16,   8,   6,  12,  23,  13,  11,

/* P    Q    R    S    T    U    V    W    X    Y    Z    [    \    ]    ^    _ */
  14,   1,  14,  28,  29,   6,   3,  11,   1,   3,   1,   1,   1,   1,   1,   3,

/* `    a    b    c    d    e    f    g    h    i    j    k    l    m    n    o */
   1, 491,  85, 173, 232, 744, 127, 110, 293, 418,   6,  39, 250, 139, 429, 446,

/* p    q    r    s    t    u    v    w    x    y    z    {    |    }    ~     */
 111,   5, 388, 375, 531, 152,  57,  97,  12, 101,   5,   2,   1,   2,   3,   1,

   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
   1
};


/* INICIALIZACION DEL MODELO */

void Inicializar_Modelo ()
{
  int i;

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
  /* No hacer nada en este caso */
}
