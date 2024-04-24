C
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  int n = 0, *array = NULL;
  if (scanf("%d", &n) <= 0 || n > SIZE_MAX / sizeof(*array) ||
      ((array = malloc(n * sizeof(*array))) == NULL)) {
    return EXIT_FAILURE;
  }
  // Use array
  free(array);  // Don't forget to free the memory.
}