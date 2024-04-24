#include <stdio.h>
#include <stdlib.h>

int main() {
    char *name = malloc(256 * sizeof(char)); // Allocate memory for 255 characters and room for the null terminator
    
    printf("What is your name? ");
    scanf(" %[^\n]", name); // Note the space before %[^\n] to consume any leading whitespace

    printf("Hello %s. Nice to meet you.\n", name);

    free(name); // Free the allocated memory
    return 0;
}
