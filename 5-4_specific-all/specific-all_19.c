#include <stdlib.h>

typedef struct {
    int size; // size of array
    int *array;
} MyStruct;

void allocateMemory(MyStruct *myStruct) {
    myStruct->array = (int *)malloc(myStruct->size * sizeof(int));
    
    if (myStruct->array == NULL) {
        // Handle allocation failure
    }
}

int main() {
    MyStruct myStruct;
    myStruct.size = 10; // for example
    
    allocateMemory(&myStruct);
    
    // Now you can access and use myStruct.array
    // Don't forget to free the memory when you're done
    free(myStruct.array);

    return 0;
}
