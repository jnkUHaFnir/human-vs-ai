#include <stdio.h>
#include <stdlib.h> // Include the stdlib.h header file for malloc()

typedef struct {
    int* data;
    unsigned int len;
} intarr_t;

intarr_t* intarr_create(unsigned int len) {
    intarr_t* int_arr = (intarr_t*)malloc(sizeof(intarr_t)); // Allocate memory for intarr_t struct
    if(int_arr != NULL) {
        int_arr->data = (int*)malloc(len * sizeof(int)); // Allocate memory for data array
        int_arr->len = len;
        return int_arr;
    } else {
        return NULL;
    }
}

int main() {
    unsigned int len = 15;
    intarr_t* h = intarr_create(len);
    
    if(h != NULL) {
        printf("Length of intarr_t: %d\n", h->len);
    } else {
        printf("Failed to create intarr_t\n");
    }
    
    return 0;
}
