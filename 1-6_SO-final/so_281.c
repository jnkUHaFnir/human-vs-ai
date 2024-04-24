C
#include <stdio.h>
#include <stdlib.h>
int main() {
  int n;
  scanf("%d", &n);
  int *array = malloc(n);
  // Use array
  free(array);  // Don't forget to free the memory.
}