#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** str_split(char* str, const char delimiter) {
    char** tokens = NULL;
    int count = 0;
    char* token = strtok(str, &delimiter);

    while (token) {
        tokens = realloc(tokens, sizeof(char*) * ++count);
        tokens[count - 1] = token;
        token = strtok(NULL, &delimiter);
    }

    tokens = realloc(tokens, sizeof(char*) * (count + 1));
    tokens[count] = NULL;

    return tokens;
}

int main() {
    char* str = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    char** substrings = str_split(str, ',');

    for (int i = 0; substrings[i]; i++) {
        printf("%s\n", substrings[i]);
    }

    free(substrings);

    return 0;
}
