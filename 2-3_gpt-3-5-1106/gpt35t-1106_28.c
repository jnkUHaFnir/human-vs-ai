int main(void) {
  str1 s1;
  s1.array = "Damn"; // assigning the array in the structure
  display(&s1); // calling the display function
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct { char *array; } str1;

void display(str1 *p1); // prototype for the display function

void display(str1 *p1) {
  // your display function implementation
}

int main(void) {
  // your main function
}
