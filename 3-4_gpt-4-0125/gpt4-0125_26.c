#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *temp;
    int count;
} foo;

int main() {
    // Allocate memory for foo
    foo *fake = malloc(sizeof(foo));
    if (fake == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Return non-zero to indicate failure
    }

    fake->count = 0;

    // Increment and allocate memory for temp
    ++(fake->count);
    fake->temp = malloc(fake->count * sizeof(int));
    if (fake->temp == NULL) {
        printf("Memory allocation failed\n");
        // Clean up previously allocated memory before failing
        free(fake);
        return 1;
    }

    // Now realloc "temp" to ++(fake->count)
    ++(fake->count);
    int* temp_realloc = realloc(fake->temp, fake->count * sizeof(int));
    if (temp_realloc == NULL) {
        printf("Memory reallocation failed\n");
        free(fake->temp);
        free(fake);
        return 1;
    }
    fake->temp = temp_realloc;

    // Remember to free allocated memory
    free(fake->temp);
    free(fake);

    return 0;
}
