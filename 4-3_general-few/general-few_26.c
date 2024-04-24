#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *temp;
    int count;
}foo;

int main()
{
    foo *fake = (foo*)malloc(sizeof(foo));
    fake->count = 0;

    ++(fake->count);
    fake->temp = (int*)malloc(fake->count * sizeof(int));

    /* Do something */

    /* Now realloc "temp" to (fake->count + 1) */
    ++(fake->count);
    fake->temp = (int*)realloc(fake->temp, fake->count * sizeof(int));

    free(fake->temp);
    free(fake);
    
    return 0;
}
