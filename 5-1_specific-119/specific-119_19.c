#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size; // size of array
    int *array;
} IntArray;

void allocateIntArray(IntArray *intArray) {
    intArray->array = (int*)malloc(intArray->size * sizeof(int));
    if (intArray->array == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1); // Exit the program if memory allocation fails
    }
}

int main() {
    IntArray myIntArray;
    
    // Set the size of the array
    myIntArray.size = 5;

    // Allocate memory for the array
    allocateIntArray(&myIntArray);

    // Access and use the array
    for (int i = 0; i < myIntArray.size; i++) {
        myIntArray.array[i] = i * 2;
        printf("%d ", myIntArray.array[i]);
    }

    // Don't forget to free the allocated memory
    free(myIntArray.array);

    return 0;
}
