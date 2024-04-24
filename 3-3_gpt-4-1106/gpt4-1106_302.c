#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void load(char ***array, int *index) {
    ssize_t riadok;
    size_t len = 0;
    char *buffer = NULL;

    printf("Slova:\n");
    while ((riadok = getline(&buffer, &len, stdin)) != -1) {
        if (riadok == 1) {
            break;
        }

        *array = (char **)realloc(*array, (*index + 1) * sizeof(char *));
        if (!(*array)) {
            perror("Failed to reallocate memory");
            exit(EXIT_FAILURE);
        }

        (*array)[*index] = (char *)malloc((riadok + 1) * sizeof(char));
        if (!((*array)[*index])) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        strcpy((*array)[*index], buffer);

        *index = *index + 1;
    }

    free(buffer); // Don't forget to free the temporary buffer
}

int main() {
    int index = 0;
    int i;
    char **array = NULL;

    load(&array, &index);

    for (i = 0; i < index; i++) {
        printf("%s", array[i]);
        free(array[i]); // Free each line after printing
    }

    free(array); // Free the main array after all lines are printed

    return 0;
}
