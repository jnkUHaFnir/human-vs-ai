char **array_of_strings = (char **)malloc(x * sizeof(char *));
if (array_of_strings == NULL) {
    // Handle memory allocation failure (e.g., by exiting the function/program).
}
for (int i = 0; i < x; ++i) {
    array_of_strings[i] = (char *)malloc(50 * sizeof(char));
    if (array_of_strings[i] == NULL) {
        // Handle memory allocation failure (e.g., freeing already allocated memory and exiting the function/program).
    }
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x; // Number of strings.
    printf("Enter the number of strings: ");
    scanf("%d", &x);
    
    char **array_of_strings = (char **)malloc(x * sizeof(char *));
    if (array_of_strings == NULL) {
        // Handle memory allocation failure.
        return 1;
    }
    
    for (int i = 0; i < x; ++i) {
        array_of_strings[i] = (char *)malloc(50 * sizeof(char));
        if (array_of_strings[i] == NULL) {
            // Handle memory allocation failure.
            // Free already allocated memory.
            for (int j = 0; j < i; ++j) {
                free(array_of_strings[j]);
            }
            free(array_of_strings);
            return 1;
        }
    }
    
    // Now you have an array of x strings, each capable of holding 49 characters plus the null terminator.
    
    // Don't forget to free the memory once you're done with it!
    for (int i = 0; i < x; ++i) {
        free(array_of_strings[i]);
    }
    free(array_of_strings);
    
    return 0;
}
