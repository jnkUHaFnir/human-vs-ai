#include <stdio.h>
#include <stdlib.h>

// Function to dynamically read and store a string 
// Returns the length of the string
int read_string(char **output) {
    // Allocate initial block of memory (e.g., for 1 character + null terminator)
    int capacity = 2;  // starting capacity
    *output = malloc(capacity * sizeof(char));
    if (*output == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    int counter = 0;
    char input;
    while ((input = getchar()) != '\n' && input != EOF) {   // read until detect '\n' or EOF
        (*output)[counter++] = input;  // store the character

        // Check if we need to expand the buffer
        if (counter + 1 == capacity) {  // +1 for the null terminator
            capacity *= 2;  // double the capacity
            *output = realloc(*output, capacity * sizeof(char));
            if (*output == NULL) {
                perror("Failed to reallocate memory");
                exit(EXIT_FAILURE);
            }
        }
    }
    (*output)[counter] = '\0';  // null-terminate the string

    // Optionally, shrink the buffer to the exact size needed
    char *shrunk_output = realloc(*output, (counter + 1) * sizeof(char));
    if (shrunk_output != NULL) {
        *output = shrunk_output;  // only use shrunk buffer if realloc succeeded
    }

    return counter;  // returning the length not including the null terminator
}

int main() {
    char *myString;
    printf("Enter a string: ");
    int length = read_string(&myString);
    printf("You entered: %s\n", myString);
    printf("Length of string: %d\n", length);
    // Remember to free the memory
    free(myString);
    return 0;
}
