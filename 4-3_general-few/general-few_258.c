#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "String1::String2:String3:String4::String5";
    char *deli = "::";

    char *token;
    char *remainder = str;

    while ((token = strtok(remainder, deli)) != NULL) {
        remainder = NULL; // To continue from the last position
        printf("Token = \"%s\"\n", token);

        char *nextToken = strtok(remainder, deli);
        if (nextToken != NULL) {
            printf("Token = \"%s:%s\"\n", nextToken, strtok(NULL, ""));
        }
    }

    return 0;
}
