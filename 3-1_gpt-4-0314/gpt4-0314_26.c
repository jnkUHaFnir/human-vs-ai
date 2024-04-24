#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *temp;
    int count;
} foo;

int main() {
    foo *fake = (foo*)malloc(1 * sizeof(foo));
    fake->count = 0;

    ++(fake->count);
    fake->temp = (int*)malloc((fake->count) * sizeof(int));

    /* Do something */

    /* Now I want to realloc "temp" to ++(fake->count) */
    ++(fake->count);
    fake->temp = (int*)realloc(fake->temp, (fake->count) * sizeof(int));

    /* Don't forget to free the memory allocated */
    free(fake->temp);
    free(fake);

    return 0;
}
