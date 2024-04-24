#include <stdio.h>
#include <string.h>

void uppercase(char source[])
{
    int i;

    for(i = 0; i < strlen(source); ++i)
    {
        if (source[i] >= 'a' && source[i] <= 'z')
        {
            source[i] = source[i] - 'a' + 'A';
        }
    }

    printf("%s", source);
}

int main()
{
    char str[] = "cold";
    uppercase(str);

    return 0;
}
