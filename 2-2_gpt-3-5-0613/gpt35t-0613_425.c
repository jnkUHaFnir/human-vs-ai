#include <stdio.h>
#include <stdlib.h>

int main() {
    char *name = malloc(sizeof(char) * 256); 

    printf("What is your name? ");
    scanf(" %[^\n]s", name);

    printf("Hello %s. Nice to meet you.\n", name);

    free(name);
    return 0;
}
