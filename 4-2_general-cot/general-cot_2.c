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
  s1.array = (char *)malloc(10 * sizeof(char));
  if (s1.array == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }
  strcpy(s1.array, "Damn");
  
  display(&s1);
  
  free(s1.array);
  return 0;
}
