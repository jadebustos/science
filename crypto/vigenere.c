/*
  This software is licensed under GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
  (c) 2012 Jose Angel de Bustos Perez <jadebustos@gmail.com>
*/

/* 
  The following are deliberately forbidden:
        - Attempt World domination
        - Using this software as compiling massive weapon
        - Translating into Klingon
        - Ask for /home nationalisms
        - Reverse spelling of this source code
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER 100

int main ( int argc, char *argv[] ) { /* INICIO MAIN */

	FILE 	*ptFile;
	char 	chrFile[BUFFER];
	int 	intCharCount=0,
		i=0,
		intCripto=0,
		intOffset=0;

	if ( argc != 3 ) { /* INICIO if COMPROBACION ARGUMENTOS */
		printf("Uso: %s fichero n\n", argv[0]);
		printf("\tfichero: es el fichero con el texto a encriptar.\n");
		printf("\tn: desplazamiento del cifrado Vigenere.\n");
		return 1;
	} /* FINAL if COMPROBACION ARGUMENTOS */

	intOffset = abs((int)atoi(argv[2])%('Z'-'A')); /* DESPLAZAMIENTO CIFRA */

	ptFile=fopen(argv[1],"r"); /* ABRIMOS FICHERO */

	if ( ptFile == NULL ) { /* INICIO if COMPROBACION DE APERTURA DE FICHERO */
		printf("No se pudo abrir el fichero %s.\n", argv[1]);
		return 1;
	} /* FINAL if COMPROBACION DE APERTURA DE FICHERO */

	while( !feof( ptFile ) ) { /* INICIO while LECTURA FICHERO */
		intCharCount = fread(chrFile, sizeof(char), BUFFER, ptFile);
		for(i=0;i<intCharCount;i++) { /* INICIO for PROCESAMIENTO FICHERO */
			if ( chrFile[i] == '\n' || chrFile[i] == ' ' ) 
				printf("%c", chrFile[i]);
			else { /* INICIO else IMPRIMIR CRIPTOGRAMA */
				intCripto = (int)chrFile[i];
				if ( intCripto >= 'A' && intCripto <= 'Z' ) { /* INICIO if ENCRIPTACION ALFABETO MAYUSCULAS */
					intCripto = (int)chrFile[i] - 'A';
					intCripto += intOffset;
					intCripto %= ('Z'-'A'+1);
					intCripto += 'A';
				} /* FINAL if ENCRIPTACION ALFABETO MAYUSCULAS */
				else if ( intCripto >= 'a' && intCripto <= 'z' ) { /* INICIO else if ENCRIPTACION ALFABETO MINUSCULAS */
                                        intCripto = (int)chrFile[i] - 'a';
                                        intCripto += intOffset;
                                        intCripto %= ('z'-'a'+1);
                                        intCripto += 'a';
				} /* FINAL else if ENCRIPTACION ALFABETO MINUSCULAS */
				printf("%c", intCripto);
			} /* FINAL else IMPRIMIR CRIPTOGRAMA */
		} /* FINAL for PROCESAMIENTO FICHERO */
	} /* FINAL while LECTURA FICHERO */

	fclose(ptFile); /* CERRAMOS FICHERO */

	return 0;
} /* FINAL MAIN */
