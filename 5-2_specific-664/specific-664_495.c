#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char** str_split(const char* str, char delimiter) {
    char* temp = strdup(str);   // Make a copy of the original string as `strtok` modifies the string
    char* token = strtok(temp, &delimiter);

    char** result = malloc(MAX_SIZE * sizeof(char*));
    int i = 0;

    while (token != NULL) {
        result[i++] = strdup(token);
        token = strtok(NULL, &delimiter);
    }

    result[i] = NULL;  // Null-terminate the array of strings
    free(temp);  // Free the temporary copy

    return result;
}

int main() {
    const char* str = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    char** result = str_split(str, ',');

    int i = 0;
    while (result[i] != NULL) {
        printf("%s\n", result[i]);
        free(result[i]);  // Free memory allocated for each token
        i++;
    }

    free(result);  // Free the array of strings

    return 0;
}
