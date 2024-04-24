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

  char * reds[max];

  int i;

  FILE * file = argc > 1 ? fopen(argv[1], "r") : stdin;
  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  if (argc != 2) {
    printf("Usage: %s input_file\n", argv[0]);
    return 0;
  }

  for (i = 0; i < max; i++) {
    reds[i] = malloc(stringlength);
    fgets(reds[i], stringlength, file);
  }

  for (i = 0; i < max; i++) {
    removechar(reds[i], ' ');
  }

  for (i = 0; i < max; i++) {
    printf("%s", reds[i]);
  }

  int success = 1;
  size_t size = sizeof(stringcard)/sizeof(stringcard[0]); 
  size_t size2 = 0;

  for (i = 0; i < max; i++) {
    for (int j = 0; j < size; j++) {
      if(strcmp(stringcard[j], reds[i]) == 0) {
        size2++;
        break;
      }
    }
  }

  if (size2 != size) {
    success = 0;
  }

  if (success) {
    printf("All elements from stringcard are present in reds.\n");
  } else {
    printf("Not all elements from stringcard are present in reds.\n");
  }

  return 0;
}
