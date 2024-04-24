#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char *directions[3];
    
    // Allocate memory for each string
    for (int i = 0; i < 3; i++) {
        directions[i] = (char*)malloc(MAX_LENGTH * sizeof(char));
        if (directions[i] == NULL) {
            // Handle allocation failure
            perror("Memory allocation failed");
            exit(1);
        }
    }
    
    // Read input strings
    for (int i = 0; i < 3; i++) {
        if (scanf("%99s", directions[i]) != 1) {
            // Handle input error
            perror("Error reading input");
            exit(1);
        }
    }
    
    // Display strings
    for (int i = 0; i < 3; i++) {
        printf("%s\n", directions[i]);
    }
    
    // Free allocated memory
    for (int i = 0; i < 3; i++) {
        free(directions[i]);
    }
    
    return 0;
}
