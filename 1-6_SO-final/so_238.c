    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #define MAXPTRS 32
    
    char **read_input (FILE *fp, size_t *ndx)
    {
        size_t maxp = MAXPTRS,  /* initial number of pointers */
            n = 0;              /* initial memory for line (0, getline decides) */
        ssize_t nchr = 0;       /* number of chars read by getline */
        char *line = NULL,      /* buffer to read each line */
            **lines = NULL;     /* pointer to pointer to all stored lines */
        *ndx = 0;               /* zero index pointer passed from caller */
        
        if (!(lines = calloc (maxp, sizeof *lines))) { /* allocate pointers */
            fprintf (stderr, "read_input: memory exhausted.\n");
            return NULL;
        }
        
        /* read each line (into line) */
        while ((nchr = getline (&line, &n, fp)) != -1) {
            if (nchr && line[nchr - 1] == '\n') /* chk/trim trailing '\n' */
                line[--nchr] = 0;
            lines[*ndx] = strdup (line); /* duplicate line (belongs to getline) */
            if (++(*ndx) == maxp) {      /* check if reallocation of ptrs req'd */
                void *tmp = realloc (lines, sizeof *lines * maxp * 2);
                if (!tmp) {     /* if realloc fails, bail */
                    fprintf (stderr, "read_input: memory exhausted - realloc.\n");
                    goto memlimit;
                }
                lines = tmp;    /* assign reallocted block to lines */
                /* zero all new memory (optional) */
                memset (lines + maxp, 0, maxp * sizeof *lines);
                maxp *= 2;      /* increment number of allocated pointers */
            }
        }
        /* final realloc to reduce to exact number of pointers */
        void *tmp = realloc (lines, *ndx * sizeof *lines);
        if (tmp)
            lines = tmp;
        
        memlimit:;              /* label for goto */
        
        if (line) free (line);  /* free line (it belongs to getline) */
        
        return lines;
    }
    
    int main (int argc, char **argv) {
    
        size_t n = 0;           /* number of lines read by read_input */
        char **lines = NULL;    /* ptr to ptr to char for lines returned */
        FILE *fp = argc > 1 ? fopen (argv[1], "r") : stdin;
    
        if (!fp) {  /* validate file open for reading */
            fprintf (stderr, "error: file open failed '%s'.\n", argv[1]);
            return 1;
        }
        
        /* call read_input/validate return */
        if (!(lines = read_input (fp, &n)) || n == 0) {
            fprintf (stderr, "error: read_input failed.\n");
            return 1;
        }
        if (fp != stdin) fclose (fp);       /* close file if not stdin */
        
        for (size_t i = 0; i < n; i++) {    /* iterate over each line */
            printf ("line[%3zu] : %s\n", i, lines[i]);
            free (lines[i]);                /* free memory for line */
        }
        free (lines);                       /* free pointers */
        
        return 0;
    }