#include <stdlib.h>

typedef struct {
    int size; // size of array
    int *array;
} MyStruct;

void allocateArray(MyStruct *myStruct) {
    myStruct->array = (int *)malloc(myStruct->size * sizeof(int));
    if (myStruct->array == NULL) {
        // Handle memory allocation failure
    }
}

int main() {
    MyStruct myStruct;
    myStruct.size = 10; // For example, initialize the size to 10
    allocateArray(&myStruct);

    // Now you can use myStruct.array as an array of ints
    // Don't forget to free the memory when you're done with it
    free(myStruct.array);

    return 0;
}
