#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** str_split(const char* str, char delimiter) {
    // Count the number of delimiters to determine the number of elements in the resulting array
    int count = 1; // initialize to 1 to account for the last token
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delimiter) {
            count++;
        }
    }

    // Allocate memory for array of strings
    char** result = (char**)malloc(count * sizeof(char*));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed");
        exit(1);
    }

    char* token = strtok((char*)str, &delimiter);
    int i = 0;
    while (token != NULL) {
        result[i] = (char*)malloc(strlen(token) + 1);
        strcpy(result[i], token);
        token = strtok(NULL, &delimiter);
        i++;
    }

    return result;
}

int main() {
    const char* str = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    char** tokens = str_split(str, ',');

    for (int i = 0; tokens[i] != NULL; i++) {
        printf("%s\n", tokens[i]);
        free(tokens[i]); // free memory allocated for each token
    }

    free(tokens); // free memory allocated for the array of tokens

    return 0;
}
