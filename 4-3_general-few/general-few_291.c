#include <stdio.h>
#include <regex.h>

int main() {
    char name[128];
    regex_t regex;
    int reti;

    reti = regcomp(&regex, "^[0-9a-zA-Z]*$", REG_EXTENDED);

    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 1;
    }

    if (scanf("%127s", name) != 1){
        printf("Invalid or no input.\n");
        return 1;
    }

    reti = regexec(&regex, name, 0, NULL, 0);

    if (!reti) {
        printf("Matched\n");
    } else {
        printf("Invalid\n");
    }

    regfree(&regex);

    return 0;
}
