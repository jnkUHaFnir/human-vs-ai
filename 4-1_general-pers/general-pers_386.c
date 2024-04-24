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

char* removechar(char *str, int ch) {
  char *cpos = str;
  while ((cpos = strchr(cpos, ch))) {
    memmove(cpos, cpos + 1, strlen(cpos));
  }
  return str;
}

int main(int argc, char **argv) {
  char *reds[max];
  int i;

  FILE *file = argc > 1 ? fopen(argv[1], "r") : stdin;
  if (file == NULL) {
    printf("Error opening file!\n");
    return 1;
  }
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  for (i = 0; i < max; i++) {
    reds[i] = malloc(stringlength);
    if (fgets(reds[i], stringlength, file) == NULL)
      break;
    removechar(reds[i], ' '); // removes spaces
  }
  
  for (i = 0; i < max; i++) {
    if (i > 0) printf(" ");
    printf("%s", reds[i]);
  }

  int success = 1;
  size_t size = sizeof(stringcard) / sizeof(stringcard[0]);
  size_t size2 = i; // Use the actual number of strings read from the file

  if (size == size2) {
    for (int j = 0; j < size; j++) {
      int found = 0;
      for (int k = 0; k < size2; k++) {
        if (strcmp(stringcard[j], reds[k]) == 0) {
          found = 1;
          break;
        }
      }
      if (!found) {
        success = 0;
        printf("\nElement %s not found in the file.\n", stringcard[j]);
      }
    }
  } else {
    printf("\nFile doesn't contain all expected elements.\n");
    success = 0;
  }

  if (success) {
    printf("\nAll elements found in the file.\n");
  }

  for (i = 0; i < max; i++) {
    free(reds[i]);
  }
  if (file != stdin) {
    fclose(file);
  }

  return 0;
}
