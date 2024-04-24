#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int *temp;
   int count;
}foo;

int main()
{
    foo *fake = (foo*)malloc(1*sizeof(foo));
    fake->count = 0;
    
    ++(fake->count);
    fake->temp = (int*)malloc((fake->count)*sizeof(int));
    
    /* I do something */
    
    /*now i want to realloc "temp" to ++(fake->count) */
    
    ++(fake->count);
    fake->temp = (int*)realloc(fake->temp,(fake->count)*sizeof(int));
    
    // Always check if the allocation was successful
    if(fake->temp == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        return 1;
    }
    
    /* Continuing what you need to do */
    
    // Free allocated memory
    free(fake->temp);

    fake->temp = NULL;

    free(fake);
    fake = NULL;

    return 0;
}
