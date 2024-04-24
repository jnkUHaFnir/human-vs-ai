#include <stdio.h>
#include <stdlib.h>

typedef struct myStruct {
    int size;
    char *name;
    struct myStruct **array;
} myStruct;

int main() {
    int array_size = 5;

    // Allocate memory for the main struct
    myStruct *a = malloc(sizeof(myStruct));
    a->size = array_size;
    a->name = "Main Struct";

    // Allocate memory for the array of struct pointers
    a->array = malloc(array_size * sizeof(struct myStruct *));

    // Allocate memory for each struct in the array
    for (int i = 0; i < array_size; i++) {
        a->array[i] = malloc(sizeof(struct myStruct));
        a->array[i]->size = 0; // Set size to 0 for demonstration
        a->array[i]->name = "Array Struct";
    }

    // Accessing elements in the array
    for (int i = 0; i < array_size; i++) {
        printf("Array %d - Size: %d, Name: %s\n", i, a->array[i]->size, a->array[i]->name);
    }

    // Free memory
    for (int i = 0; i < array_size; i++) {
        free(a->array[i]);
    }
    free(a->array);
    free(a);

    return 0;
}
