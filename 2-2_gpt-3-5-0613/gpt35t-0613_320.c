#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    unsigned int len;
} intarr_t;

intarr_t* intarr_create(unsigned int len) { 
    intarr_t* arr = (intarr_t*) malloc(sizeof(intarr_t));
    if(arr != NULL) {
        arr->data = (int*) malloc(len * sizeof(int));
        if(arr->data != NULL) {
            arr->len = len;
            return arr;
        } else {
            free(arr);
        }
    }
    return NULL;
}

int main() {
    unsigned int len = 15;
    intarr_t* arr = intarr_create(len);
    if(arr != NULL) {
        printf("Array created with length: %d\n", arr->len);
    } else {
        printf("Failed to create array\n");
    }
    return 0;
}
