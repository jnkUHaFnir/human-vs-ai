#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void load(char ***pArray, int *index) {
    int riadok;
    size_t len = 0;
    char *buffer = NULL;
    char **array = *pArray;  // Dereference the pointer to get the actual array

    printf("Slova:\n");
    while ((riadok = getline(&buffer, &len, stdin)) != -1) {
        if (riadok == 1) {
            break;
        }

        array = (char **)realloc(array, (*index + 1) * sizeof(char *));
        array[*index] = (char *)malloc((riadok + 1) * sizeof(char));
        strncpy(array[*index], buffer, riadok);  // Use strncpy to prevent buffer overflow
        array[*index][riadok] = '\0';  // Null-terminate the string

        *index = *index + 1;
    }

    *pArray = array;  // Update the pointer in the main function
}

int main() {
    int index = 0;
    int i;
    char **array = NULL;

    load(&array, &index);

    for (i = 0; i < index; i++) {
        printf("%s", array[i]);
        free(array[i]);  // Free the memory allocated for each string
    }

    free(array);  // Free the memory allocated for the array

    return 0;
}
