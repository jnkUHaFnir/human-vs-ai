    #include <stdio.h>
    #include <stdlib.h>
    
    typedef struct mystruct {
        int size;
        int *array;
    } mystruct;
    
    int main (void) {
        
        size_t i = 0;
        size_t nelements = 0;
        
        /* 
         * declaring a struct mystruct 
         */
        mystruct s;
        
        s.size = 5;
        
        /* allocating array based on size */
        s.array = malloc (s.size * sizeof *s.array);
        if (!s.array) {
            fprintf (stderr, "error: virtual memory exhausted.\n");
            return 1;
        }
        
        /* fill array */
        while (scanf ("%d", &s.array[i]) == 1) {
            i++;
            if ((int)i == s.size)
                break;  /* or realloc s.array */
        }
        nelements = i;
        
        for (i = 0; i < nelements; i++)
            printf (" s.array[%zu] = %d\n", i, s.array[i]);
        
        /* free allocated memory */
        free (s.array);
        
        putchar ('\n');
        
        /* 
         * declaring a pointer to mystruct 
         */
        mystruct *msp = NULL;
        
        /* allocate memory for msp (mystruct pointer) */
        msp = malloc (sizeof *msp);
        if (!msp) {
            fprintf (stderr, "error: virtual memory exhausted.\n");
            return 1;
        }
        
        msp->size = 5;
        
        /* allocating array based on size */
        msp->array = malloc (msp->size * sizeof *msp->array);
        if (!msp->array) {
            fprintf (stderr, "error: virtual memory exhausted.\n");
            return 1;
        }
        
        /* fill array */
        i = 0;
        while (scanf ("%d", &msp->array[i]) == 1) {
            i++;
            if ((int)i == msp->size)
                break;  /* or realloc msp->array */
        }
        nelements = i;
        
        for (i = 0; i < nelements; i++)
            printf (" msp->array[%zu] = %d\n", i, msp->array[i]);
        
        /* free allocated memory */
        free (msp->array);
        free (msp);
        
        return 0;
    }