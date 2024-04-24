#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* global; // Define global as a pointer to char (string)

int main() {
    printf("Please Enter Text: \n");

    // Allocate memory for global to store the input text
    global = (char*)malloc(100*sizeof(char)); // Assuming a maximum of 100 characters

    if (global == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    scanf(" %99[^\n]", global); // Read a line of text up to 99 characters (leaving space for NULL terminator)

    printf("%s\n", global); // Print the entered text

    // Free the allocated memory
    free(global);

    return 0;
}
