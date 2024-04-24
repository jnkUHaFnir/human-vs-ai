#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  FILE * fp = fopen("file.txt","r");
  char string[100];
  char found[100];
  const char fetch[11] = "learning";

  while(fgets(string, 100, fp))
  {
    if(strstr(string, fetch) != NULL) {
        strcpy(found, string);
        printf("Your result: %s", found);
        break; // Stop after finding the first occurrence
    }
  }

  if(strstr(found, fetch) != NULL){
    printf("Your result is: %s", found);
  } else {
    printf("Word 'learning' not found in any sentence.");
  }

  fclose(fp);
  return 0;
}
