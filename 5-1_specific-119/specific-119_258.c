#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "String1::String2:String3:String4::String5";
    char *deli = "::";
    char *start = str;
    char *end;

    while ((end = strstr(start, deli)) != NULL) {
        *end = '\0';
        printf("Token = \"%s\"\n", start);
        start = end + strlen(deli);
    }

    if (strlen(start) > 0) {
        printf("Token = \"%s\"\n", start);
    }

    return 0;
}
