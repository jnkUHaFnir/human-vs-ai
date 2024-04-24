#include <stdlib.h>

typedef struct {
    int size; // size of array
    int *array;
} ArrayStruct;

int main() {
    ArrayStruct myArray;
  
    // Assume myArray.size is set to some value
    
    // Allocate memory for the array
    myArray.array = (int *)malloc(myArray.size * sizeof(int));
    
    // Check if memory allocation was successful
    if (myArray.array == NULL) {
        // Handle memory allocation error
        return 1;
    }
    
    // Use the array allocated here
    
    // Don't forget to free the memory when done
    free(myArray.array);
    
    return 0;
}
