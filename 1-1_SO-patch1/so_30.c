    char * getline(void) {
        char * line = malloc(100);
        size_t lenmax = 100, len = lenmax;
        int c;
        
        if(line == NULL)
            return NULL;
        for(;;) {
            c = fgetc(stdin);
            if(c == EOF)
                break;
            if(--len == 0) {
                char * linen = realloc(line, lenmax *= 2);
                len = lenmax;
                if(linen == NULL) {
                    free(line);
                    return NULL;
                }
                line = linen;
            }
            if((*line++ = c) == '\n')
                break;
        }
        *line = '\0';
        return line;
    }