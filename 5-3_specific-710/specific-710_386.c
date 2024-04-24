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
  char * cpos = str;
  while ((cpos = strchr(cpos, ch))) {
    strcpy(cpos, cpos + 1);
  }
  return str;
}

int main(int argc, char ** argv) {
  char reds[max][stringlength]; // Changed to 2D array
  
  int i;
  
  FILE * file = argc > 1 ? fopen(argv[1], "r") : stdin;
  if (file == NULL)
    return 1;
  if (argc != 2) {
    printf("[ERR]");
    return 0;
  }

  for (i = 0; i < max; i++) {
    fgets(reds[i], stringlength, file);
  }

  for (i = 0; i < max; i++) {
    printf("%s", reds[i]);
  }

  // removes spaces
  for (i = 0; i < max; i++) {
    removechar(reds[i], ' ');
  }

  for (i = 0; i < max; i++) {
    printf("%s", reds[i]);
  }

  int success = 1;
  int found;
  
  for (int j = 0; j < sizeof(stringcard) / sizeof(stringcard[0]); j++) {
    found = 0; // Reset found flag for each iteration
    for (i = 0; i < max; i++) {
      if (strcmp(stringcard[j], reds[i]) == 0) { // Compare stringcard element with reds element
        found = 1;
        break;
      }
    }
    if (found == 0) { // If not found, set success to 0
      success = 0;
      break;
    }
  }

  if (success) {
    printf("All elements of stringcard are present in reds.\n");
  } else {
    printf("Not all elements of stringcard are present in reds.\n");
  }

  return 0;
}
