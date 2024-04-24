#include <stdio.h>
#include <stdlib.h> // Need to include stdlib for the malloc and free functions

typedef struct {
    int* data;
    unsigned int len;
} intarr_t;

intarr_t* intarr_create(unsigned int len) { 
    // Allocate memory for the structure itself
    intarr_t* new_array = (intarr_t*) malloc(sizeof(intarr_t));
    if (new_array == NULL) {
        // Allocation failed for the structure
        return NULL;
    }

    // Allocate memory for the data array within the structure
    new_array->data = (int*) malloc(len * sizeof(int));
    if (new_array->data == NULL) {
        // Allocation failed for the data array, need to free the previously allocated memory
        free(new_array);
        return NULL;
    }

    // Assign the length to the len field of the structure
    new_array->len = len;
    return new_array;
}

int main() {
    unsigned int len = 15;
    intarr_t* h = intarr_create(len);

    if(h != NULL) {
        printf("Array created with length %d\n", h->len);

        // Perform operations on the array...

        // Don't forget to free the memory once you're done with the array
        free(h->data); // Free the data array
        free(h);       // Free the structure itself
    } else {
        printf("Failed to create array\n");
    }

    return 0;
}
