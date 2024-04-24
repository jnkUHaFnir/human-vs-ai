#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct myStruct;
struct myStruct {
    int size;
    char *name;
    myStruct *array[]; // Flexible array member
};

int main() {
    int num_elements = 5;

    // Allocate space for the struct and its flexible array member
    myStruct *a = malloc(sizeof(myStruct) + sizeof(myStruct *) * num_elements);
    if (!a) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    a->size = num_elements;
    a->name = "Sample";

    // Allocate space for each element in the array
    for (int i = 0; i < num_elements; i++) {
        a->array[i] = malloc(sizeof(myStruct));
        if (!a->array[i]) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        a->array[i]->size = 0;
        a->array[i]->name = "Child";
    }

    // Use the struct data
    printf("Parent name: %s\n", a->name);
    for (int i = 0; i < a->size; i++) {
        printf("Child %d name: %s\n", i, a->array[i]->name);
    }

    // Free memory
    for (int i = 0; i < num_elements; i++) {
        free(a->array[i]);
    }
    free(a);

    return EXIT_SUCCESS;
}
