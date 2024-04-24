#include <stdlib.h>

typedef struct {
    int size; // size of array
    int* array;
} ArrayStruct;

ArrayStruct* allocateArray(int size) {
    ArrayStruct* arrayStruct = malloc(sizeof(ArrayStruct));
    if (arrayStruct) {
        arrayStruct->size = size;
        arrayStruct->array = malloc(size * sizeof(int));
        if (arrayStruct->array == NULL) {
            // Handle allocation failure
            free(arrayStruct);
            return NULL;
        }
    }
    return arrayStruct;
}

// Usage example:
int main() {
    int arraySize = 10;
    ArrayStruct* myArray = allocateArray(arraySize);
    if (myArray) {
        // Access and modify elements in myArray->array
        // Don't forget to free memory when done
        free(myArray->array);
        free(myArray);
    }
    return 0;
}
