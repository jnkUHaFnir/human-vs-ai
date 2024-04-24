#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "One:1:Two::Three::::";
    char *deli = ":";
    char *token = strtok(str, deli);

    while (token != NULL) {
        if (strcmp(token, "") != 0) {
            printf("Token = \"%s\"\n", token);
        } else {
            printf("\"\n");
        }
        token = strtok(NULL, deli);
    }

    return 0;
}
