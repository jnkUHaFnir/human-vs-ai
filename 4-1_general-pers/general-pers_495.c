#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** str_split(const char* str, char delimiter, int* count) {
    // Count the number of delimiters to determine the number of elements in the resulting array
    *count = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delimiter) {
            (*count)++;
        }
    }

    // Allocate memory for the array of strings
    char** result = (char**)malloc(*count * sizeof(char*));
    if (result == NULL) {
        return NULL;
    }

    // Initialize variables for splitting
    const char* start = str;
    int index = 0;

    // Split the string based on the delimiter
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delimiter || str[i + 1] == '\0') {
            int length = (str[i + 1] == '\0') ? (i + 1) : (i);
            int size = length - (start - str);
            
            // Allocate memory for the individual string
            result[index] = (char*)malloc((size + 1) * sizeof(char));
            if (result[index] == NULL) {
                // Free previously allocated memory
                for (int j = 0; j < index; j++) {
                    free(result[j]);
                }
                free(result);
                return NULL;
            }

            // Copy the substring into the individual string
            strncpy(result[index], start, size);
            result[index][size] = '\0';

            // Update start position for the next substring
            start = str + i + 1;
            index++;
        }
    }

    return result;
}

int main() {
    const char* str = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    
    int count = 0;
    char** result = str_split(str, ',', &count);
    
    if (result != NULL) {
        for (int i = 0; i < count; i++) {
            printf("%s\n", result[i]);
            free(result[i]);
        }
        free(result);
    } else {
        printf("Failed to split the string.\n");
    }

    return 0;
}
