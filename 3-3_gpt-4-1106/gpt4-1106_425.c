#include <stdio.h>
#include <stdlib.h>

int main() {
    char *name = malloc(256 * sizeof(char)); // 256 characters buffer

    if (name == NULL) {
        // Handle the memory allocation error
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("What is your name? ");
    // Read a line of text, including spaces, up to 255 characters
    fgets(name, 256, stdin);

    // fgets includes the newline character in the buffer. Remove it if present.
    name[strcspn(name, "\n")] = '\0';

    printf("Hello %s. Nice to meet you.\n", name);

    free(name); // Remember to free the memory once you're done
    return 0;
}
