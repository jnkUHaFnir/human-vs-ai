#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1000];
    int i, j;

    scanf("%s", str);  // input the string

    int found = 0;
    for (i = 0; i < strlen(str) && !found; i++)
    {
        for (j = i + 1; j < strlen(str); j++)
        {
            if (str[i] == str[j])  // compare
            {
                printf("%c", str[i]);
                found = 1;
                break; // exit the inner loop once a repeated character is found
            }
        }
    }

    return 0;
}
