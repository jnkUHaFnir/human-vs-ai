#include <stdio.h>
#include <stdlib.h> // Include necessary header for malloc

typedef struct {
    int* data;
    unsigned int len;
} intarr_t;

intarr_t* intarr_create(unsigned int len) { 
    intarr_t* arr = malloc(sizeof(intarr_t));  // Allocate memory for the intarr_t struct

    if(arr != NULL) {
        arr->data = malloc(len * sizeof(int));  // Allocate memory for the data array
        if (arr->data == NULL) {
            free(arr); // Free the allocated struct if data allocation fails
            return NULL;
        }
        arr->len = len; // Set the length in the intarr_t struct
        return arr;
    } else {
        return NULL; // Return NULL if allocation for the struct fails
    }
}

int main() {
    unsigned int len = 15; // Use unsigned int for array length
    intarr_t* arr = intarr_create(len);

    if (arr != NULL) {
        printf("Array created successfully with length: %u\n", arr->len);
    } else {
        printf("Failed to create array\n");
    }

    return 0;
}
