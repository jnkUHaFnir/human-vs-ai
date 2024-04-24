#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** str_split(char* str, const char* delim) {
    char** result = NULL;
    int count = 0;
    char* token = strtok(str, delim);

    while (token != NULL) {
        result = realloc(result, sizeof(char*) * (count + 1));
        result[count] = strdup(token);
        count++;
        token = strtok(NULL, delim);
    }

    result = realloc(result, sizeof(char*) * (count + 1));
    result[count] = NULL;

    return result;
}

int main() {
    char* str = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    char** array = str_split(str, ",");
    int i = 0;

    while (array[i] != NULL) {
        printf("%s\n", array[i]);
        free(array[i]);
        i++;
    }

    free(array);

    return 0;
}
