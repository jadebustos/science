#include <ctype.h>
#include <conio.h>

/*-------------------------------------------------------------
	FUNCION QUE LEE UNA PULSACION DE TECLADO O DE CONTROL
	PULSACIONES DE CONTROL

	F1      'AYUDA'                         ECO ';'
	RE PAG  'RETROCEDE PAGINA'              ECO 'I'
	AV PAG  'AVANZA PAGINA'                 ECO 'Q'
	INICIO  'IR A LA PRIMERA PAGINA'        ECO 'G'
	FIN     'IR A LA ULTIMA PAGINA'         ECO 'O'
	ESC     'SALIR DE LAS AYUDAS'   DEVUELVE EL VALOR 27 EN DECIMAL

	CURSOR  'ARRIBA'        ECO 'H'
	CURSOR  'DERECHA'       ECO 'M'
	CURSOR  'ABAJO'         ECO 'P'
	CURSOR  'IZQUIERDA'     ECO 'K'

	PULSACIONES DE TECLADO NORMALES

	C 'CIFRAS SIGNIFICATIVAS'
	T 'TOLERANCIA'
	N 'NUMERO DE ITERACIONES'
	F 'FUERZA DE FRICCION'
	X 'COORDENADA X'
	Y 'INCREMENTO DE Y'
	V 'VELOCIDAD INICIAL'
	G 'GRAVEDAD'
	R 'NUMERO DE SEGMENTOS'

-------------------------------------------------------------*/

char leer_tecla (void)

{

/* COMPRUEBA SI ES UN CARACTER DE CONTROL Y SI LO ES LO DEVUELVE COMO
   MINUSCULA SI SE PULSA UN CARACTER DE CONTROL, POR EJEMPLO RE PAG LA
   FUNCION iscntrl DEVULVE UN VALOR DISTINTO DE CERO Y QUEDA UN ECO 'I'
   ENTONCES PARA NO CONFUNDIR CON LAS OPCIONES DEL PROGRAMA, TODAS ELLAS EN
   MINUSCULA ESTE PROGRAMA DEVUELVE EL ECO EN MINUSCULA DE ESTA FORMA SABEMOS
   QUE ES UN CARCTER DE CONTROL Y CUAL ES, SI ES UN CARACTER NORMAL LO
   DEVUELVE EN MAYUSCULA */

char tecla;

do
	tecla = toupper ( getch() );

while ( iscntrl ( tecla ) == 0  && tecla != 'C' &&
	tecla != 'T' && tecla != 'N' && tecla != 'F' && tecla != 'X' &&
	tecla != 'Y' && tecla != 'V' && tecla != 'G' && tecla != 'R' &&
	tecla != 27  && tecla != 'h' && tecla != 'm' && tecla != 'p' &&
	tecla != 'k' );

if ( tecla == 0 )
	tecla = tolower( getch () ); /* RECOGE EL ECO */

return (tecla);
}

/*--------------------------------------------------------------------------
  FUNCION QUE LEE UNA PULSACION DE TECLADO Y LA DEVUELVE SI ES 1, 2 O 3
  COMO SI FUERA UN CARACTER
--------------------------------------------------------------------------*/

char leer_num(void)
{
char tecla;

do
	{
	tecla = getch();
	}

while ( tecla != '1' && tecla != '2' && tecla != '3');

return (tecla);
}

/*--------------------------------------------------------------------------
  PRESENTA LAS OPCIONES DE SEGUIR CON LA EJECUCION DEL PROGRAMA O SALIR
--------------------------------------------------------------------------*/

char opciones(void)

{
char tecla;

textcolor(LIGHTRED);

gotoxy(8,7);
cprintf("C");

gotoxy(8,9);
cprintf("S");

textcolor(WHITE);

gotoxy(9,7);
cprintf("ontinuar.");

gotoxy(9,9);
cprintf("alir.");

gotoxy(8,11);
cprintf("Opcion: ");

do
	{
	tecla = toupper(getch () );
	}

while ( tecla != 'S' && tecla != 'C' );

return (tecla);
}
