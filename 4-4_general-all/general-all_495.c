#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** str_split(const char *str, char delimiter, int *size) {
    int i, count = 1;
    *size = 1;

    // Count the number of substrings
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == delimiter) {
            count++;
        }
    }

    // Allocate memory for array of strings
    char** substrings = (char**)malloc(sizeof(char*) * count);

    if (substrings == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Initialize variables for splitting
    int start = 0;
    int index = 0;

    // Split the string
    for (i = 0; i <= strlen(str); i++) {
        if (str[i] == delimiter || str[i] == '\0') {
            // Allocate memory for the substring
            substrings[index] = (char*)malloc(i - start + 1);

            if (substrings[index] == NULL) {
                printf("Memory allocation failed\n");
                exit(1);
            }

            // Copy substring
            memcpy(substrings[index], &str[start], i - start);
            substrings[index][i - start] = '\0';

            start = i + 1;
            index++;
        }
    }

    *size = count;
    return substrings;
}

int main() {
    const char* str = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    int size;
    char** substrings = str_split(str, ',', &size);

    printf("Number of substrings: %d\n", size);
    for (int i = 0; i < size; i++) {
        printf("Substring %d: %s\n", i, substrings[i]);
        free(substrings[i]);
    }

    free(substrings);
    
    return 0;
}
