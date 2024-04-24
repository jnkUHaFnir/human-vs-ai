typedef struct {
  int size; // size of the array
  int *array; // pointer to the first element of the array
} ArrayStruct;
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size;
  int *array;
} ArrayStruct;

int main() {
  ArrayStruct myStruct;
  
  myStruct.size = 10; // For example, setting the size of the array to 10 ints
  
  // Allocate memory for the array in the struct
  myStruct.array = (int *)malloc(myStruct.size * sizeof(int));
  
  // Always check if malloc was successful
  if(myStruct.array == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }
  
  // Now you can use the array, for example initializing it
  for(int i = 0; i < myStruct.size; i++) {
    myStruct.array[i] = i; // Initializing each element to its index
  }
  
  // Example of using the array
  for(int i = 0; i < myStruct.size; i++) {
    printf("%d ", myStruct.array[i]);
  }
  printf("\n");
  
  // Remember to free the memory when done
  free(myStruct.array);
  
  return 0;
}
