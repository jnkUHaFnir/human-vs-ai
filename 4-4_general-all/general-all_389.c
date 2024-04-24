#include <stdio.h>
#include <string.h>

void uppercase(char source[])
{
    for (int i = 0; i < strlen(source); ++i)
    {
        if (source[i] >= 'a' && source[i] <= 'z')
        {
            source[i] = source[i] - 'a' + 'A';
        }
    }
}

int main()
{
    char input[] = "cold";
    uppercase(input);
    printf("%s\n", input);

    return 0;
}
