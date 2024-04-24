#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* uppercase(const char source[])
{
    int length = strlen(source);
    char* result = (char*)malloc(length + 1);

    for (int i = 0; i < length; ++i)
    {
        if (source[i] >= 'a' && source[i] <= 'z')
        {
            result[i] = source[i] - 'a' + 'A';
        }
        else
        {
            result[i] = source[i];
        }
    }
    result[length] = '\0';  // Add null terminator to the end of the string
    return result;
}

int main()
{
    const char* input = "cold";
    char* result = uppercase(input);
    printf("%s\n", result);
    free(result);  // Free the allocated memory
    return 0;
}
