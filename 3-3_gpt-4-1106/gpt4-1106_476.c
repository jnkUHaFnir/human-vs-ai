#include <stdio.h>
#include <stdlib.h>

char * readline(FILE *fp) {
  if (fp == NULL) {
    return NULL; // Check for invalid file pointer.
  }

  int buff_len = 0, buff_capacity = 64; // Start with a buffer size of 64 bytes.
  char *buffer = malloc(buff_capacity);
  if (buffer == NULL) {
    return NULL; // Check for malloc failure.
  }

  char ch;
  while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
    if (buff_len == buff_capacity - 1) {
      // Expand the buffer when necessary (minus one for null terminator).
      buff_capacity *= 2;
      buffer = realloc(buffer, buff_capacity);
      if (buffer == NULL) {
        return NULL; // Check for realloc failure.
      }
    }
    buffer[buff_len++] = ch; // Append character and increment length.
  }

  buffer[buff_len] = '\0'; // Null-terminate the string.
  return buffer;
}
