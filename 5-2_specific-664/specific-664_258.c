#include <string.h>
#include <stdio.h>

int main(void)
{
    char str[] = "One:1:Two::Three::::";
    char *deli = ":";

    char *token = strtok(str, deli);
    char *prev_token = NULL;

    while (token != NULL)
    {
        if (strcmp(token, "") == 0 && prev_token != NULL && strcmp(prev_token, "") == 0)
        {
            // Merge consecutive empty tokens
            prev_token = token;
        }
        else
        {
            if (prev_token != NULL && strcmp(prev_token, "") != 0)
            {
                printf("%s:", prev_token);
            }
            prev_token = token;
        }

        token = strtok(NULL, deli);
    }

    if (prev_token != NULL && strcmp(prev_token, "") != 0)
    {
        printf("%s\n", prev_token);
    }

    return 0;
}
