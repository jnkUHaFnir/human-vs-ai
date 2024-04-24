#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  FILE *fp = fopen("file.txt","r");
  if(fp == NULL){
    printf("Could not open file.\n");
    return 1;
  }

  char string[100];
  char found[100];
  const char fetch[] = "learning";

  while(fgets(string, sizeof(string), fp) != NULL)
  {
    size_t len = strlen(string);
    if (len > 0 && string[len-1] == '\n') {
      string[len-1] = '\0'; // Remove newline character if present
    }

    strcpy(found, string);
    printf("Your original line: %s\n", found);

    char *result = strstr(found, fetch);
    if(result != NULL) {
      printf("Found '%s' in the line: %s\n", fetch, found);
      // You can break here if you only want to find the word once in the file
    }
  }

  fclose(fp);
  return 0;
}
