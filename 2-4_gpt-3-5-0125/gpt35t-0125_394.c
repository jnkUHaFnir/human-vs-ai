#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  size_t message_len = 1; /* + 1 for terminating NULL */
  char *buffer = (char*) malloc(message_len);
  buffer[0] = '\0'; // Initialize buffer to empty string

  for (int i = 0; i < 200000; i++)
  {
    // Calculate the size needed for the current string
    int size = snprintf(NULL, 0, "%d \n", i);
    char *a = malloc(size + 1);
    sprintf(a, "%d \n", i);

    // Increase the buffer size to accommodate the new string
    message_len += strlen(a) + 1; /* + 1 for separator ';' */
    buffer = (char*) realloc(buffer, message_len);
    
    // Append the new string to the buffer
    strcat(buffer, a);

    free(a); // Free the allocated string
  }
  
  // Print or use the buffer as needed
  printf("%s", buffer);
  
  free(buffer); // Free the final buffer

  return 1;
}
