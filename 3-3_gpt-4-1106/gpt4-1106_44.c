#include <stdio.h>
#include <string.h>
int main(void)
{
  char *s = "ABC";
  printf("%s\n",s);
  sprintf(s,"DEF");
  printf("%s\n",s); 
  return 0;
}
#include <stdio.h>
#include <string.h>
int main(void)
{
  char s[4]; // allocate space for 4 characters (including the null-terminator)
  strcpy(s, "ABC"); // copy the string into the allocated space
  printf("%s\n", s);
  sprintf(s, "DEF"); // now it's safe to overwrite the string
  printf("%s\n", s); 
  return 0;
}
