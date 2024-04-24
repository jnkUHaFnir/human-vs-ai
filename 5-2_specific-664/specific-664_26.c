#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *temp;
    int count;
} foo;

int main() {
    foo *fake = (foo*)malloc(1*sizeof(foo));
    if (fake == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    fake->count = 0;

    ++(fake->count);
    fake->temp = (int*)malloc((fake->count)*sizeof(int));
    if (fake->temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    /* Do something */

    /* Now I want to realloc "temp" to ++(fake.count) */
    ++(fake->count);
    int *temp_ptr = (int*)realloc(fake->temp, (fake->count)*sizeof(int));
    if (temp_ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    fake->temp = temp_ptr;

    /* Don't forget to free the allocated memory when you are done using it */
    free(fake->temp);
    free(fake);

    return 0;
}
