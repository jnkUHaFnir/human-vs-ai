#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void load(char ***array, int *index) {

    int riadok;
    size_t len = 0;
    char *buffer = NULL;

    printf("Slova:\n");
    while ((riadok = getline(&buffer, &len, stdin)) != -1) {

        if (riadok == 1) {
            break;
        }

        *array = (char **)realloc(*array, (*index + 1) * sizeof(char *));
        (*array)[*index] = (char *)malloc((riadok + 1) * sizeof(char)); // Fix sizeof(char)
        strcpy((*array)[*index], buffer);

        *index = *index + 1;
    }

    free(buffer); // Free allocated buffer
}

int main()
{

    int index = 0;
    int i;
    char **array = NULL;

    load(&array, &index);

    for (i = 0; i < index; i++)
        printf("%s", array[i]);

    // Free allocated memory
    for (i = 0; i < index; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
