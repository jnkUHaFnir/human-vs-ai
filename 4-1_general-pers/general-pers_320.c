#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    unsigned int len;
} intarr_t;

intarr_t* intarr_create(unsigned int len) {
    intarr_t* intarr = malloc(sizeof(intarr_t)); // Allocate memory for intarr_t struct
    if(intarr != NULL) {
        intarr->data = malloc(len * sizeof(int)); // Allocate memory for int data
        if(intarr->data == NULL) {
            free(intarr); // Free intarr_t struct memory in case of data allocation failure
            return NULL;
        }
        intarr->len = len;
        return intarr;
    } else {
        return NULL;
    }
}

int main() {
    unsigned int len = 15;
    intarr_t* int_array = intarr_create(len);
    if(int_array != NULL) {
        printf("Array created successfully with length: %u\n", int_array->len);
        // Do some operations with the int array here
        free(int_array->data); // Free int array memory
        free(int_array); // Free intarr_t struct memory
    } else {
        printf("Failed to create array\n");
    }
    return 0;
}
