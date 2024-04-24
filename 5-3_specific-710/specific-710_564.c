#include <stdio.h>
#include <stdlib.h> // for malloc

int main()
{
    char *name = NULL;
    int bufferSize = 100;

    printf("Your name: \n");

    name = (char *)malloc(bufferSize * sizeof(char));  // Allocate memory for the name

    if (name == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    if (fgets(name, bufferSize, stdin) != NULL) {
        printf("Name: %s\n", name);
    } else {
        printf("Error reading input.\n");
    }

    free(name);  // Free dynamically allocated memory

    return 0;
}
