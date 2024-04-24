#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "String1::String2:String3:String4::String5";
    char *deli = ":";
    char *token = strtok(str, deli);
    char *prev_token = NULL;

    while (token != NULL)
    {
        if (prev_token != NULL && strlen(prev_token) > 0 && prev_token[strlen(prev_token)-1] == ':')
        {
            // concatenate the current token to the previous token if the previous token ends with ':'
            strcat(prev_token, token);
            printf("Token= \"%s\"\n", prev_token);
        }
        else
        {
            printf("Token= \"%s\"\n", token);
            prev_token = token;
        }
        token = strtok(NULL, deli);
    }

    return 0;
}
