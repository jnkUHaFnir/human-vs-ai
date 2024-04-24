#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size; // Size of the array
    int *array; // Pointer to the first element of the array
} IntArray;

int main() {
    // Instantiating the struct
    IntArray myIntArray;
    
    // Let's assume you want an array of 10 integers
    myIntArray.size = 10;
    
    // Allocate memory for the array using malloc
    // The size needed is the size of the array multiplied by the size of an int
    myIntArray.array = (int *)malloc(myIntArray.size * sizeof(int));
    
    // Check if the allocation was successful
    if (myIntArray.array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }
    
    // Now you can use the array, for example, initialize it with values
    for (int i = 0; i < myIntArray.size; i++) {
        myIntArray.array[i] = i;
    }
    
    // When you are done with the array, you should free the allocated memory
    free(myIntArray.array);
    myIntArray.array = NULL; // It's a good practice to null a pointer after freeing it

    return 0;
}
