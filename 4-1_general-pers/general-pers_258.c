#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str[] = "String1::String2:String3:String4::String5";
    char *deli = "::";
    char *token;
    char *rest = str;
    
    while ((token = strtok_r(rest, deli, &rest))) {
        if (rest != NULL) {
            printf("Token=\"%s:%s\"\n", token, rest);
        } else {
            printf("Token=\"%s\"\n", token);
        }
    }
    
    return 0;
}
