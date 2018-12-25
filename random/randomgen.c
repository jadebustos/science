/* (c) 2014, Jose Angel de Bustos Perez <jadebustos@gmail.com> */
/*     Distributed under GNU GPL v2 License                    */
/*     See COPYING.txt for more details                        */

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/random.h>

#include "log.h"

void randomgen(int number, int limit, char *filename, char *device) { /* begin - randomgen function */

    /* opening random device */
    int randomData = open(device, O_RDONLY);

    int entropy,
	i;

    unsigned int myRandomInteger;

    FILE *fd;

    /* checking if it is a random device */
    int result = ioctl(randomData, RNDGETENTCNT, &entropy);
   
    if ( result != 0 ) {
	logging("The supplied random device is not a random device.");
	exit(1);
    }

    /* opening file to store data */
    fd = fopen(filename,"w");

    if ( fd == NULL ) { /* begin - if */
	logging("The file to store the random numbers could not been opened.");
	exit(1);
    } /* end - if */

    fprintf(fd,"RND ; ENTROPY\n");

    for(i=0;i<number;i++) { /* begin - for */
	read(randomData, &myRandomInteger, sizeof(myRandomInteger));
	myRandomInteger %= limit;
	fprintf(fd, "%d ; %d \n", myRandomInteger, entropy);
    } /* end - for */

    fclose(fd);

    return;

} /* end - randomgen function */
