        while (fgets (buffer, 30, stdin)) {
            ...
            while (token != NULL) {
                if (!strcmp (token, "."))               /* compare != '.' */
                    goto done;
                ...
        }
        done:;
        
        return line_count;
    }