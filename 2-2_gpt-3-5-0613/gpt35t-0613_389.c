#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void uppercase(char *source)
{
    int i;
    int length = strlen(source);
    
    for(i = 0; i < length; ++i)
    {
        if (source[i] >= 'a' && source[i] <= 'z')
            source[i] = source[i] - 'a' + 'A';
    }
}

int main()
{
    char str[] = "cold";
    uppercase(str);
    printf("%s\n", str);  // Output: COLD

    return 0;
}
