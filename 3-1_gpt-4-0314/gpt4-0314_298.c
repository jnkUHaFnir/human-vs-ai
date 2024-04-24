#include <stdio.h>
#include <stdlib.h>

void process(int *arr, int size) {
    // Process your array here
    // ...
}

int main() {
    int *arr;
    int current_size = 10; // Initial size, can be any reasonable value
    int idx = 0;

    // Allocate memory for the array
    arr = (int *)malloc(current_size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Loop to add entities
    while (/* condition to continue adding entities */) {
        // If the array is full, increase its size with realloc
        if (idx == current_size) {
            current_size *= 2; // Double the size, or any other growing strategy
            int *new_arr = (int *)realloc(arr, current_size * sizeof(int));
            if (new_arr == NULL) {
                printf("Memory reallocation failed.\n");
                free(arr);
                exit(1);
            } else {
                arr = new_arr;
            }
        }

        // Add an entity to the list
        // arr[idx] = some_entity;
        idx++;
    }

    // Process the populated array
    process(arr, idx);

    // Release the allocated memory
    free(arr);

    return 0;
}
