#include <stdio.h>
#include <ctype.h>

void shift(char *my_string); // Function declaration

int main()
{
  char inputstring[50];
  
  printf("Enter a string: ");
  fgets(inputstring, 50, stdin);
  
  shift(inputstring); // Function call
  
  return 0;
}

void shift(char *my_string) // Function definition
{
  if (my_string[0] >= 'A' && my_string[0] <= 'Z') // When first char is uppercase
  {
    for (int i = 0; my_string[i] != '\0'; i++)
    {
      putchar(toupper(my_string[i]));
    }
  }
  else if (my_string[0] >= 'a' && my_string[0] <= 'z') // When first char is lowercase
  {
    for (int i = 0; my_string[i] != '\0'; i++)
    {
      putchar(tolower(my_string[i]));
    }
  }
}
