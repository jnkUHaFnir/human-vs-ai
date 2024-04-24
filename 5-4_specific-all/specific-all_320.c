#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    unsigned int len;
} intarr_t;

intarr_t* intarr_create(unsigned int len) {
    intarr_t* intarr = (intarr_t*)malloc(sizeof(intarr_t));
    
    if(intarr != NULL) {
        intarr->data = (int*)malloc(len * sizeof(int));
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
    intarr_t* h = intarr_create(len);
    
    if(h != NULL) {
        printf("Array length: %u\n", h->len);
    } else {
        printf("Failed to create int array.\n");
    }
    
    return 0;
}
