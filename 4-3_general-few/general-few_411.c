#include <stdio.h>
#include <ctype.h>

void shift(char *my_string); // Function declaration

int main()
{
    char inputstring[50];

    printf("Enter a string: ");
    fgets(inputstring, 50, stdin);
    shift(inputstring); // Function
    return 0;
}

void shift(char *my_string)
{
    char ch = my_string[0]; // Capture the first character

    for (int i = 0; my_string[i]; i++)
    {
        if (ch >= 'A' && ch <= 'Z') // When first char is uppercase
        {
            putchar(toupper(my_string[i]));
        }
        else if (ch >= 'a' && ch <= 'z') // When first char is lowercase
        {
            putchar(tolower(my_string[i]));
        }
    }
}
