typedef struct {
    int size;  // size of the array
    int* array;  // pointer to the array of integers
} MyStruct;
free(myStruct->array);  // Free the allocated array
free(myStruct);         // Free the struct memory
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int* array;
} MyStruct;

int main() {
    MyStruct* myStruct = malloc(sizeof(MyStruct));
    if (!myStruct) {
        // Handle memory allocation failure
        return 1;
    }

    myStruct->size = 10; // For example
    myStruct->array = (int*)malloc(myStruct->size * sizeof(int));
    if (!myStruct->array) {
        // Handle memory allocation failure for the array
        free(myStruct);
        return 1;
    }

    // Example usage: Initialize and print array
    for (int i = 0; i < myStruct->size; i++) {
        myStruct->array[i] = i;
        printf("%d ", myStruct->array[i]);
    }

    // Cleanup
    free(myStruct->array);
    free(myStruct);

    return 0;
}
