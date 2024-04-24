#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of occurrences of a character in a string
int count_char(char *str, char delimiter) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == delimiter) {
            count++;
        }
    }
    return count;
}

// Function to split a string into an array using a delimiter
char **str_split(char *str, char delimiter) {
    int num_substrings = count_char(str, delimiter) + 1;
    char **result = malloc((num_substrings + 1) * sizeof(char *));
    int current_index = 0;
    char *token;

    token = strtok(str, &delimiter);
    while (token != NULL) {
        result[current_index] = malloc(strlen(token) + 1);
        strcpy(result[current_index], token);
        current_index++;
        token = strtok(NULL, &delimiter);
    }

    result[current_index] = NULL;
    return result;
}

int main() {
    char *str = strdup("JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC");
    char **split_strings = str_split(str, ',');

    for (int i = 0; split_strings[i] != NULL; i++) {
        printf("split_strings[%d] = %s\n", i, split_strings[i]);
    }

    // Free the allocated memory
    for (int i = 0; split_strings[i] != NULL; i++) {
        free(split_strings[i]);
    }
    free(split_strings);
    free(str);
    
    return 0;
}
