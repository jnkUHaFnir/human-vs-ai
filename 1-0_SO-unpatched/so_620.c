    char** tokenize(char* input, const char* sep)
    {
        /* This is the array filled with tokens and returned
        */
        char** toks = 0;
    
        /* Size of the 'toks' array. Starts low and is doubled when
        ** exhausted.
        */
        size_t size = 4;
    
        /* 'ntok' points to the next free element of the 'toks' array
        */
        size_t ntok = 0;
        size_t i;
    
        toks = malloc(size * sizeof(*toks));
    
        if ( toks == NULL )
          return NULL;
    
        toks[ntok] = strtok( input, sep );
    
    
        /* While we have more tokens to process...
        */
       
        do
        {
            /* We should still have 2 empty elements in the array, 
            ** one for this token and one for the sentinel.
            */
            if (ntok > size - 2)
            {
                char** newtoks;
                size *= 2;
    
                newtoks = realloc(toks, size * sizeof(*toks));
    
                if (newtoks == NULL)
    	        {
                    free(toks);
    		        return NULL;
    	        }
    
                toks = newtoks;
            }
            ntok++;
            toks[ntok] = strtok(0, sep);
        }  while (toks[ntok]);
    
        return toks;
    }