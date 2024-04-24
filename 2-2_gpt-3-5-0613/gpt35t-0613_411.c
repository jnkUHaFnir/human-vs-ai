#include <stdio.h>
#include <ctype.h>

void shift (char *my_string);

int main()
{
  char inputstring[50];

  printf("Enter a string\n");
  fgets(inputstring, 50, stdin); // Get one line of input

  shift(inputstring);

  return 0;
}

void shift (char *my_string)
{
  int i = 0;
  char ch = my_string[0]; // Get the first character

  while(my_string[i])
  {
    if(ch >= 'A' && ch <= 'Z') // When first char is uppercase
    {
      putchar(toupper(my_string[i]));
      i++;
    }
    else if (ch >= 'a' && ch <= 'z') // When first char is lowercase
    {
      putchar(tolower(my_string[i]));
      i++;
    }
  }
}
