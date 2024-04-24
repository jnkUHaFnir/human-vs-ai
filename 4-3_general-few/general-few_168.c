#include <stdio.h>
#include <stdlib.h>

typedef struct myStruct {
    int size;
    char *name;
    struct myStruct (*array)[];
} myStruct;

int main() {
    myStruct *a;

    // Allocate memory for myStruct including the array of myStruct elements
    a = malloc(sizeof(myStruct) + sizeof(myStruct*) * 5);

    // Now we can assign the name and size
    a->size = 5;
    a->name = "Example";

    // Access the array elements and assign values
    for (int i = 0; i < a->size; i++) {
        // Allocate memory for each element in the array
        a->array[i] = malloc(sizeof(myStruct));

        // Assign some values for each element (e.g., setting name to "Element i")
        a->array[i]->name = "Element";
        a->array[i]->size = i+1;

        printf("Array Element %d - Name: %s, Size: %d\n", i, a->array[i]->name, a->array[i]->size);

        // Remember to free memory for each element later
        // free(a->array[i]);
    }

    // Free the main struct when done
    free(a);

    return 0;
}
