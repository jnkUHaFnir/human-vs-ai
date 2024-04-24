    int process_stream (WordCountEntry entries[], int entry_count)
    {
        short line_count = 0;
        char buffer[30];
        const char *delim " \n";                        /* set delim once */
        
        while (fgets (buffer, 30, stdin)) {
            char* token = strtok(buffer, delim);
            while (token != NULL && *token != '.') {    /* compare != '.' */
                int i = 0;
                while (i < entry_count) {               /* +1 causeses UB */
                    if (!strcmp(entries[i].word, token))
                        entries[i].counter++;
                    i++;
                }
                line_count++;
                token = strtok(NULL, delim);            /* now get next token */
            }
        }
        return line_count;
    }