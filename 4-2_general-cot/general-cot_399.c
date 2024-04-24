#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

int main() {
    int* data = (int*)malloc(BUFFER_SIZE * sizeof(int));
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Use the allocated memory here

    free(data); // Don't forget to free the allocated memory when done

    return 0;
}
