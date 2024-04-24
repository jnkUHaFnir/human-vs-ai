char** tokenize(const char* input, const char* sep)
{
    char* dup;
    char** toks = NULL;
    size_t size = 2;
    size_t ntok = 0;
    char* cur_tok;
    size_t i;

    if (!input || !sep) {
        return NULL; // Input validation
    }

    if (!(dup = strdup(input))) {
        return NULL;
    }

    if (!(toks = malloc(size * sizeof(*toks)))) {
        free(dup);
        return NULL;
    }

    cur_tok = strtok(dup, sep);

    while (cur_tok)
    {
        if (ntok > size - 2)
        {
            char** newtoks;
            size *= 2;

            newtoks = realloc(toks, size * sizeof(*toks));

            if (!newtoks)
            {
                free(dup);
                for (i = 0; i < ntok; ++i) {
                    free(toks[i]);
                }
                free(toks);
                return NULL;
            }

            toks = newtoks;
        }

        if (cur_tok[0] != '\0') {
            toks[ntok] = strdup(cur_tok); // Handle empty tokens
            if (!toks[ntok]) {
                free(dup);
                for (i = 0; i < ntok; ++i) {
                    free(toks[i]);
                }
                free(toks);
                return NULL;
            }
            ntok++;
        }

        cur_tok = strtok(NULL, sep);
    }

    free(dup);
    toks[ntok] = NULL;
    return toks;
}
