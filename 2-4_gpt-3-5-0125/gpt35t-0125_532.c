#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j;
    char str[1000];
    int found = 0;

    scanf("%s", str); //input the string
    for (i = 0; i < strlen(str) && !found; i++)
    {
        for (j = i + 1; j < strlen(str) && !found; j++)
        {
            if (str[i] == str[j]) //compare
            {
                printf("%c\n", str[i]);
                found = 1; // set flag to stop the loop
            }
        }
    }

    if (!found)
    {
        printf("No repeated characters found.\n");
    }

    return 0;
}
