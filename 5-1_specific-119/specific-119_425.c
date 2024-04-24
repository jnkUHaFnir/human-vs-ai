#include <stdio.h>
#include <stdlib.h>

int main() {
    char *name = malloc(256 * sizeof(char)); // Allocate memory for 255 characters plus null terminator

    printf("What is your name? ");
    fgets(name, 256, stdin); // read input including spaces

    printf("Hello %s. Nice to meet you.\n", name);

    free(name); // free dynamically allocated memory

    return 0;
}
