#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size; // size of array
    int *array;
} MyStruct;

MyStruct *allocateMemory(int size) {
    MyStruct *myStruct = (MyStruct *)malloc(sizeof(MyStruct));
    myStruct->size = size;
    myStruct->array = (int *)malloc(size * sizeof(int));

    return myStruct;
}

int main() {
    int size = 5; // for example

    MyStruct *myStruct = allocateMemory(size);

    // Check if memory allocation was successful
    if (myStruct == NULL || myStruct->array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Use the allocated array
    for (int i = 0; i < size; i++) {
        myStruct->array[i] = i;
    }

    // Free the allocated memory when done
    free(myStruct->array);
    free(myStruct);

    return 0;
}
