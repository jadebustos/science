/* (c) 2014, Jose Angel de Bustos Perez <jadebustos@gmail.com> */
/*     Distributed under GNU GPL v2 License                    */
/*     See COPYING.txt for more details                        */

#include <stdio.h>

void help(void) { /* begin - help function */

    printf("Arguments:\n");
    printf("\t\t --multithread: to use as many threads as processors. No arguments. Not implemented.\n");
    printf("\t\t --number: how many pseudo-random numbers to be generated (specified as a mandatory argument).\n");
    printf("\t\t --limit: Pseudo-random numbers will be generated between 0 and limit - 1 (specified as a mandatory argument).\n");
    printf("\t\t --device: Character device to get the pseudo-random number (specified as a mandatory argument: /dev/random or /dev/urandom).\n");
    printf("\t\t --filename: filename to store the pseudo-random numbers (specified as a mandatory argument).\n");
    printf("\t\t --help: this message.\n\n");
    return;

} /* end - help function */
