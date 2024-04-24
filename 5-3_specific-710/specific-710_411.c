#include <stdio.h>
#include <ctype.h>

void shift(char *my_string); // Function declaration

int main()
{
    char inputstring[50];

    printf("Enter a string: ");
    scanf(" %49[^\n]", inputstring); // Read up to 49 characters until newline

    shift(inputstring); // Call the function

    return 0;
}

void shift(char *my_string)
{
    if (*my_string >= 'A' && *my_string <= 'Z') // If first char is uppercase
    {
        putchar(toupper(*my_string)); // Print uppercase first character

        for (int i = 1; my_string[i]; i++)
        {
            putchar(toupper(my_string[i])); // Print rest of the string in uppercase
        }
    }
    else if (*my_string >= 'a' && *my_string <= 'z') // If first char is lowercase
    {
        putchar(tolower(*my_string)); // Print lowercase first character

        for (int i = 1; my_string[i]; i++)
        {
            putchar(tolower(my_string[i])); // Print rest of the string in lowercase
        }
    }
}
