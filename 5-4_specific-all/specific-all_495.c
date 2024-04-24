#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** str_split(const char* str, char delimiter) {
    int i, j = 0;
    int count = 1;
    int len = strlen(str);
    
    for (i = 0; i < len; i++) {
        if (str[i] == delimiter) {
            count++;
        }
    }
    
    char **result = (char **)malloc(count * sizeof(char *));
    if (result == NULL) {
        return NULL;
    }
    
    int start = 0;
    for (i = 0; i < len; i++) {
        if (str[i] == delimiter) {
            int length = i - start;
            result[j] = (char *)malloc((length + 1) * sizeof(char));
            if (result[j] == NULL) {
                // Clean up memory if allocation fails
                for (int k = 0; k < j; k++) {
                    free(result[k]);
                }
                free(result);
                return NULL;
            }
            
            strncpy(result[j], str + start, length);
            result[j][length] = '\0';
            j++;
            start = i + 1;
        }
    }
    
    // Copy the last part of the string
    int length = i - start;
    result[j] = (char *)malloc((length + 1) * sizeof(char));
    if (result[j] == NULL) {
        // Clean up memory if allocation fails
        for (int k = 0; k < j; k++) {
            free(result[k]);
        }
        free(result);
        return NULL;
    }
    
    strncpy(result[j], str + start, length);
    result[j][length] = '\0';

    return result;
}

int main() {
    char *str = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    char **tokens = str_split(str, ',');

    if (tokens == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; tokens[i] != NULL; i++) {
        printf("%s\n", tokens[i]);
        free(tokens[i]); // Free memory for each token
    }

    free(tokens); // Free memory for the array of tokens
    
    return 0;
}
