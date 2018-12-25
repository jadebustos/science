/* (c) 2014, Jose Angel de Bustos Perez <jadebustos@gmail.com> */
/*     Distributed under GNU GPL v2 License                    */
/*     See COPYING.txt for more details                        */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "help.h"
#include "log.h"
#include "randomgen.h"

int main(int argc, char *argv[]) { /* begin - main function */

    int num_threads = 1,    /* number of threads */
	random_numbers = 0, /* how many randon numbers to generate */
	random_limit = 0;   /* random numbers between 0 and random_limit -1 */

    char *random_device,
	*filename;

    while (1) { /* begin - while */
	static struct option long_options[] = {
	    {"multithread", no_argument, 0, 'm'},
	    {"number", required_argument, 0, 'n'},
	    {"limit", required_argument, 0, 'l'},
	    {"device", required_argument, 0, 'd'},
	    {"filename", required_argument, 0, 'f'},
	    {"help", no_argument, 0, 'h'},
	    {0, 0, 0, 0}
	};

	int option_index = 0,
	    c;

	c = getopt_long(argc, argv, "mn:l:d:", long_options, &option_index);

	/* end of options */
	if ( c == -1 ) { break; }

	/* processing arguments */
	switch(c) { /* begin - switch */
	case 'm':
	    printf("m\n");
	    break;
	case 'n':
	    random_numbers = atoi(optarg);
	    break;
	case 'l':
	    random_limit = atoi(optarg);
	    break;
	case 'd':
	    random_device = (char *)calloc(strlen(optarg)+1, sizeof(char));
	    if ( random_device == NULL ) { /* begin - if */
		logging("Error reserving memory to store the random device.");
		exit(1);
	    } /* end - if */
	    strcpy(random_device,optarg);
	    break;
	case 'f':
	    filename = (char *)calloc(strlen(optarg)+1, sizeof(char));
	    if ( filename == NULL ) { /* begin - if */
		logging("Error reserving memory to store the filename.");
		exit(1);
	    } /* end - if */
	    strcpy(filename,optarg);
	    break;
	default:
	    help();
	    exit(0);
	    break;
	} /* end - switch */

    } /* end - while */

    randomgen(random_numbers, random_limit, filename, random_device);

} /* end - main function */
