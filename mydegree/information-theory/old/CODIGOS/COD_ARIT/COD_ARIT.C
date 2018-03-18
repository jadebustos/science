

/* DECLARACIONES USADAS PARA LA CODIFICACION Y DECODIFICACION ARITMETICA */


/* TAMANO DE LOS VALORES DEL CODIGO ARITMETICO */

#define Bits_Codigo 16           /* Numero de bits de un valor del codigo  */
typedef long Tipo_Valor_Codigo;  /* Tipo de un valor del codigo aritm‚etico */
#define Valor_Maximo (((long) 1 << Bits_Codigo) - 1) 
                                 /* Valor mas grande del codigo, 2^16 - 1  */


/* PUNTOS MITAD Y CUARTOS EN EL RANGO DE VALORES DEL CODIGO */

#define Primer_Cuarto (Valor_Maximo / 4 + 1) /* Punto siguiente al primer cuarto   */
#define Mitad (2 * Primer_Cuarto)            /* Punto siguiente a la primera mitad */
#define Tercer_Cuarto (3 * Primer_Cuarto)    /* Punto siguiente al tercer cuarto   */


/* CONJUNTO DE SIMBOLOS A SER CODIFICADOS */

#define Numero_Caracteres 256                    /* Numero de caracteres     */
#define Simbolo_EOF Numero_Caracteres            /* Indice del simbolo EOF   */
#define Numero_Simbolos (Numero_Caracteres + 1)  /* Numero total de simbolos */


/* TABLA DE FRECUENCIAS ACUMULADAS */

#define Maxima_Frecuencia (((long) 1 << (Bits_Codigo - 2)) - 1)
                        /* Contador de frecuencia ma ximo permitido, 2^14 - 1 */

int frec_acum [Numero_Simbolos + 1];   /* Frecuencias de simbolos acumuladas */


/* VARIABLES QUE DEFINEN LOS LIMITES DEL INTERVALO ACTUAL DEL CODIGO */

static Tipo_Valor_Codigo lim_superior = Valor_Maximo;
static Tipo_Valor_Codigo lim_inferior = 0;


/* CONTADOR DE BITS OPUESTOS A ENVIAR DESPUES DEL SIGUIENTE BIT */

static Tipo_Valor_Codigo bits_pendientes = 0;


/* VALOR ACTUAL DENTRO DE LA REGION DEL CODIGO */

static Tipo_Valor_Codigo valor_actual = 0;


