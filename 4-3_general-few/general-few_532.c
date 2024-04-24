#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1000];
    
    scanf("%s",str); // input the string

    for(size_t i = 0; i < strlen(str); i++)
    {
        for(size_t j = i + 1; j < strlen(str); j++)
        {
            if(str[i] == str[j]) // compare
            {
                printf("%c\n", str[i]);
                return 0; // exit the program after printing the first repeated character
            }
        }
    }

    printf("No repeated characters found.\n");
    return 0;
}
