    int explode(char *buffer[],const char *delimiter,const char *string){
        /*** DECLARATIONS ***/
        int numsplits = 1;
        const uint64_t delimiterlength = strlen(delimiter);
        const uint64_t strlength = strlen(string);
        /*** CODE ***/
        if(delimiterlength != 1){
            /****
             * This uses a slightly more complicated algorithm than a single-character split.
             ****/
            /* How far into the delimiter one is. */
            int delimiterencountered = 0;
            for(uint64_t str_iterator = 0;str_iterator < strlength;str_iterator++){
                /** If all of the delimiter has been encountered, then allocate another pointer to the buffer pointer array */
                if(delimiterencountered == delimiterlength){
                    /* Increment buffer pointer index */
                    numsplits++;
                    /* Allocate another pointer to the buffer pointer array */
                    realloc((char *)buffer,numsplits + sizeof(char *));
                } else if(*string == *(delimiter + delimiterencountered)){
                    /* part of the delimiter has been found, so increment the delimiterencountered variable */
                    delimiterencountered++;
                } else {
                    /* if part of the delimiter was encountered, negate that. */
                    if (delimiterencountered > 0) delimiterencountered = 0;
                    /* Copy te current character to the buffer; */
                    *buffer[numsplits] = *string;
                    /* Increment the buffer pointer */
                    buffer[numsplits]++;
                }
            }
        } else {
            for(uint64_t str_iterator = 0;str_iterator < (strlength - 1);str_iterator++){
                if(*string == *delimiter){
                    /* Increment buffer position and number of splits */
                    numsplits++;
                    /* Add 1 ?byte of memory to the array of pointers */
                    realloc((char *)buffer,numsplits * sizeof(char *));
                } else {
                    /* Copy the current character to the buffer */
                    *buffer[numsplits] = *string;
                    /* Increment the buffer pointer */
                    buffer[numsplits]++;
                }
                /* Increment the string pointer */
                string++;
            }
        }
        /*** RETURN ***/
        return numsplits;
    }