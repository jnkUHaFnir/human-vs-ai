#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 100

int main(){

  FILE *fp = fopen("file.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  char string[MAX_STRING_SIZE] = {0}; // Initialize the array
  char found[MAX_STRING_SIZE];

  const char fetch[] = "learning";

  while (fgets(string, MAX_STRING_SIZE, fp))
  {
    strncpy(found, string, sizeof(found)-1); // Ensure null-termination

    printf("Your result: %s", found);

    char *result = strstr(found, fetch);

    if (result != NULL) {
      printf("Your result is: %s", result);
      break;
    }
  }

  fclose(fp);
  return 0;
}
