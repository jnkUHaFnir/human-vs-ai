#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** str_split(const char* str, char delimiter) {
    // Allocate memory for a temporary copy of the string
    char* temp = strdup(str);
    
    // Count the number of delimiters in the string
    int count = 0;
    char* token = strtok(temp, &delimiter);
    while (token != NULL) {
        count++;
        token = strtok(NULL, &delimiter);
    }
    
    // Allocate memory for the result array
    char** result = malloc((count + 1) * sizeof(char*));
    if (result == NULL) {
        free(temp);
        return NULL;
    }
    
    // Split the string and store each token in the result array
    count = 0;
    token = strtok(strdup(str), &delimiter);
    while (token != NULL) {
        result[count] = strdup(token);
        count++;
        token = strtok(NULL, &delimiter);
    }
    result[count] = NULL; // Set the last element to NULL
  
    // Free the temporary copy of the string
    free(temp);
    
    return result;
}

int main() {
    char* str = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    char** split_result = str_split(str, ',');
    
    if (split_result != NULL) {
        // Print each token in the result array
        for (int i = 0; split_result[i] != NULL; i++) {
            printf("%s\n", split_result[i]);
        }
        
        // Free the result array
        for (int i = 0; split_result[i] != NULL; i++) {
            free(split_result[i]);
        }
        free(split_result);
    }
    
    return 0;
}
