#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    unsigned int len;
} intarr_t;

intarr_t* intarr_create(unsigned int len) {
    intarr_t* intarr = (intarr_t*) malloc(sizeof(intarr_t)); // Allocate memory for intarr_t struct
    if (intarr != NULL) {
        intarr->data = (int*) malloc(len * sizeof(int)); // Allocate memory for int data array
        if (intarr->data != NULL) {
            intarr->len = len;
            return intarr;
        } else {
            free(intarr);
            return NULL;
        }
    } else {
        return NULL;
    }
}

int main() {
    int len = 15;
    intarr_t* intarr = intarr_create(len);

    if (intarr != NULL) {
        printf("intarr created successfully with length: %u\n", intarr->len);

        // Don't forget to free memory when done
        free(intarr->data);
        free(intarr);
    } else {
        printf("intarr creation failed\n");
    }

    return 0;
}
