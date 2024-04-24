#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *temp;
    int count;
} foo;

int main() {
    foo *fake = malloc(sizeof(foo));
    if (fake == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    fake->count = 0;
    
    fake->count++;
    fake->temp = malloc(fake->count * sizeof(int));
    if (fake->temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(fake);
        return 1;
    }
    
    /* Do something */
    
    /* Now if you want to realloc "temp" to ++(fake.count) */
    int *temp_ptr = realloc(fake->temp, (fake->count + 1) * sizeof(int));
    if (temp_ptr != NULL) {
        fake->temp = temp_ptr;
        fake->count++;
        printf("Memory reallocated successfully\n");
    } else {
        fprintf(stderr, "Memory reallocation failed\n");
        free(fake->temp);
    }
    
    free(fake->temp); /* Free the memory if needed */
    free(fake);
    
    return 0;
}
