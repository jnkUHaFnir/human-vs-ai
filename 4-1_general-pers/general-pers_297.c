#include <stdio.h>

#define MAX_SIZE 10000

int main() {
  int histogram[MAX_SIZE];
  int i;

  while (1) {
    int *rectPtr = histogram;
    int size;

    if (scanf("%d", &size) != 1 || size <= 0 || size > MAX_SIZE) {
      printf("Invalid input size\n");
      return 1; // Exit with an error status
    }

    for (i = 0; i < size; ++i) {
      if (scanf("%d", rectPtr) != 1) {
        printf("Invalid input data\n");
        return 1; // Exit with an error status
      }
      
      rectPtr++;
    }

    printf("%d\n", 1);
  }

  return 0;
}
