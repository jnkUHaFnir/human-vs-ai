#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char *s = malloc(strlen("ABC") + 1); // Allocate memory for s
  if (s == NULL) {
    // Handle allocation failure
    return 1;
  }

  strcpy(s, "ABC"); // Copy the string "ABC" into the allocated memory
  printf("%s\n", s);

  strcpy(s, "DEF"); // Copy the string "DEF" into the allocated memory
  printf("%s\n", s); 

  free(s); // Don't forget to free the allocated memory
  return 0;
}
