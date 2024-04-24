#include <stdio.h>    
#include <stdlib.h>
#include <string.h>

void load(char ***array_ptr, int *index) {
    int riadok;
    size_t len = 0;
    char *buffer = NULL;

    printf("Slova:\n");
    while ((riadok = getline(&buffer, &len, stdin)) != -1) {
        if (riadok == 1) {
            break;  
        }

        *array_ptr = (char**) realloc(*array_ptr, (*index + 1) * sizeof(char*));
        (*array_ptr)[*index] = (char*) malloc((riadok + 1) * sizeof(char));
        strcpy((*array_ptr)[*index], buffer);

        *index = *index + 1;
    }

    free(buffer);
}

int main() {
    int index = 0;
    int i;
    char **array = NULL;

    load(&array, &index);

    for (i = 0; i < index; i++) {
        printf("%s", array[i]);
        free(array[i]);
    }

    free(array);

    return 0;  
}
