#include <stdio.h>
#include <string.h>

void toUpper(char *str)
{
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') { // Use character literals ('a' and 'z') for clarity
            str[i] = (char)(str[i] - 32); // Convert lowercase to uppercase
        }
    }
}

int main()
{
    char string[20];

    printf("Enter any string:\n");
    scanf("%19s", string); // Limit input to fit in the string buffer

    toUpper(string); // Call the toUpper function directly on the string

    printf("The string in upper case is: %s\n", string);

    return 0;
}
