#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** str_split(char* str, const char delimiter) {
    char** result = NULL;
    size_t count = 0;
    char* tmp = str;
    char* last_comma = NULL;
    char delim[2];
    delim[0] = delimiter;
    delim[1] = '\0';

    // Count number of substrings
    while (*tmp) {
        if (*tmp == delimiter) {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }
    count += last_comma < (str + strlen(str) - 1);

    // Allocate memory for substrings
    result = (char**)malloc((count + 1) * sizeof(char*));

    if (result) {
        size_t idx = 0;
        char* token = strtok(str, delim);

        while (token) {
            *(result + idx++) = strdup(token);
            token = strtok(NULL, delim);
        }
        *(result + idx) = NULL;
    }

    return result;
}

int main() {
    char* str = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    char** tokens = str_split(str, ',');
    if (tokens) {
        for (int i = 0; *(tokens + i); i++) {
            printf("Token[%d] = %s\n", i, *(tokens + i));
            free(*(tokens + i));
        }
        free(tokens);
    }
    return 0;
}
