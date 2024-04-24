#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  FILE * fp = fopen("file.txt","r");
  char string[100]; // Changed to non-const to allow modification
  char found[100];
  char *result;
  const char fetch[] = "learning"; // Removed fixed size, automatically determined

  if(fp == NULL){
    printf("Error opening file.\n");
    return 1;
  }

  while(fgets(string, 100, fp))
  {
    // Ensure null-termination after reading the string
    string[strcspn(string, "\n")] = '\0'; 

    printf("Your result: %s\n", string);

    result = strstr(string, fetch);
    if(result != NULL) {
        printf("Found '%s' in the line.\n", fetch);
    }   
  }

  fclose(fp);
  return 0;
}
