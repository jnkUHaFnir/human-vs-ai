#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char* input;
    char temp;
    size_t length;
    int i = 0, j = 0;

    // Allocate buffer for initial input (e.g., 256 characters)
    input = (char*)malloc(256 * sizeof(char));
    if (input == NULL) { // Always check if malloc succeeded
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter a string: ");
    fgets(input, 256, stdin); // Use fgets to read string including whitespaces
    length = strlen(input);

    // Remove newline character if it exists
    if(input[length - 1] == '\n'){
        input[length - 1] = '\0';
        length--; // Update length to reflect removal of newline character
    }

    // Optionally resize memory allocation to exactly match the input length + 1 for '\0'
    input = (char*)realloc(input, (length + 1) * sizeof(char));
    if (input == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        return 1;
    }

    j = length - 1;

    while (i < j) {
        temp = input[j];
        input[j] = input[i];
        input[i] = temp;
        i++;
        j--;
    }

    printf("Reversed = %s\n", input);

    free(input); // Do not forget to free dynamically allocated memory
    return 0;
}
