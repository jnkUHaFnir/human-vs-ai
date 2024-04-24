#include <stdio.h>
#include <stdlib.h> // include header for malloc

typedef struct {
    int* data;
    unsigned int len;
} intarr_t;

intarr_t* intarr_create(unsigned int len) { 
    // Allocate memory for a new intarr_t
    intarr_t* new_intarr = (intarr_t *) malloc(sizeof(intarr_t));

    if(new_intarr != NULL) {
        // Allocate memory for the data field in intarr_t
        new_intarr->data = (int *) malloc(len * sizeof(int));

        if (new_intarr->data != NULL) {
            // Set the length of intarr_t
            new_intarr->len = len;
            return new_intarr;
        } else {
            // If allocation for data fails, free the allocated memory for new_intarr
            free(new_intarr);
        }
    }
    // If allocation failed return NULL
    return NULL;
}

int main() {
    unsigned int len = 15;
    intarr_t* h = intarr_create(len);
    printf("%p\n", (void *)h); // Print the address pointed by h
    if (h != NULL) {
        // Free the allocated memory before terminating the program
        free(h->data);
        free(h);
    }
    return 0;
}
