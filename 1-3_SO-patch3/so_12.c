    #include <stdio.h>
    #include <stdlib.h>
    
    enum { MAXL = 40, MAXC = 50 };
    
    int main (int argc, char **argv) {
    
        char (*lines)[MAXC] = NULL; /* pointer to array of type char [MAXC] */
        int i, n = 0;
        FILE *fp = argc > 1 ? fopen (argv[1], "r") : stdin;
    
        if (!fp) {  /* valdiate file open for reading */
            fprintf (stderr, "error: file open failed '%s'.\n", argv[1]);
            return 1;
        }
    
        if (!(lines = malloc (MAXL * sizeof *lines))) { /* allocate MAXL arrays */
            fprintf (stderr, "error: virtual memory exhausted 'lines'.\n");
            return 1;
        }
    
        while (n < MAXL && fgets (lines[n], MAXC, fp)) { /* read each line */
            char *p = lines[n];                  /* assign pointer */
            for (; *p && *p != '\n'; p++) {}     /* find 1st '\n'  */
            *p = 0, n++;                         /* nul-termiante  */
        }
        if (fp != stdin) fclose (fp);   /* close file if not stdin */
    
        /* print lines */
        for (i = 0; i < n; i++) printf (" line[%2d] : '%s'\n", i + 1, lines[i]);
    
        free (lines);   /* free allocated memory */
    
        return 0;
    }