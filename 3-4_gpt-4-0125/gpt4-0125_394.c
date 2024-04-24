#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Predict the maximum possible size needed.
  // Example, if each number plus a newline is roughly 6 bytes on average,
  // you can estimate the size. This is simplified; consider the length of numbers.
  size_t predictedSize = 200000 * 6; // Adjust based on your data.
  char *buffer = malloc(predictedSize);

  if (buffer == NULL) {
      perror("Failed to allocate memory");
      return 1;
  }

  size_t usedSize = 0; // How much of the buffer is used.
  size_t bufferSize = predictedSize; // Current size of the buffer.

  for (int i = 0; i < 200000; i++) {
    // Check how much space we need for the next line
    int needed = snprintf(NULL, 0, "%d \n", i);

    // Check if we need to expand the buffer
    if (usedSize + needed >= bufferSize) {
      size_t newSize = bufferSize * 2; // Double the buffer size.
      char *newBuffer = realloc(buffer, newSize);
      if (newBuffer == NULL) {
          perror("Failed to reallocate memory");
          free(buffer); // Don't forget to free the original buffer before exiting.
          return 1;
      }
      buffer = newBuffer;
      bufferSize = newSize;
    }

    // Now we are sure we have space, so we append.
    int written = snprintf(buffer + usedSize, bufferSize - usedSize, "%d \n", i);
    // Make sure our size tracker accounts for what we've added
    if (written > 0) {
      usedSize += written;
    } else {
      printf("Error writing to buffer\n");
      break; // Handle error.
    }
  }

  // Make use of buffer
  printf("%.*s", (int)usedSize, buffer);

  free(buffer);

  return 0;
}
