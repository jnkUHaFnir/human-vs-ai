#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *name = malloc(256 + 1); // Allocate memory for 256 characters plus 1 for the null terminator
    
    if (name == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("What is your name? ");
    fgets(name, 256, stdin); // Read up to 256 characters from stdin, including spaces

    // Remove the newline character at the end of the name if it exists
    name[strcspn(name, "\n")] = '\0';

    printf("Hello %s. Nice to meet you.\n", name);

    free(name); // Free the allocated memory

    return 0;
}
