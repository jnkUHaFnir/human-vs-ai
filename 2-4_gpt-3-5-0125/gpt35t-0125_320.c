#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    unsigned int len;
} intarr_t;

intarr_t* intarr_create(unsigned int len) { 
    intarr_t* intarr = malloc(sizeof(intarr_t)); // Allocate memory for intarr_t struct
    if(intarr != NULL) {
        intarr->data = malloc(len * sizeof(int)); // Allocate memory for int array
        if(intarr->data == NULL) {
            free(intarr);
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
    intarr_t* h = intarr_create(len); // Corrected data type and return type
    if(h != NULL) {
        printf("%p\n", (void*) h); // Print memory address of intarr_t struct
    } else {
        printf("Unable to create intarr\n");
    }
    return 0;
}
