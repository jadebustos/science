/*--------------------------------------------------------------------------
      ESTRUCTURA QUE CONTIENE LOS PARAMETROS PARA RESOLVER EL PROBLEMA
--------------------------------------------------------------------------*/

struct datos
        
        {

        int pre, /* PRECISION CON LA QUE SE MOSTRARAN LOS CALCULOS */
            ite, /* NUMERO MAXIMO DE ITERACIONES */
            N, /* NUMERO DE SEGMENTOS DEL CANAL */
            newton_ite, /* NUMERO DE ITERACIONES EN EL METODO DE NEWTON */
            broyden_ite; /* NUMERO DE ITERACIONES EN EL METODO DE BROYDEN */

        double tol, /* TOLERANCIA */
               fuerza, /* FUERZA DE FRICCION*/
               X, /* COORDENADA X DEL FINAL DEL CANAL */
               incr_y, /* INCREMENTO DE Y */
               velocidad_inicial, /* VELOCIDAD INICIAL */
               gravedad; /* GRAVEDAD EN pies/seg^2 */
        };
