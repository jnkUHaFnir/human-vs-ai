#include <stdio.h>
#include <stdlib.h>

typedef struct myStruct {
    int size;
    char *name;
    struct myStruct **array;
} myStruct;

int main() {
    // Allocate memory for the main struct
    myStruct *a = malloc(sizeof(myStruct));

    // Set the size and name for the main struct
    a->size = 5;
    a->name = "Main";

    // Allocate memory for the array of pointers to myStruct
    a->array = malloc(sizeof(struct myStruct *) * a->size);

    // Allocate memory for each individual myStruct in the array
    for (int i = 0; i < a->size; i++) {
        a->array[i] = malloc(sizeof(myStruct));
        a->array[i]->size = i;  // Just an example of setting values
        a->array[i]->name = "Sub";
        a->array[i]->array = NULL; // If you have a nested array, allocate memory here too
    }

    // Accessing elements in the array
    for (int i = 0; i < a->size; i++) {
        printf("Element %d: %s\n", i, a->array[i]->name);
    }

    // Free the allocated memory
    for (int i = 0; i < a->size; i++) {
        free(a->array[i]);
    }
    free(a->array);
    free(a);

    return 0;
}
