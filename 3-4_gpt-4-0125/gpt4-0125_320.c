#include <stdio.h>
#include <stdlib.h> // For malloc and free

typedef struct {
    int* data;
    unsigned int len;
} intarr_t;

intarr_t* intarr_create(unsigned int len) { 
    // Allocate memory for struct intarr_t itself
    intarr_t* array = (intarr_t*) malloc(sizeof(intarr_t));
    if(array == NULL) {
        return NULL; // Allocation failed
    }

    // Allocate memory for data array within struct
    array->data = (int*) malloc(len * sizeof(int));
    if(array->data == NULL) {
        free(array); // Free struct memory if data array allocation fails
        return NULL;
    }

    // Successful allocation
    array->len = len;
    return array;
}

int main() {
    unsigned int len = 15; // Should be unsigned to match the function parameter
    intarr_t* h = intarr_create(len);
    if (h != NULL) {
        printf("Array created successfully with length %u\n", h->len);
        // Remember to free allocated memory to avoid memory leaks
        free(h->data);
        free(h); 
    } else {
        printf("Failed to create array.\n");
    }
    return 0;
}
