#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct { char *array; } str1;

void display(str1 *p1) {
  if (p1->array != NULL) {
    printf("%s\n", p1->array);
  } else {
    printf("The string is NULL.\n");
  }
}

int main(void) {
  str1 s1;

  // Allocate memory for the string and check if the allocation was successful
  s1.array = (char *)malloc(5 * sizeof(char)); // "Damn\0" -> 5 characters including the null terminator
  if (s1.array == NULL) {
    fprintf(stderr, "Memory allocation failed.\n");
    return 1;
  }

  // Copy the string into the allocated memory
  strcpy(s1.array, "Damn");

  // Call display to print
  display(&s1);

  // Free the previously allocated memory
  free(s1.array);

  return 0;
}
