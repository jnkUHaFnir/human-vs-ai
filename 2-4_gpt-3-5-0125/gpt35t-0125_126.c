// Declare the struct
typedef struct {
  int size; //size of array
  int* array;
} ArrayStruct;

// Create an instance of the struct
ArrayStruct myArray;

// Assign a size to the array
myArray.size = 10;

// Allocate memory for the array using malloc
myArray.array = (int*)malloc(myArray.size * sizeof(int));

// Check if memory allocation was successful
if (myArray.array == NULL) {
  printf("Error: Memory allocation failed");
} else {
  // Memory allocation was successful, you can now use the array
  for (int i = 0; i < myArray.size; i++) {
    myArray.array[i] = i; // Initialize values or do any operation on the array
  }
}

// Don't forget to free the memory when done using it
free(myArray.array);
