#include <stdio.h>
#include <stdlib.h>

int main() {
    char *name = malloc(256 * sizeof(char)); 

    printf("What is your name? ");
    scanf(" %[^\n]", name);

    printf("Hello %s. Nice to meet you.\n", name);

    free(name); // Don't forget to free the allocated memory

    return 0;
}
