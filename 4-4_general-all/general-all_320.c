#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    unsigned int len;
} intarr_t;

intarr_t* intarr_create(unsigned int len) {
    intarr_t* new_intarr = (intarr_t*)malloc(sizeof(intarr_t));

    if(new_intarr != NULL) {
        new_intarr->data = (int*)malloc(len * sizeof(int));
        
        if(new_intarr->data == NULL) {
            free(new_intarr); // Free the structure if data allocation fails
            return NULL;
        }
        
        new_intarr->len = len;
        return new_intarr;
    } else {
        return NULL;
    }
}

int main() {
    int len = 15;
    intarr_t* new_array = intarr_create(len);

    if(new_array != NULL) {
        printf("Array created successfully with length: %u\n", new_array->len);
    } else {
        printf("Failed to create array.\n");
    }

    return 0;
} 
