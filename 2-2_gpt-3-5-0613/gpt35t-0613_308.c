#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE * fp = fopen("file.txt","r");
  char string[100];
  const char fetch[11] = "learning";

  while(fgets(string, 100, fp))
  {
    if(strstr(string, fetch))
    {
      printf("Your result: %s", string);
      break;
    }
  }

  fclose(fp);
  return 0;
}
