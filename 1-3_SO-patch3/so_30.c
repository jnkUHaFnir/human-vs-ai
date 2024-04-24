    char * getline(void) {
        char * line = malloc(100);
        size_t lenmax = 100, len = lenmax;
        int c;
        
        for(;;) {
            c = fgetc(stdin);
            if(c == EOF)
                break;
            if(len-- == 0) {
                line = realloc(line, lenmax *= 2);
                len = lenmax;
            }
            if((*line++ = c) == '\n')
                break;
        }
        *line = '\0';
        return line;
    }