    #include <stdio.h>
    #include <stdlib.h> /* for malloc/free & EXIT_FAILURE */
    #include <errno.h>  /* for strtol validation */
    #include <limits.h> /* for INT_MIN/INT_MAX */
    
    #define MAXC 1024   /* don't skimp on buffer size */
    
    int main (int argc, char **argv) {
        
        int first_num,      /* your first_num */
            *arr = NULL,    /* a pointer to block to fill with int values */
            nval = 0;       /* the number of values converted */
        char buf[MAXC];     /* buffer to hold subsequent lines read */
        /* open file passed as 1st argument (default: stdin if no argument) */
        FILE *fp = argc > 1 ? fopen (argv[1], "r"): stdin;
        
        if (!fp) {  /* validate file open for reading */
            perror ("fopen-file");
            exit (EXIT_FAILURE);
        }
        
        if (fscanf (fp, "%d", &first_num) != 1) {   /* read/validate int */
            fputs ("error: invalid file format, integer not first.\n", stderr);
            exit (EXIT_FAILURE);
        }
        
        if (!fgets (buf, MAXC, fp)) {   /* read/discard '\n' */
            fputs ("error: non-POSIX ending after 1st integer.\n", stderr);
            exit (EXIT_FAILURE);
        }
        
        /* allocate/validate storage for first_num integers */
        if (!(arr = malloc (first_num * sizeof *arr))) {
            perror ("malloc-arr");
            exit (EXIT_FAILURE);
        }
        
        while (fgets (buf, MAXC, fp)) { /* read lines until conversions made */
            char *p = buf,  /* nptr & endptr for strtol conversion */
                *endptr;
            if (*p == '\n')     /* skip blank lines */
                continue;
            while (nval < first_num) {  /* loop until nval == first_num */
                errno = 0;              /* reset errno for each conversion */
                long tmp = strtol (p, &endptr, 0);  /* call strtol */
                if (p == endptr && tmp == 0) {  /* validate digits converted */
                    /* no digits converted - scan forward to next +/- or [0-9] */
                    while (*p && *p != '+' && *p != '-' && 
                            ( *p < '0' || '9' < *p))
                        p++;
                    if (*p)     /* valid start of numeric sequence? */
                        continue;   /* go attempt next conversion */
                    else
                        break;      /* go read next line */
                }
                else if (errno) {   /* validate successful conversion */
                    fputs ("error: overflow/underflow in conversion.\n", stderr);
                    exit (EXIT_FAILURE);
                }
                else if (tmp < INT_MIN || INT_MAX < tmp) {  /* validate int */
                    fputs ("error: value exceeds range of 'int'.\n", stderr);
                    exit (EXIT_FAILURE);
                }
                else {  /* valid conversion - in range of int */
                    arr[nval++] = tmp;      /* add value to array */
                    if (*endptr && *endptr != '\n') /* if chars remain */
                        p = endptr;         /* update p to endptr */
                    else        /* otherwise */
                        break;  /* bail */
                }
            }
            if (nval == first_num)  /* are all values filled? */
                break;
        }
        if (nval < first_num) { /* validate required integers found */
            fputs ("error: EOF before all integers read.\n", stderr);
            exit (EXIT_FAILURE);
        }
        
        for (int i = 0; i < nval; i++)  /* loop outputting each integer */
            printf ("arr[%2d] : %d\n", i, arr[i]);
        
        free (arr);         /* don't forget to free the memory you allocate */
        
        if (fp != stdin)    /* and close any file streams you have opened */
            fclose (fp);
        
        return 0;
    }