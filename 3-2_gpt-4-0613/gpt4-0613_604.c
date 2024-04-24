#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace_str(char *str, char *orig, char *rep)
{
  char *result; 
  char *ins;   
  char *tmp;   
  int len_rep;  
  int len_orig; 
  int len_front; 
  int count;    

  if (!orig)
    return NULL;
  len_orig = strlen(orig);
  if (len_orig == 0)
    return NULL; 
  if (!rep)
    rep = "";
  len_rep = strlen(rep);

  ins = str;
  for (count = 0; (tmp = strstr(ins, orig)); ++count)
    ins = tmp + len_orig;

  tmp = result = malloc(strlen(str) + (len_rep - len_orig) * count + 1);

  if (!result)
    return NULL;

  while (count--)
  {
    ins = strstr(str, orig);
    len_front = ins - str;
    tmp = strncpy(tmp, str, len_front) + len_front;
    tmp = strcpy(tmp, rep) + len_rep;
    str += len_front + len_orig; 
  }
  strcpy(tmp, str);
  return result;
}

int main(void)
{
  char *str = "Hello world, cruel world";
  char *orig = "world";
  char *rep = "Earth";
  
  char *result = replace_str(str, orig, rep);

  if(result) {
    printf("%s\n", result);
    free(result);
  }
}
