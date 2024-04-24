#include <stdio.h>
#include <stdlib.h> // Include necessary header for malloc

typedef struct {
    int* data;
    unsigned int len;
} intarr_t;

intarr_t* intarr_create(unsigned int len) {
    intarr_t* intarr = malloc(sizeof(intarr_t)); // Allocate memory for intarr_t struct
    if(intarr != NULL) {
        intarr->data = malloc(sizeof(int) * len); // Allocate memory for int* data array
        if(intarr->data != NULL) {
            intarr->len = len; // Assign len to the intarr_t struct
            return intarr;
        } else {
            free(intarr); // Free the intarr_t struct if memory allocation for data fails
            return NULL;
        }
    } else {
        return NULL;
    }
}

int main() {
    unsigned int len = 15; // Use unsigned int instead of int for len
    intarr_t* h = intarr_create(len); // Store the returned pointer in intarr_t*
    if(h != NULL) {
        printf("Memory allocation successful\n");
    } else {
        printf("Memory allocation failed\n");
    }
    return 0;
}
