#include <stdlib.h>

typedef struct {
    int size; // size of array
    int *array;
} ArrayStruct;

// Function to allocate memory for the array based on size
void allocateArray(ArrayStruct *arrStruct) {
    arrStruct->array = (int *)malloc(arrStruct->size * sizeof(int));
    if (arrStruct->array == NULL) {
        // Memory allocation failed, handle error as needed
        // Example: printf("Memory allocation failed");
    }
}

// Example usage
int main() {
    ArrayStruct myArray;
    myArray.size = 5; // Setting the size to 5 as an example
    allocateArray(&myArray);

    // Now you can access and use myArray.array as needed

    // Don't forget to free the allocated memory when done using it
    free(myArray.array);

    return 0;
}
