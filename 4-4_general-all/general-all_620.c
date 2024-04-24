#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** tokenize(const char* input, const char* sep) {
    if (!input || !sep) {
        return NULL;
    }

    char* dup = strdup(input);
    if (!dup) {
        return NULL; // Handle strdup failure
    }

    char** toks = NULL;
    size_t size = 2;
    size_t ntok = 0;

    toks = malloc(size * sizeof(*toks));
    if (!toks) {
        free(dup);
        return NULL; // Handle malloc failure
    }

    char* cur_tok = strtok(dup, sep);

    while (cur_tok) {
        if (ntok >= size - 1) { // Adjusted size check
            size *= 2;
            char** newtoks = realloc(toks, size * sizeof(*toks));
            if (!newtoks) {
                free(dup);
                for (size_t i = 0; i < ntok; ++i) {
                    free(toks[i]);
                }
                free(toks);
                return NULL; // Handle realloc failure
            }
            toks = newtoks;
        }

        toks[ntok] = strdup(cur_tok);
        if (!toks[ntok]) {
            free(dup);
            for (size_t i = 0; i < ntok; ++i) {
                free(toks[i]);
            }
            free(toks);
            return NULL; // Handle strdup failure
        }

        ntok++;
        cur_tok = strtok(NULL, sep); // Changed to NULL to continue tokenizing
    }

    free(dup);
    toks[ntok] = NULL; // Set the last entry to NULL
    return toks;
}

void tokenize_free(char*** toks) {
    if (toks && *toks) {
        for (int i = 0; (*toks)[i]; ++i) {
            free((*toks)[i]);
        }
        free(*toks);
        *toks = NULL;
    }
}

int main() {
    char line[] = "The quick brown fox jumps over the lazy dog";
    char** toks = tokenize(line, " \t");
    if (toks) {
        for (int i = 0; toks[i]; ++i) {
            printf("%s\n", toks[i]);
        }
        tokenize_free(&toks);
    } else {
        printf("Tokenization failed\n");
    }

    return 0;
}
