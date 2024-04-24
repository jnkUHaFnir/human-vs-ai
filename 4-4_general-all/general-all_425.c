#include <stdio.h>
#include <stdlib.h>

int main() {
    char *name = malloc(256); // Allocate memory for 255 characters plus 1 for the null terminator
    
    if (name == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("What is your name? ");
    fgets(name, 256, stdin); // Read up to 255 characters from stdin

    // Remove the newline character at the end (if present)
    size_t len = strlen(name);
    if (len > 0 && name[len-1] == '\n') {
        name[len-1] = '\0';
    }

    printf("Hello %s. Nice to meet you.\n", name);

    // Free dynamically allocated memory
    free(name);

    return 0;
}
