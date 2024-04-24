#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** str_split(const char* str, const char delim) {
    int num_delims = 0;
    const char* ptr = str;

    // Count the number of delimiters in the string
    while (*ptr) {
        if (*ptr == delim) {
            num_delims++;
        }
        ptr++;
    }

    // Allocate memory for the array of strings
    char** result = (char**)malloc((num_delims + 1) * sizeof(char*));

    if (result == NULL) {
        return NULL;
    }

    // Copy each substring into the array of strings
    int i = 0;
    char* token = strtok((char*)str, &delim);
    while (token != NULL) {
        result[i] = strdup(token);
        token = strtok(NULL, &delim);
        i++;
    }
    result[i] = NULL; // Set the last element of the array to NULL

    return result;
}

int main() {
    char* str = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    char** result = str_split(str, ',');

    for (int i = 0; result[i] != NULL; i++) {
        printf("%s\n", result[i]);
    }

    // Free the memory allocated for the array of strings
    for (int i = 0; result[i] != NULL; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
