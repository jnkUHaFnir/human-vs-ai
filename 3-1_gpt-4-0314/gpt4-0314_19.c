#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size; // size of array
    int* array;
} MyStruct;

int main() {
    MyStruct myStruct;

    myStruct.size = 10; // Set the size of the array
    myStruct.array = (int*) malloc(myStruct.size * sizeof(int)); // Allocate memory for the int array

    if (myStruct.array == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    // Populate the array with some values
    for (int i = 0; i < myStruct.size; i++) {
        myStruct.array[i] = i * 10;
    }

    // Print the array
    for (int i = 0; i < myStruct.size; i++) {
        printf("myStruct.array[%d] = %d\n", i, myStruct.array[i]);
    }

    // Free the memory when finished
    free(myStruct.array);

    return 0;
}
