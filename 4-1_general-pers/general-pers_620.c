char** tokenize(const char* input, const char* sep)
{
    char* dup = NULL;
    char** toks = NULL;
    char* cur_tok = NULL;
    size_t size = 8; // Initial size for token array
    size_t ntok = 0;
    size_t i;

    if (!input || !sep) {
        return NULL;
    }

    if (!(dup = strdup(input))) {
        return NULL;
    }

    if (!(toks = malloc(size * sizeof(*toks))) {
        free(dup);
        return NULL;
    }

    cur_tok = strtok(dup, sep);

    while (cur_tok) {
        if (ntok >= size - 1) {
            size *= 2;
            char** newtoks = realloc(toks, size * sizeof(*toks));

            if (!newtoks) {
                free(dup);
                for (i = 0; i < ntok; ++i) {
                    free(toks[i]);
                }
                free(toks);
                return NULL;
            }

            toks = newtoks;
        }

        toks[ntok] = strdup(cur_tok);

        if (!toks[ntok]) {
            free(dup);
            for (i = 0; i < ntok; ++i) {
                free(toks[i]);
            }
            free(toks);
            return NULL;
        }

        ntok++;
        cur_tok = strtok(NULL, sep);
    }

    free(dup);
    toks[ntok] = NULL;
    return toks;
}
