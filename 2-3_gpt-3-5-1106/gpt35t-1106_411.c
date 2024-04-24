#include <stdio.h>
#include <ctype.h>

void shift (char *my_string); // Function declaration

int main()
{
  char inputstring[50];

  printf("Enter a string: ");
  fgets(inputstring, 50, stdin); // Get input string
  shift(inputstring); // Call the shift function
}

void shift (char *my_string) // Function definition
{
  char ch = my_string[0]; // Get the first character of the input string

  if (ch >= 'A' && ch <= 'Z') // When first char is uppercase
  {
    for (int i = 0; my_string[i]; i++)
    {
      putchar(toupper(my_string[i])); // Convert and print each character to uppercase
    }
  }
  else if (ch >= 'a' && ch <= 'z') // When first char is lowercase
  {
    for (int i = 0; my_string[i]; i++)
    {
      putchar(tolower(my_string[i])); // Convert and print each character to lowercase
    }
  }
}
