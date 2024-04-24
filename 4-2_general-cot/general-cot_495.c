#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** str_split(const char* str, char delimiter, int* token_count) {
    int i;
    int count = 1;  // Number of tokens
    char** tokens;
    char* token;
    char* temp_str = strdup(str);

    // Count the number of tokens
    for (i = 0; temp_str[i]; i++) {
        count += (temp_str[i] == delimiter);
    }

    tokens = (char**)malloc(count * sizeof(char*));

    // Split the string
    i = 0;
    token = strtok(temp_str, &delimiter);
    while (token != NULL) {
        tokens[i++] = strdup(token);
        token = strtok(NULL, &delimiter);
    }

    *token_count = count;
    free(temp_str);

    return tokens;
}

int main() {
    char* str = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    char** tokens;
    int token_count;

    tokens = str_split(str, ',', &token_count);

    for (int i = 0; i < token_count; i++) {
        printf("%s\n", tokens[i]);
        free(tokens[i]); // Free allocated memory for each token
    }

    free(tokens); // Free memory allocated for the array of tokens

    return 0;
}
