#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct {
  char *array;
} str1;

void display(str1 *p1) {
  printf("%s\n", p1->array);
}

int main(void) {
  str1 s1;
  s1.array = (char *)malloc(10 * sizeof(char)); // Allocate memory for array
  strcpy(s1.array, "Damn");
  
  display(&s1); // Pass the address of s1 to the display function

  free(s1.array); // Free the allocated memory

  return 0;
}
