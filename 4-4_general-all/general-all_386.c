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

char* removechar(char str[], int ch) {
  char *src, *dst;
  for (src = dst = str; *src != '\0'; src++) {
    *dst = *src;
    if (*dst != ch) {
      dst++;
    }
  }
  *dst = '\0';
  return str;
}

int main(int argc, char ** argv) {
  char * reds[max];
  int i;

  FILE * file = argc > 1 ? fopen(argv[1], "r") : stdin;
  if (file == NULL) {
    return 1;
  }

  if (argc != 2) {
    printf("[ERR]");
    return 0;
  }

  for (i = 0; i < max; i++) {
    reds[i] = malloc(stringlength);
    fgets(reds[i], stringlength, file);
    removechar(reds[i], ' '); // removes spaces
  }

  for (i = 0; i < max; i++) {
    printf("%s\n", reds[i]);
  }

  int success = 1;

  for (int i = 0; i < max; i++) {
    int found = 0;
    for (int j = 0; j < sizeof(stringcard) / sizeof(stringcard[0]); j++) {
      if (strcmp(stringcard[j], reds[i]) == 0) {
        found = 1;
        break;
      }
    }
    if (!found) {
      success = 0;
      printf("[ERR] String not found: %s\n", reds[i]);
      break;
    }
  }

  if (success) {
    printf("All elements present in input file.\n");
  }

  return 0;
}
