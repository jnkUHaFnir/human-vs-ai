#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zero_out_memory(int *ptr, size_t num_ints) {
    for (size_t i = 0; i < num_ints; i++) {
        ptr[i] = 0;
    }
}

int main() {
    size_t num_ints = 100; // Number of integers to zero out
    int *arr = (int*)malloc(num_ints * sizeof(int));

    // Check if allocation was successful
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    zero_out_memory(arr, num_ints);

    // Free allocated memory
    free(arr);

    return 0;
}
