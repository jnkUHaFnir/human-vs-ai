char** tokenize_safe(const char* input, const char* sep);
void free_tokens(char*** tokens);

int main() {
    char line[] = "The quick brown fox jumps over the lazy dog";
    char** tokens = tokenize_safe(line, " \t");
    
    if (tokens) {
        for (int i = 0; tokens[i]; ++i) {
            printf("%s\n", tokens[i]);
        }
        free_tokens(&tokens);
    }

    return 0;
}

char** tokenize_safe(const char* input, const char* sep) {
    if (!input || !sep) {
        return NULL;
    }

    char* input_copy = strdup(input);
    if (!input_copy) {
        return NULL;
    }

    char** tokens = NULL;
    size_t size = 10;
    size_t ntok = 0;
    
    char* token = strtok(input_copy, sep);
    while (token) {
        if (ntok >= size - 1) {
            size *= 2;
            char** temp = realloc(tokens, size * sizeof(*tokens));
            if (!temp) {
                free(input_copy);
                free_tokens(&tokens);
                return NULL;
            }
            tokens = temp;
        }

        tokens[ntok] = strdup(token);
        if (!tokens[ntok]) {
            free_tokens(&tokens);
            free(input_copy);
            return NULL;
        }

        ntok++;
        tokens[ntok] = NULL;
        token = strtok(NULL, sep);
    }

    free(input_copy);
    return tokens;
}

void free_tokens(char*** tokens) {
    if (tokens && *tokens) {
        for (int i = 0; (*tokens)[i]; i++) {
            free((*tokens)[i]);
        }
        free(*tokens);
        *tokens = NULL;
    }
}
