#include <stdlib.h>
#include <stdio.h>

#define SIZE 100

int main() {
    int *ptr = (int *)malloc(SIZE * sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Proceed with using ptr

    free(ptr);
    return 0;
}
