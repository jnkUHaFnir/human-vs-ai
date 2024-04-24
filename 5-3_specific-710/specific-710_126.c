#include <stdlib.h>

typedef struct {
    int size; // size of array
    int* array;
} MyStruct;

MyStruct myStruct;
myStruct.size = 10; // set the size to 10 or any desired size

// allocate memory for the array
myStruct.array = malloc(myStruct.size * sizeof(int));

// check if malloc was successful
if (myStruct.array == NULL) {
    // handle malloc failure
    exit(1); // for example, exit the program with an error code
}

// Now you can use myStruct.array as an array of integers with size myStruct.size

// Don't forget to free the allocated memory when you're done using it
free(myStruct.array);
