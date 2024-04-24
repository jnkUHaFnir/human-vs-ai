#include <string.h>
#include <stdio.h>

int main(void)
{
    char str[] = "String1::String2:String3:String4::String5";
    char *deli = "::";
    char *token;
    char *saveptr;

    token = strtok_r(str, deli, &saveptr);
    while (token != NULL)
    {
        printf("Token= \"%s\"\n", token);
        token = strtok_r(NULL, deli, &saveptr);
    }

    return 0;
}
