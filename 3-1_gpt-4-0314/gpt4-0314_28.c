#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct {
  char *array;
} str1;

// Add a function prototype for 'display()'
void display(str1 *p1);

int main(void) {
  str1 s1;

  // Allocate memory for the string inside the struct
  s1.array = (char *)malloc(10 * sizeof(char));

  // Check if memory allocation was successful
  if (s1.array == NULL) {
      printf("Memory allocation failed\n");
      return 1;
  }

  // Copy the string "Damn" into the allocated memory
  strcpy(s1.array, "Damn");

  // Call the 'display()' function to print the string
  display(&s1);

  // Free the memory allocated for the string
  free(s1.array);

  return 0;
}

void display(str1 *p1) {
  // No need to allocate memory here, just print the string
  printf("%s", p1->array);
}
