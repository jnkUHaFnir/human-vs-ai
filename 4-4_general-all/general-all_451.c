#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* global; // Correct variable type - pointer to char

int main() {
    global = (char*)malloc(100 * sizeof(char)); // Allocating memory for the global variable
    if (global == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Please Enter Text: \n");
    scanf(" %99[^\n]", global); // Read input as a string (up to 99 characters) without spaces
    getchar(); // Consume the newline character left in the input buffer

    printf("%s\n", global); // Print out the stored string

    free(global); // Free the allocated memory

    return 0;
}
