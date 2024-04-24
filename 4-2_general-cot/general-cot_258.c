#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[] = "String1::String2:String3:String4::String5";
    char *deli = ":";
    char *token;
    char temp[100] = "";

    token = strtok(str, deli);
    printf("Token = \"%s", token);

    while ((token = strtok(NULL, deli)) != NULL) {
        if (strcmp(token, "") != 0 && strcmp(temp, "") != 0) {
            printf(":%s", token);
        } else {
            printf("\"\n");
            printf("Token = \"%s", token);
        }
    }
    printf("\"\n");

    return 0;
}
