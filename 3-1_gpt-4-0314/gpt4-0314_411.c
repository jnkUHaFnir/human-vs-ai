#include <stdio.h>
#include <ctype.h>
void shift (char *my_string); // Function declaration

int main()
{
  char inputstring[50];

  printf("Enter a string\n");
  fgets(inputstring, 50, stdin);
  shift(inputstring); // Function
  return 0;
}

void shift (char *my_string) // Function definition
{
  int i = 0;
  char ch = my_string[0];
  int is_upper = (ch >= 'A' && ch <= 'Z'); // Determine if the first character is uppercase

  while(my_string[i])
  {
    if (is_upper) // If the first character is uppercase, make the rest uppercase
    {
      putchar(toupper(my_string[i]));
    }
    else // If the first character is lowercase, make the rest lowercase
    {
      putchar(tolower(my_string[i]));
    }
    
    i++;
  }
  printf("\n"); // Adding a line break after the output
  return;
}
