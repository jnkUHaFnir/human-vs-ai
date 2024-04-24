#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    
    scanf("%s", str); // input the string
    
    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = i + 1; j < strlen(str); j++)
        {
            if (str[i] == str[j]) // compare
            {
                printf("%c\n", str[i]);
                return 0; // Exit the program after printing the first repeating character
            }
        }
    }
    
    return 0;
}
