int* array;
array = (int*)malloc(size * sizeof(int));
yourStruct.array = array;
typedef struct {
  int size; // size of array
  int* array;
} YourStruct;

int main() {
  YourStruct yourStruct;
  
  // Get the desired size from somewhere
  int size = 10;
  
  // Allocate memory for the int array
  int* array = (int*)malloc(size * sizeof(int));
  
  // Update the struct
  yourStruct.size = size;
  yourStruct.array = array;
  
  // Use the allocated memory
  
  // Free the allocated memory when no longer needed
  free(array);
  
  return 0;
}
