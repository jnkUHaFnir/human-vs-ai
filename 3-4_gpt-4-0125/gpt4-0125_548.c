#include <stdio.h>
#include <stdlib.h> // For malloc

int main() {
    char *directions[3];
    int i;
    // Allocate memory for each string
    for(i = 0; i < 3; i++) {
        directions[i] = malloc(100 * sizeof(char)); // Allocate space for 100 chars
        if (directions[i] == NULL) {
            // If malloc fails, exit the program
            fprintf(stderr, "Failed to allocate memory\n");
            exit(EXIT_FAILURE);
        }
    }
    
    // Read strings into allocated memory
    printf("Enter 3 directions:\n");
    for(i = 0; i < 3; i++) {
        // It's safer to use fgets to avoid buffer overflow, but need to strip the newline character
        if(fgets(directions[i], 100, stdin) != NULL){
            size_t ln = strlen(directions[i]) - 1; // Get length of string
            if (directions[i][ln] == '\n') 
                directions[i][ln] = '\0'; // Replace newline with null terminator
        }
    }
    
    // Print the strings
    for(i = 0; i < 3; i++) {
        printf("%s\n", directions[i]);
    }
    
    // Free the allocated memory
    for(i = 0; i < 3; i++) {
        free(directions[i]);
    }

    return 0;
}
