#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char *input = NULL;
    size_t input_length = 0;

    printf("Enter a string: ");
    
    // Read user input
    if (fgets(NULL, &input_length, stdin) == NULL) {
        // Handle error
        fprintf(stderr, "Error reading input\n");
        return 1;
    }
    
    // Remove newline character if present
    input_length = strlen(input);
    if (input[input_length - 1] == '\n') {
        input[input_length - 1] = '\0';
    }
    
    // Dynamically allocate memory for the input string
    input = (char *)malloc(input_length * sizeof(char));
    if (input == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Copy input to dynamically allocated memory
    strncpy(input, input, input_length);

    // Use the input as needed
    
    // Don't forget to free the dynamically allocated memory
    free(input);
    
    return 0;
}
