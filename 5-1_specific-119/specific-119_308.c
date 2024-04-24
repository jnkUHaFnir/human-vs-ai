#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  FILE *fp = fopen("file.txt", "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  
  char string[100];
  char *found = NULL;
  const char fetch[] = "learning";

  while(fgets(string, 100, fp))
  {
    printf("Your result: %s", string);

    found = strstr(string, fetch);
    if (found != NULL) {
      printf("Your result is: %s", found);
      break;
    }
  }

  fclose(fp);

  return 0;
}
