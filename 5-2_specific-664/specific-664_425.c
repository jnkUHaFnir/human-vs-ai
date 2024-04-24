#include <stdio.h>
#include <stdlib.h>

int main() {
    char *name = malloc(256); // Allocate memory for 256 characters

    printf("What is your name? ");
    fgets(name, 256, stdin); // Read input including spaces

    // Remove the newline character from the input
    size_t length = strlen(name);
    if (name[length - 1] == '\n') {
        name[length - 1] = '\0';
    }

    printf("Hello %s. Nice to meet you.\n", name);

    free(name); // Free the allocated memory

    return 0;
}
