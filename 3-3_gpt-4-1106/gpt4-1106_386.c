#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

#define MAX 13
#define STRING_LENGTH 16

const char *stringcard[] = {
  "RED A",
  "RED 2",
  "RED 3",
  "RED 4",
  "RED 5",
  "RED 6",
  "RED 7",
  "RED 8",
  "RED 9",
  "RED 10",
  "RED J",
  "RED Q",
  "RED K",
};

char * removechar(char str[], int ch) {
  char * cpos = str;
  while ((cpos = strchr(cpos, ch))) {
    strcpy(cpos, cpos + 1);
  }
  return str;
}

int main(int argc, char ** argv) {
  char * reds[MAX];
  int i;

  if (argc != 2) {
    printf("[ERR] Usage: %s <input_file>\n", argv[0]);
    return 1;
  }

  FILE * file = fopen(argv[1], "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  for (i = 0; i < MAX; i++) {
    reds[i] = malloc(STRING_LENGTH);
    if (fgets(reds[i], STRING_LENGTH, file) == NULL) {
      break; // Stop if there are less than MAX lines in the file
    }
    // Remove newline character if it's there
    reds[i][strcspn(reds[i], "\n")] = 0; 
  }

  fclose(file);

  // Check if `reds` contains all elements of `stringcard`
  int cardFound;
  for (i = 0; i < MAX; i++) {
    cardFound = 0;
    for (int j = 0; j < MAX; j++) {
      if (strcmp(stringcard[i], reds[j]) == 0) {
        cardFound = 1;
        break;
      }
    }
    if (!cardFound) {
      printf("\"%s\" not found in input file.\n", stringcard[i]);
      // Free allocated memory
      for (int k = 0; k <= i; k++) free(reds[k]);
      return 1;
    }
  }

  printf("All stringcard elements found in input file.\n");

  // Free allocated memory
  for (i = 0; i < MAX; i++) {
    free(reds[i]);
  }

  return 0;
}
