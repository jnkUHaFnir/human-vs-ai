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

char * removechar(char str[], int ch) {
  char *cpos = str;
  while ((cpos = strchr(cpos, ch))) {
    strcpy(cpos, cpos + 1);
  }
  return str;
}

int main(int argc, char ** argv) {
  char *reds[max];
  int i;

  FILE *file = argc > 1 ? fopen(argv[1], "r") : stdin;

  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  if (argc != 2) {
    printf("Usage: %s <input_file>\n", argv[0]);
    return 0;
  }

  for (i = 0; i < max; i++) {
    reds[i] = malloc(stringlength);
    fgets(reds[i], stringlength, file);
  }

  printf("Contents of 'reds':\n");
  for (i = 0; i < max; i++) {
    printf("%s", reds[i]);
  }

  // remove spaces
  for (i = 0; i < max; i++) {
    removechar(reds[i], ' ');
  }

  printf("\nContents of 'reds' after removing spaces:\n");
  for (i = 0; i < max; i++) {
    printf("%s", reds[i]);
  }

  int success = 1;
  size_t size = sizeof(stringcard) / sizeof(stringcard[0]);
  size_t size2 = sizeof(reds) / sizeof(reds[0]);

  if (size == size2) {
    for (int i = 0; i < size; i++) {
      int found = 0;
      for (int j = 0; j < size2; j++) {
        if (strcmp(stringcard[i], reds[j]) == 0) {
          found = 1;
          break;
        }
      }
      if (!found) {
        success = 0;
        break;
      }
    }
  } else {
    success = 0;
  }

  if (success) {
    printf("\nAll elements of 'stringcard' are present in 'reds'.\n");
  } else {
    printf("\nNot all elements of 'stringcard' are present in 'reds'.\n");
  }

  for (i = 0; i < max; i++) {
    free(reds[i]);
  }

  return 0;
}
