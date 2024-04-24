#include <stdio.h>
#include <regex.h>

int main() {
    char name[128];
    
    regex_t regex;
    int reti;

    // Compile the regular expression pattern
    reti = regcomp(&regex, "^[0-9a-zA-Z]+$", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 1;
    }

    // Get user input
    if (scanf("%127[^\n]", name) != 1) {
        printf("Input error\n");
        return 1;
    }

    // Match the input against the regular expression
    reti = regexec(&regex, name, 0, NULL, 0);
    if (!reti) {
        printf("Matched\n");
    } else if (reti == REG_NOMATCH) {
        printf("Invalid\n");
    } else {
        char error_message[100];
        regerror(reti, &regex, error_message, sizeof(error_message));
        fprintf(stderr, "Regex match failed: %s\n", error_message);
        return 1;
    }

    // Free the compiled regular expression
    regfree(&regex);

    return 0;
}
