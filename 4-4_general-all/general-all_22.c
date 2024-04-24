#include <stdlib.h>
#include <stdio.h>

int main() {
    int x = 5; // Number of strings
    char **array_of_strings;
    
    // Allocate memory for array of strings
    array_of_strings = (char **)malloc(x * sizeof(char *));
    
    if (array_of_strings == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    for (int i = 0; i < x; i++) {
        array_of_strings[i] = (char *)malloc(51 * sizeof(char)); // 50 characters + 1 for null terminator
        
        if (array_of_strings[i] == NULL) {
            printf("Memory allocation failed for string %d.\n", i);
            return 1;
        }
    }
    
    // Use the array_of_strings as needed
    
    // Free allocated memory
    for (int i = 0; i < x; i++) {
        free(array_of_strings[i]);
    }
    free(array_of_strings);
    
    return 0;
}
