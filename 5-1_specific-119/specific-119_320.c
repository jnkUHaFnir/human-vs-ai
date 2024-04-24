#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    unsigned int len;
} intarr_t;

intarr_t* intarr_create(unsigned int len) { 
    intarr_t* my_intarr = (intarr_t*)malloc(sizeof(intarr_t));
    if (my_intarr == NULL) {
        return NULL; // Allocation failed
    }
    
    my_intarr->len = len;
    my_intarr->data = (int*)malloc(sizeof(int) * len);
    
    if (my_intarr->data == NULL) {
        free(my_intarr);
        return NULL; // Allocation failed
    }

    return my_intarr;
}

int main() {
    int len = 15;
    intarr_t* h = intarr_create(len);
    
    if (h != NULL) {
        printf("Array created with length: %u\n", h->len);
    } else {
        printf("Failed to create array\n");
    }

    return 0;
}
