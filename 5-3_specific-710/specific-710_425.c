#include <stdio.h>
#include <stdlib.h>

int main() {
    char *name = (char *)malloc(256 * sizeof(char)); // allocate memory for 255 characters plus null-terminator

    if (name == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    printf("What is your name? ");
    fgets(name, 256, stdin); // read a line of input, including spaces

    printf("Hello %s. Nice to meet you.\n", name);

    free(name); // free the allocated memory

    return 0;
}
