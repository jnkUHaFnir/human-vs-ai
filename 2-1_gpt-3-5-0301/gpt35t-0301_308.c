#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE *fp = fopen("file.txt", "r");
  char found[100];
  const char fetch[11] = "learning";

  while(fgets(found, 100, fp))
  {
    if(strstr(found, fetch))
    {
      printf("Your result: %s", found);

      sscanf(found, "%*s %[^\n]", found);
      printf("Your result is: %s\n", found);

      break;
    }
  }

  fclose(fp);

  return 0;
}