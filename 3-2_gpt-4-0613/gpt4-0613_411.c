#include <stdio.h>
#include <ctype.h>
void shift (char *my_string);

int main()
{
  char inputstring[50];

  printf("Enter a string\n");
  fgets(inputstring, 50, stdin); // Read the string
  shift(inputstring);
  return 0;
}

void shift (char *my_string)
{
  char ch = my_string[0];
  int i = 0;

  while(my_string[i] != '\0' && i < 50) // Ensures that we will not overflow the string
  {
    if(isupper(ch)) // When first char is uppercase
    {
      putchar(toupper(my_string[i]));
    }
    else if (islower(ch)) // When first char is lowercase
    {
      putchar(tolower(my_string[i]));
    }
    else // If first char is not a letter, just print it as it is
    {
      putchar(my_string[i]);
    }
    i++;
  }
  printf("\n");
  return;
}
