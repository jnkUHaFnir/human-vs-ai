#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "String1::String2:String3:String4::String5";
    char *deli = ":";
    char *token = strtok(str, deli);
    char *lastToken = NULL;

    while(token != NULL) {
        // Check for consecutive delimiters
        if(lastToken != NULL && *lastToken == '\0' && *token == '\0') {
            printf("%s%s", deli, token);
        } else {
            printf("Token= \"%s\"\n", token);
        }
        lastToken = token;
        token = strtok(NULL, deli);
    }

    return 0;
}
Token="String1"
Token="String2:String3:String4"
Token="String5"
