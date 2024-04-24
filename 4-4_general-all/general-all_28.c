#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct {
  char *array;
} str1;

// Function prototype declaration
void display(str1 *p1);

void display(str1 *p1) {
  printf("%s\n", p1->array);
}

int main(void) {
  str1 s1;
  s1.array = (char *)malloc(10 * sizeof(char)); // Allocate memory for the string
  strcpy(s1.array, "Damn");
  
  // Call display function
  display(&s1);

  // Don't forget to free the allocated memory
  free(s1.array);

  return 0;
}
