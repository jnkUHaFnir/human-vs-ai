#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *temp;
    int count; // Added semicolon here
} foo;

int main() {
    foo *fake = (foo*)malloc(sizeof(foo));
    fake->count = 0;

    ++(fake->count);
    fake->temp = (int*)malloc(fake->count * sizeof(int));

    // Do something here

    // Reallocating memory
    ++(fake->count);
    int *temp_ptr = (int*)realloc(fake->temp, fake->count * sizeof(int));
    
    if (temp_ptr) {
        fake->temp = temp_ptr;
    } else {
        // Handle realloc failure
        printf("Failed to reallocate memory\n");
    }

    // Don't forget to free allocated memory when done
    free(fake->temp);
    free(fake);

    return 0;
}
