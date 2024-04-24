#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    unsigned int len;
} intarr_t;

intarr_t* intarr_create(unsigned int len) { 
    intarr_t *arr = (intarr_t*) malloc(sizeof(intarr_t)); 
    if(arr != NULL) { 
        arr->data = (int*) malloc(len * sizeof(int));
        if (arr->data == NULL) {
            free(arr); //It is important to free the previously allocated memory to avoid memory leaks
            return NULL; 
        }
        arr->len = len; 
    }
    return arr;
}

int main() {
    unsigned int len = 15;
    intarr_t* p = intarr_create(len);
    if(p != NULL) {
        printf("%u\n", p->len); //Printing length of our structure
        //Remember to free allocated memory after using it
        free(p->data);
        free(p);
    }
    return 0;
} 