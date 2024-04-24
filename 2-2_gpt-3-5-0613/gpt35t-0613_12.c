#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE* in = fopen("text.txt", "r");
  if (in == NULL) {
    printf("Failed to open file.");
    return 1;
  }

  char** lines = NULL;
  char line[50];
  int count = 0;
  while (fgets(line, sizeof(line), in) != NULL) {
    lines = realloc(lines, (count + 1) * sizeof(char*));
    if (lines == NULL) {
      printf("Failed to allocate memory.");
      return 1;
    }
    lines[count] = strdup(line);
    count++;
  }

  for (int i = 0; i < count; i++) {
    printf("Line %d: %s", i, lines[i]);
    // Do something with each line here
  }

  // Free memory
  for (int i = 0; i < count; i++) {
    free(lines[i]);
  }
  free(lines);
  
  return 0;
}
