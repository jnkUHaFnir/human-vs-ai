#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *name = NULL;
    size_t len = 0;

    printf("Your name: \n");
    getline(&name, &len, stdin);

    // Remove the newline character at the end of input
    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }

    printf("Name: %s\n", name);

    free(name);

    return 0;
}
