#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *temp;
    int count;
} foo;

int main() {
    foo *fake = (foo*)malloc(sizeof(foo));
    fake->count = 0;

    ++(fake->count);
    fake->temp = (int*)malloc(fake->count * sizeof(int));

    /* Do something */

    /* Now if you want to expand the array */
    ++(fake->count);
    fake->temp = (int*)realloc(fake->temp, fake->count * sizeof(int));

    /* Don't forget to check if realloc was successful */
    if (fake->temp == NULL) {
        printf("Memory reallocation failed.");
        exit(1);
    }

    // Use fake->temp as needed

    free(fake->temp);
    free(fake);

    return 0;
}
