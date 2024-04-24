#define INITIAL_SIZE 16

typedef struct {
    char** tokens;
    size_t count;
} TokenArray;

TokenArray* tokenize(const char* input, const char* sep) {
    /* Initialization and tokenization code */
    /* ... */

    /* Initialize a new TokenArray */
    TokenArray* tokenArray = malloc(sizeof(TokenArray));
    tokenArray->tokens = toks;
    tokenArray->count = ntok;

    return tokenArray;
}

void tokenize_free(TokenArray* token_array) {
    for (size_t i = 0; i < token_array->count; i++) {
        free(token_array->tokens[i]);
    }
    free(token_array->tokens);
    free(token_array);
}
