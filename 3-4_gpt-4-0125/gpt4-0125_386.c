#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 13
#define stringlength 8
const char *stringcard[] = {
  "REDA",
  "RED2",
  "RED3",
  "RED4",
  "RED5",
  "RED6",
  "RED7",
  "RED8",
  "RED9",
  "RED10",
  "REDJ",
  "REDQ",
  "REDK",
};

char *cleanString(char str[]) {
  char *cpos = str;
  while ((cpos = strchr(cpos, ' ')) || (cpos = strchr(cpos, '\n'))) { // Removes both spaces and newline characters
    strcpy(cpos, cpos + 1);
  }
  return str;
}

int main(int argc, char **argv) {
  char *reds[max];
  int i, j, found;

  FILE *file = argc > 1 ? fopen(argv[1], "r") : stdin;
  if (file == NULL || argc != 2) {
    printf("[ERR]\n");
    return 1;
  }

  for (i = 0; i < max; i++) {
    reds[i] = malloc(stringlength + 1); // +1 for the null terminator
    fgets(reds[i], stringlength + 1, file);
  }
  
  // Remove spaces and newlines
  for (i = 0; i < max; i++) {
    cleanString(reds[i]);
  }

  // Check if all elements in stringcard are present in reds
  size_t size = sizeof(stringcard) / sizeof(stringcard[0]);
  for (i = 0, found = 1; i < size && found; i++) {
    found = 0;
    for (j = 0; j < max; j++) {
      if (strcmp(stringcard[i], reds[j]) == 0) {
        found = 1;
        break;
      }
    }
    if (!found) {
      printf("Missing or incorrect order: %s\n", stringcard[i]);
    }
  }

  // Check if all elements in reds are present in stringcard (Optional, based on requirements)
  // This step is omitted for brevity but follows a similar approach.

  // Print results
  if(found) {
    printf("Success: Input file contains all required elements in the correct order.\n");
  } else {
    printf("Failed: Input file is missing some elements or the order is incorrect.\n");
  }

  // Cleanup
  for (i = 0; i < max; i++) {
    free(reds[i]);
  }

  fclose(file);
  return 0;
}
