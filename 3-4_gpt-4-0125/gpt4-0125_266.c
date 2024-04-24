#include <stdio.h>
#include <stdlib.h> // Needed for malloc and free

int main() {
    int i;
    char** t;
    int numStrings = 16; // Number of strings
    int stringSize = 16; // Maximum length of each string

    // Allocate memory for the array of char pointers
    t = (char**)malloc(numStrings * sizeof(char*));
    if (t == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation failed
    }

    // Allocate memory for each string and initialize
    for (i = 0; i < numStrings; i++) {
        t[i] = (char*)malloc(stringSize * sizeof(char));
        if (t[i] == NULL) {
            printf("Memory allocation for string %d failed\n", i);
            return 1; // Exit if memory allocation failed
        }
        
        // Example initialization (optional)
        snprintf(t[i], stringSize, "String %d", i); // Safer than strcpy
    }

    // Example usage: Print allocated strings
    for (i = 0; i < numStrings; i++) {
        printf("%s\n", t[i]);
    }

    // Free allocated memory for each string
    for (i = 0; i < numStrings; i++) {
        free(t[i]);
    }

    // Free the array of pointers
    free(t);

    return 0;
}
