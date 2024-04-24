#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  FILE * fp = fopen("file.txt","r");
  char string[100];
  char found[100];
  char *result;
  char fetch[11] = "learning";

  if(!fp){
     printf("Unable to open file\n");
     return 1; 
  }

  while(fgets(string, sizeof(string), fp))
  {
    strcpy(found, string);
    printf("Your input: %s", found);

    result = strstr(found, fetch);
    if(result){
        printf("Your result is: %.10s\n",result);
    }
    else
    {
        printf("No match found\n");
    }
  }
  fclose(fp);
  return 0;
}
printf("Your keyword is: %s\n", fetch);
result = strstr(found, fetch);
if(result){
  result += strlen(fetch);
  printf("Your result is: %s", result);
}
else{
  printf("Fetch string '%s' not found in the read data", fetch);
}
