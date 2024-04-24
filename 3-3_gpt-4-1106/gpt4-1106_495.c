#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** str_split(char* str, const char delimiter) {
    char** result = 0;
    size_t count = 0;
    char* temp_str = strdup(str);  // Create a copy of the input string
    char* last_comma = 0;
    char delim[2];
    delim[0] = delimiter;
    delim[1] = 0;

    // Count how many elements will be extracted
    char* token = strtok(temp_str, delim);
    while (token) {
        count++;
        last_comma = token;
        token = strtok(0, delim);
    }

    // Allocate memory for results
    result = malloc(sizeof(char*) * (count + 1));

    if (result) {
        size_t idx = 0;
        char* token = strtok(str, delim);

        while (token) {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        *(result + idx) = 0; // Null-terminate the array of strings
    }

    free(temp_str);
    return result;
}

void free_str_split(char** str_split_array) {
    char** temp = str_split_array;
    while (*temp) {
        free(*temp);
        temp++;
    }
    free(str_split_array);
}

int main() {
    char* str = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    char** tokens = str_split(str, ',');

    if (tokens) {
        int i;
        for (i = 0; *(tokens + i); i++) {
            printf("[%s]\n", *(tokens + i));
            free(*(tokens + i));
        }
        printf("\n");
        free(tokens);
    }

    return 0;
}
