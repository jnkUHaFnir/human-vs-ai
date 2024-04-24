#include <stdio.h>

#define MAX_SIZE 10000 // use a defined constant for maximum size

int main(int argc, const char * argv[]) {
  int histogram[MAX_SIZE];
  int i;

  while (1) {
    int size;
    if (scanf("%d", &size) != 1 || size == 0) {
      // break out of the loop if scanf fails or size is 0
      break;
    }

    if (size > MAX_SIZE) {
      // Prevents buffer overflow - you could also handle this with an error message or exit
      size = MAX_SIZE;
    }

    for (i = 0; i < size; ++i) {
        if (scanf("%d", &histogram[i]) != 1) {
          // handle incorrect input; possibly flush the input buffer or return error
          fprintf(stderr, "Failed to read the expected number of integers.\n");
          return 1;
        }
    }

    printf("%d\n", 1);
    fflush(stdout); // Ensure the output is printed immediately
  }

  return 0;
}
