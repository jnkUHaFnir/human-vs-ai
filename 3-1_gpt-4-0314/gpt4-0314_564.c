#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[100];
    char *name;
    printf("Your name: \n");
    fgets(buffer, sizeof(buffer), stdin);

    // Allocate memory for name and copy the input string to name
    name = malloc(strlen(buffer) + 1); // +1 for the null-terminator
    strcpy(name, buffer);

    // Remove newline character
    if (name[strlen(name) - 1] == '\n')
    {
        name[strlen(name) - 1] = '\0';
    }

    printf("Name: %s  \n", name);

    // Free the allocated memory
    if (name != NULL)
    {
        free(name);
    }
    return 0;
}
