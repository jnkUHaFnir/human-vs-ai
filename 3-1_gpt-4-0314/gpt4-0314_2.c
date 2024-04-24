#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct { char *array; } str1;

// Prototype for display function
void display(str1 *p1);

// Allocation function
void allocateArray(str1 *p1, int size){ 
   p1->array = (char *)malloc(size * sizeof(char));
}

int main(void) {
  str1 s1;
  allocateArray(&s1, 10); // Allocate memory for array
  strcpy(s1.array, "Damn");
  display(&s1); // Call display function
  free(s1.array); // Free allocated memory
  return 0;
}

void display(str1 *p1) {
  printf("%s", p1->array);
}
