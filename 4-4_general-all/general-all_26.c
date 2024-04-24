#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int *temp;
   int count;
} foo;

int main() {
    foo *fake = (foo*)malloc(sizeof(foo));
    if (fake == NULL) {
        fprintf(stderr, "Failed to allocate memory for foo.\n");
        exit(1);
    }

    fake->count = 0;
    ++(fake->count);

    fake->temp = (int*)malloc(fake->count * sizeof(int));
    if (fake->temp == NULL) {
        fprintf(stderr, "Failed to allocate memory for temp.\n");
        exit(1);
    }

    /* Do something */

    ++(fake->count);
    int *temp_ptr = (int*)realloc(fake->temp, fake->count * sizeof(int));
    if (temp_ptr == NULL) {
        fprintf(stderr, "Failed to reallocate memory for temp.\n");
        exit(1);
    } else {
        fake->temp = temp_ptr;
    }

    free(fake->temp);
    free(fake);

    return 0;
}
