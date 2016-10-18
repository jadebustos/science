This software is licensed under GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
  (c) 2013 Jose Angel de Bustos Perez <jadebustos@gmail.com>

All source code is signed with my gpg key associated at my email address.

COMPILACION
-------------

Para compilarlo descomprimir y make all.


EJECUCION
---------

El binario vigenere necesita dos argumentos:

	1 - El nombre de un fichero en texto plano con el texto a encriptar.
	2 - Desplazamiento de la cifra Vigenere.

Si el desplazamiento es 3 el texto se desplazara tres letras en el alfabeto, Cifrado del Cesar.

El desplazamiento se toma en valor absoluto y para evitar problemas se convierte al resto de dividir
el valor suministrado como argumento a su resto entre 25 que es el numero de elementos del alfabeto
que se encripta A .. Z sin incluir la letra ñ.

Los caracteres que no sean letras se dejan tal cual y las letras mayusculas y minusculas se conservan
sustituyendolas por el caracter que corresponda.

