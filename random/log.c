/* (c) 2014, Jose Angel de Bustos Perez <jadebustos@gmail.com> */
/*     Distributed under GNU GPL v2 License                    */
/*     See COPYING.txt for more details                        */

#include <stdio.h>
#include <time.h>
#include <string.h>

void logging(char *log_message) { /* begin - log function */

    FILE *fd;
    struct tm *tminfo;
    time_t tmraw;

    /* getting time */
    time(&tmraw);
    tminfo = localtime(&tmraw);

    /* opening log file to add log */
    fd = fopen("random.log","a");

    if ( fd != NULL ) { /* begin - if */
	fprintf(fd,"[%s] - %s\n", strtok(asctime(tminfo),"\n"), log_message);
    } /* end - if */
    else { /* begin - else */
	printf("Error opening the log file.\n");
	printf("\t *** %s\n", log_message);
    } /* end - else */

    /* closing log file */
    fclose(fd);

} /* end - log function */
