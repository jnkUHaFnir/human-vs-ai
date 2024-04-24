#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int numStrings = 100; // Number of strings
    int stringLength = 16; // Maximum length of each string

    // Allocate an array of string pointers
    char **t = (char **)malloc(numStrings * sizeof(char*));
    if (t == NULL) {
        perror("Memory allocation for string pointers failed");
        return 1;
    }

    // Allocate memory for each string
    for (i = 0; i < numStrings; i++) {
        t[i] = (char *)malloc(stringLength * sizeof(char));
        if (t[i] == NULL) {
            perror("Memory allocation for string failed");
            // Cleanup already allocated strings
            for (int j = 0; j < i; j++) {
                free(t[j]);
            }
            free(t);
            return 1;
        }
        // Initialize the string if you want (e.g., to an empty string)
        t[i][0] = '\0';
    }

    // Here you can use the allocated strings
    // ...

    // Clean up dynamically allocated memory
    for (i = 0; i < numStrings; i++) {
        free(t[i]); // Free each string
    }
    free(t); // Free the array of string pointers

    return 0;
}
