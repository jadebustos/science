# random

## Copyright

This software is licensed under GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
  
  (c) 2013 Jose Angel de Bustos Perez <jadebustos@gmail.com>

## Introduction

This software is intended to generate pseudo-random numbers using a char device under linux. These numbers are stored in a text file with two colums using ";" as a delimiter. The first column is the pseudo-random number and the second is the entropy in the system.

## Arguments

The following arguments are used:

* **--multithread** to use as many threads as processors. No arguments. Not implemented.
* **--number** how many pseudo-random numbers to be generated (specified as a mandatory argument).
* **--limit** Pseudo-random numbers will be generated between 0 and limit - 1 (specified as a mandatory argument). Which is really stored is the modulus of the random number using the parameter specified in limit.
* **--device** Character device to get the pseudo-random number (specified as a mandatory argument: /dev/random or /dev/urandom). Could be used any random character device.  
* **--filename** filename to store the pseudo-random numbers (specified as a mandatory argument).
* **--help** this message.

## Compiling

```
[user@localhost ~]$ make all
gcc    -c -o help.o help.c
gcc    -c -o log.o log.c
gcc    -c -o randomgen.o randomgen.c
gcc random.c help.o log.o randomgen.o -o random
[user@localhost ~]$
```

## Example

To generate 10000 pseudo-random numbers between 0 and 255 using /dev/random and storing them in a file with name random.txt:

```
[user@localhost ~]$ ./random --number 10000 --limit 256 --device /dev/random --filename random.txt
```
