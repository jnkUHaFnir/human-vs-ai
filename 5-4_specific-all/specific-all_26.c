#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int *temp;
   int count;
} foo;

int main()
{
    foo *fake = (foo*)malloc(sizeof(foo));
    fake->count = 0;

    // Increase count
    ++(fake->count);

    // Allocate memory for temp
    fake->temp = (int*)malloc(fake->count * sizeof(int));

    // Check if memory allocation was successful
    if (fake->temp == NULL) {
        // Handle allocation failure
        printf("Memory allocation failed\n");
        return 1;
    }

    /* Do something */

    // Increase count
    ++(fake->count);

    // Reallocate memory for temp
    int *temp = (int*)realloc(fake->temp, fake->count * sizeof(int));

    if (temp == NULL) {
        // Handle reallocation failure
        printf("Memory reallocation failed\n");
        free(fake->temp); // Free previously allocated memory before exiting
        return 1;
    } else {
        fake->temp = temp;
    }

    // Use fake->temp for further operations

    // Free memory when no longer needed
    free(fake->temp);
    free(fake);

    return 0;
}
