#include <stdio.h>
#include <regex.h>
#include <stdbool.h>

bool validate_name(char *name) {
    regex_t regex;
    int ret;

    ret = regcomp(&regex, "^[0-9a-zA-Z]+$", REG_EXTENDED);
    if (ret) {
        fprintf(stderr, "Could not compile regex\n");
        return false;
    }

    ret = regexec(&regex, name, 0, NULL, 0);
    regfree(&regex);

    if (!ret) {
        return true;
    } else if (ret == REG_NOMATCH) {
        return false;
    } else {
        fprintf(stderr, "Regex match failed\n");
        return false;
    }
}

int main() {
    char name[128];
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    if (validate_name(name)) {
        printf("Matched\n");
    } else {
        printf("Invalid\n");
    }

    return 0;
}
