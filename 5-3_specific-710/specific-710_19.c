#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size; //size of array
  int *array;
} ArrayStruct;

int main() {
  ArrayStruct myArray;
  
  // Set the size of the array
  myArray.size = 10; // For example, a size of 10
  
  // Allocate memory for the array
  myArray.array = (int*)malloc(myArray.size * sizeof(int));
  
  if (myArray.array == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }
  
  // Access and use the array elements as needed
  
  // Don't forget to free the memory when done
  free(myArray.array);
  
  return 0;
}
