#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  FILE * fp = fopen("file.txt","r");
  char string[100];
  char *result;
  const char fetch[] = "learning";

  while(fgets(string, 100, fp))
  {
    char *token = strtok(string, " ");
    while(token != NULL){
      if(strstr(token, fetch) != NULL){
        printf("Your result: %s", string);
        break;
      }
      token = strtok(NULL, " ");
    }
  }

  fclose(fp);
  return 0;
}
