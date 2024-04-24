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

        *array = (char**) realloc(*array, (*index + 1) * sizeof(char*));
        (*array)[*index] = (char*) malloc((riadok + 1) * sizeof(char));
        strcpy((*array)[*index], buffer);

        *index = *index + 1;
    }
}

int main() {
    int index = 0;
    int i;
    char **array = NULL;

    load(&array, &index);

    for (i = 0; i < index; i++) {
        printf("%s", array[i]);
        free(array[i]); // Free memory allocated for each line
    }
    
    free(array); // Free memory allocated for the array
    
    return 0;  
}
