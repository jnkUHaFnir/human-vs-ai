#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *array;
} str1;

void display(str1 *p1) {
  // No need to allocate memory here.
  // Print the string pointed to by p1->array
  printf("%s\n", p1->array); // Added a newline for clear output
}

int main(void) {
  str1 s1;
  
  // Allocate memory for the array member of structure and check for success
  s1.array = (char *)malloc(10 * sizeof(char)); // Enough for the string "Damn" plus a null terminator
  if (s1.array == NULL) {
    perror("malloc");
    return 1;
  }

  // Now copy the string into the allocated memory
  strcpy(s1.array, "Damn");

  // Call the display function to print the string
  display(&s1);

  // After using s1.array, you must free the memory
  free(s1.array);

  return 0;
}
// Function prototype for display
void display(str1 *p1);
