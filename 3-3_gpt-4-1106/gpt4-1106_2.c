#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct { char *array; } str1;

// Function prototype
void display(str1 *p1);

void display(str1 *p1) {
  printf("%s\n", p1->array);
}

int main(void) {
  str1 s1;

  // Allocate memory for the string array within the struct
  s1.array = (char *)malloc(10 * sizeof(char));
  if (s1.array == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }

  strcpy(s1.array, "Damn");

  // Call the display function to print the string
  display(&s1);

  // Free the allocated memory
  free(s1.array);

  return 0;
}
