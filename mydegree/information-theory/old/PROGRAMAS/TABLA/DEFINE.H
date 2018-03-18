#ifndef _DEFINE_H
   #define _DEFINE_H 1

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                         CONSTANTES SIMBOLICAS                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* CONSTANTE UTILIZADA PARA INDICAR QUE NO OCURRIO NINGUN ERROR */

#ifdef BIEN
       #undef BIEN
       #define BIEN 0
#else
       #define BIEN 0

#endif

/* CONSTANTE UTILIZADA PARA INDICAR QUE OCURRIO ALGUN TIPO DE ERROR */

#ifdef MAL
       #undef MAL
       #define MAL 1
#else
       #define MAL 1
#endif

/* CONSTANTE UTILIZADA PARA INDICAR QUE HUBO UN ERROR DE MEMORIA */

#ifdef ERR_MEM
       #undef ERR_MEM
       #define ERR_MEM -1
#else
       #define ERR_MEM -1
#endif

#endif
