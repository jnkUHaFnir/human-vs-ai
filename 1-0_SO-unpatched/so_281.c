C
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  size_t n = 0, *array = NULL;
  if ((scanf("%zu", &n) <= 0) ||
      (n > SIZE_MAX / sizeof(*array)) ||
      ((array = malloc(n * sizeof(*array))) == NULL)) 
  {
    return EXIT_FAILURE;
  }
  // Use array
  free(array);  // Don't forget to free the memory.
}