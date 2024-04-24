#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size; // size of array
    int *array;
} ArrayStruct;

ArrayStruct createArray(int size) {
    ArrayStruct myArray;
    myArray.size = size;
    myArray.array = (int *)malloc(size * sizeof(int));
    
    if (myArray.array == NULL) {
        // Handle memory allocation failure
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    
    return myArray;
}

int main() {
    int size = 10; // for example
    
    ArrayStruct newArray = createArray(size);
    
    // Access and modify elements of the array
    for (int i = 0; i < size; i++) {
        newArray.array[i] = i * 10;
        printf("Array[%d] = %d\n", i, newArray.array[i]);
    }
    
    // Don't forget to free the allocated memory when done
    free(newArray.array);
    
    return 0;
}
