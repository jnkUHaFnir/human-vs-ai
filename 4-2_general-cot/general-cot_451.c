#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* global;

int main() {
    global = (char*)malloc(100 * sizeof(char)); // Allocate memory for the string

    if (global == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Please Enter Text: \n");
    fgets(global, 100, stdin); // Read a line of text including spaces

    // Remove the newline character from the input
    global[strcspn(global, "\n")] = 0;

    printf("%s\n", global); // Print the stored sentence

    free(global); // Free allocated memory
    return 0;
}
