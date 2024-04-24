#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int size; //size of array
  int *array;
} MyStruct;

int main()
{
  MyStruct myStruct;
  myStruct.size = 10; // Assign the size of the array (e.g., 10 elements)
  
  // Allocate memory for the int array using the size variable and malloc
  myStruct.array = (int *)malloc(myStruct.size * sizeof(int));
  
  if (myStruct.array == NULL)
  {
    printf("Memory allocation failed\n");
    return 1;
  }

  // Do any operation with memory you've allocated
  
  // Remember to free the allocated memory before the program exits
  free(myStruct.array);
  return 0;
}
