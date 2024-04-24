    #include <stdio.h>
    #include <stdlib.h>
    
    #define NCHAR 64
    
    char *readline (FILE *fp, char **buffer);
    
    int main (int argc, char **argv) {
        
        char *line = NULL;
        size_t idx = 0;
        FILE *fp = argc > 1 ? fopen (argv[1], "r") : stdin;
        if (!fp) {
            fprintf (stderr, "error: file open failed '%s'.\n", argv[1]);
            return 1;
        }
        
        while (readline (fp, &line)) {  /* read each line in 'fp' */
            printf (" line[%2zu] : %s\n", idx++, line);
            free (line);
            line = NULL;
        }
        if (fp != stdin) fclose (fp);
        free (line);
        
        return  0;
    }
    
    /* read line from 'fp' allocate *buffer NCHAR in size
     * realloc as necessary. Returns a pointer to *buffer
     * on success, NULL otherwise.
     */
    char *readline (FILE *fp, char **buffer) 
    {
        char ch;
        size_t buflen = 0, nchar = NCHAR;
        
        *buffer = malloc (nchar);    /* allocate buffer nchar in length */
        
        while ((ch = fgetc(fp)) != '\n' && ch != EOF) 
        {
            (*buffer)[buflen++] = ch;
            
            if (buflen + 1 >= nchar) {  /* realloc */
                char *tmp = realloc (*buffer, nchar * 2);
                if (!tmp) {
                    fprintf (stderr, "error: realloc failed, "
                                     "returning partial buffer.\n");
                    (*buffer)[buflen] = 0;
                    return *buffer;
                }
                *buffer = tmp;
                nchar *= 2;
            }
        }
        (*buffer)[buflen] = 0; /* nul-terminate */
        
        return buflen ? *buffer : NULL;
    }