#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int *temp;
   int count;
} foo;

int main() {
    foo *fake = (foo*)malloc(sizeof(foo));
    if (fake == NULL) {
        perror("Error allocating memory for struct");
        exit(EXIT_FAILURE);
    }

    fake->count = 0;
    
    // Increment count and reallocate memory for the integer array.
    ++(fake->count);
    int *temp_ptr = (int*)realloc(fake->temp, fake->count * sizeof(int));
    if (temp_ptr == NULL) {
        perror("Error reallocating memory for integer array");
        free(fake->temp);
        free(fake);
        exit(EXIT_FAILURE);
    }

    fake->temp = temp_ptr;

    /* Do something with the integer array */

    // Now, if we want to expand the array, increment count and reallocate memory.
    ++(fake->count);
    temp_ptr = (int*)realloc(fake->temp, fake->count * sizeof(int));
    if (temp_ptr == NULL) {
        perror("Error reallocating memory for integer array");
        free(fake->temp);
        free(fake);
        exit(EXIT_FAILURE);
    }

    fake->temp = temp_ptr;

    // Release memory when done.
    free(fake->temp);
    free(fake);

    return 0;
}
