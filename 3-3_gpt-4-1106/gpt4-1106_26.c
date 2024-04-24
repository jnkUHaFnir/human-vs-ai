#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *temp;
    int count;
} foo;

int main() {
    foo *fake = (foo *)malloc(sizeof(foo));
    if (!fake) {
        // Handle memory allocation error
        perror("Allocation failed for fake");
        return EXIT_FAILURE;
    }

    fake->count = 0;

    // Increase the count and allocate memory for temp
    ++(fake->count);
    fake->temp = (int *)malloc(fake->count * sizeof(int));
    if (!(fake->temp)) {
        // Handle memory allocation error, and remember to free allocated memory for 'fake'
        perror("Allocation failed for fake->temp");
        free(fake);
        return EXIT_FAILURE;
    }

    /* Do something with fake->temp[0] */

    // Correctly reallocate "temp" for the new count
    ++(fake->count);
    int *new_temp = (int *)realloc(fake->temp, fake->count * sizeof(int));
    if (!new_temp) {
        // Handle realloc error but don't forget previously allocated memory for fake->temp
        perror("Reallocation failed for fake->temp");
        
        // It's important to not overwrite fake->temp with NULL here because you would lose the reference to the previously allocated memory
        // If you do fake->temp = new_temp; without checking new_temp first, you'd lose the reference to the originally allocated memory and create a memory leak
        free(fake->temp);  // free the old pointer if realloc failed
        free(fake);        // also free the structure itself before exiting
        return EXIT_FAILURE;
    }
    fake->temp = new_temp;  // Update pointer because realloc was successful

    /* You can now use fake->temp[0] and fake->temp[1] */

    // Remember to free the memory allocated for temp and fake
    free(fake->temp);
    free(fake);

    return 0;
}
