#include <stdio.h>
#include <ctype.h>

void shift(char *my_string);

int main()
{
    char inputstring[50];

    printf("Enter a string: ");
    fgets(inputstring, 50, stdin);

    shift(inputstring);

    return 0;
}

void shift(char *my_string)
{
    int i = 0;
    char ch = my_string[0]; // Get the first character from the input string

    if(ch >= 'A' && ch <= 'Z') // Check if the first character is uppercase
    {
        while(my_string[i])
        {
            putchar(toupper(my_string[i])); // Convert to uppercase and print
            i++;
        }
    }
    else if(ch >= 'a' && ch <= 'z') // Check if the first character is lowercase
    {
        while(my_string[i])
        {
            putchar(tolower(my_string[i])); // Convert to lowercase and print
            i++;
        }
    }
}
