#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** str_split(char* str, const char delimiter, int* count) {
    char** result = NULL;
    int parts = 1;
    char* temp = strdup(str); // Duplicate string for safe manipulation
    char* rest = temp;

    // Count how many elements will be extracted
    while (*temp) {
        if (*temp == delimiter) {
            parts++;
        }
        temp++;
    }
    
    result = malloc(parts * sizeof(char*)); // Allocate array of pointers
    if (!result) exit(-1); // Memory allocation failed

    int idx = 0;
    char* token = strtok_r(str, &delimiter, &rest); // Split string
    while (token != NULL) {
        result[idx++] = strdup(token); // Copy each token
        token = strtok_r(NULL, &delimiter, &rest);
    }
    
    free(temp - strlen(str)); // Free the duplicated string
    *count = parts; // Set the number of parts found
    
    return result;
}

int main() {
    char str[] = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    int count = 0, i;
    char delimiter = ',';
    char** tokens = str_split(str, delimiter, &count);

    for (i = 0; i < count; i++) {
        printf("[%s]\n", tokens[i]);
        free(tokens[i]); // Free each string
    }
    free(tokens); // Free the array of pointers
    
    return 0;
}
