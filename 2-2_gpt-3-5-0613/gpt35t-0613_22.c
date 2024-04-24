#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 5; // Assuming you want to allocate memory for 5 strings
    
    // Allocate memory for the array of strings
    char** array = malloc(x * sizeof(char*));
    
    // Allocate memory for each string
    for (int i = 0; i < x; i++) {
        array[i] = malloc(50 * sizeof(char));
    }
    
    // Access and use the strings
    for (int i = 0; i < x; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", array[i]);
    }
    
    // Free the allocated memory
    for (int i = 0; i < x; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
