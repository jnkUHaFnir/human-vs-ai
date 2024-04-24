#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[100];
    char reverse[100];

    int numLen = 0;

    printf("Enter a number\n");
    fgets(input, 100, stdin);
    printf("The number is: %s\n", input);

    numLen = strlen(input) - 1;
    printf("Length of string is: %d\n", numLen);

    for (int i = 0; i < numLen; i++)
    {
        reverse[i] = input[numLen - 1 - i];
    }
    reverse[numLen] = '\0'; // null-terminate the reversed string

    printf("The reverse number is: %s\n", reverse);
    printf("The original number is: %s\n", input);

    int result = strcmp(input, reverse);
    printf("Result of strcmp gives us: %d\n", result);

    if (strcmp(input, reverse) == 0)
    {
        printf("These numbers are palindromes\n");
    }
    else
    {
        printf("These numbers are not palindromes\n");
    }

    return 0;
}
