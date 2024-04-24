char** tokenize(const char* input, const char* sep, size_t* num_tokens)
{
    char* dup;
    char** toks = NULL;
    char* cur_tok;
    size_t size = 2;
    size_t ntok = 0;
    size_t i;

    *num_tokens = 0;

    if (!(dup = strdup(input))) {
        return NULL;
    }

    if (!(toks = malloc(size * sizeof(*toks)))) {
        free(dup);
        return NULL;
    }

    cur_tok = strtok(dup, sep);

    while (cur_tok) {
        if (ntok >= size - 1) {
            char** newtoks;
            size *= 2;

            newtoks = realloc(toks, size * sizeof(*toks));
            if (!newtoks) {
                break;
            }
            toks = newtoks;
        }

        toks[ntok] = strdup(cur_tok);
        if (!toks[ntok]) {
            break;
        }

        ntok++;
        cur_tok = strtok(NULL, sep);
    }

    free(dup);

    if (ntok == 0 || ntok >= size - 1) {
        // No tokens found or error during tokenization
        for (i = 0; i < ntok; ++i) {
            free(toks[i]);
        }
        free(toks);
        return NULL;
    }

    toks[ntok] = NULL;
    *num_tokens = ntok;
    return toks;
}
