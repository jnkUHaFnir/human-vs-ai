#include <stdio.h>
#include <stdlib.h>

int main() {
    int x; // Number of strings
    printf("Enter the number of strings: ");
    scanf("%d", &x);
    
    // Allocate memory for an array of x pointers to char
    char **strArray = (char**) malloc(x * sizeof(char*));
    if (strArray == NULL) {
        // Memory allocation failed
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Allocate memory for each string
    for (int i = 0; i < x; i++) {
        strArray[i] = (char*) malloc(50 * sizeof(char));
        if (strArray[i] == NULL) {
            // Memory allocation failed for strArray[i], need to handle freeing previous allocations and return.
            printf("Memory allocation failed for string %d\n", i);
            
            // Free previously allocated memory before exiting
            for (int j = 0; j < i; j++) {
                free(strArray[j]);
            }
            free(strArray);
            return 1;
        }
    }
    
    // Now strArray is an array of 'x' strings, each capable of holding up to 49 characters + null character

    // Example: Assigning values to each string
    for (int i = 0; i < x; i++) {
        snprintf(strArray[i], 50, "String %d", i); // This is just an example of how to assign values
    }
    
    // Example: Print the strings
    for (int i = 0; i < x; i++) {
        printf("%s\n", strArray[i]);
    }
    
    // Free memory after use
    for (int i = 0; i < x; i++) {
        free(strArray[i]); // Release each string
    }
    free(strArray); // Release the array of pointers
    
    return 0;
}
