#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void uppercase(char source[])
{
    int i;

    // Use < instead of <= to avoid accessing beyond the end of the string
    for (i = 0; i < strlen(source); ++i)
        if (source[i] >= 'a' && source[i] <= 'z')
            source[i] = source[i] - 'a' + 'A';
}

int main()
{
    // Allocate a modifiable array instead of using a string literal directly
    char str[] = "cold";
    uppercase(str);

    printf("Uppercased string: %s\n", str);

    return 0;
}
