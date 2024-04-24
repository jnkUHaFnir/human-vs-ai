typedef struct {
    char** tokens;
    size_t length;
} TokenizedString;

TokenizedString tokenize(const char* input, const char* sep);

void freeTokenizedString(TokenizedString* tokenizedString);
