#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size; // size of array
    int *array;
} ArrayStruct;

int main()
{
    ArrayStruct myStruct;
    
    // Set the size of the array
    myStruct.size = 10; // for example, allocate an array of size 10
    
    // Allocate memory for the array
    myStruct.array = (int *)malloc(myStruct.size * sizeof(int));
    
    if (myStruct.array == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Access and use the array elements like myStruct.array[0], myStruct.array[1], etc.
    
    // Don't forget to free the memory when you're done
    free(myStruct.array);

    return 0;
}
