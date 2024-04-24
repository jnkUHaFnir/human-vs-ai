#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

int main() {
    int *ptr = (int*)malloc(sizeof(int) * BUFFER_SIZE);
    
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed. Exiting...\n");
        exit(EXIT_FAILURE);
    }
    
    // Proceed with using ptr
    
    free(ptr);
    
    return 0;
}
