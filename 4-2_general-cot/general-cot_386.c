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

int main(int argc, char **argv) {
  char reds[max][stringlength]; // Change: Using 2D array for fixed size strings

  int i;

  FILE *file = argc > 1 ? fopen(argv[1], "r") : stdin;
  if (file == NULL)
    return 1;
  if (argc != 2) {
    printf("[ERR]");
    return 0;
  }

  for (i = 0; i < max; i++) {
    fgets(reds[i], stringlength, file);
  }

  // removes spaces
  for (i = 0; i < max; i++) {
    removechar(reds[i], ' ');
  }

  for (i = 0; i < max; i++) {
    printf("%s", reds[i]);
  }

  int success = 1;

  for(int i = 0; i < max; i++) {
    int found = 0;
    for(int j = 0; j < max; j++) {
      if(strcmp(stringcard[i], reds[j]) == 0) {
        found = 1;
        break;
      }
    }
    if(!found) {
      success = 0;
      break;
    }
  }

  if(success) {
    printf("All elements in the reds array match the elements in stringcard array.\n");
  } else {
    printf("Arrays do not match.\n");
  }

  return 0;
}
