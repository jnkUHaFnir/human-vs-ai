#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct {
  char *array;
} str1;

void display(str1 *p1) {
  printf("%s", p1->array);
}

int main(void) {
  str1 s1;
  s1.array = (char *)malloc(10 * sizeof(char)); // allocate memory for array
  strcpy(s1.array, "Damn"); // copy string to array
  display(&s1); // call display function and pass the address of s1
  free(s1.array); // free the allocated memory
  return 0;
}
void display(str1 *p1);
