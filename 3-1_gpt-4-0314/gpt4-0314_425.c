#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *name = malloc(sizeof(char) * 256);

    printf("What is your name? ");
    fgets(name, 256, stdin);

    // Remove the newline character at the end of the name
    name[strcspn(name, "\n")] = 0;

    printf("Hello %s. Nice to meet you.\n", name);

    free(name);
    return 0;
}
