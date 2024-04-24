#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size; // size of array
    int *array;
} MyStruct;

int main() {
    MyStruct myStruct;
    
    // Assign a value to size (for example, 5)
    myStruct.size = 5;
    
    // Allocate memory for the array
    myStruct.array = (int *)malloc(myStruct.size * sizeof(int));
    
    if (myStruct.array == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    
    // You can now access and use the array elements like myStruct.array[index]
    
    // Don't forget to free the memory when you are done
    free(myStruct.array);
    
    return 0;
}
