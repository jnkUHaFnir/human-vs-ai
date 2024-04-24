#include <stdio.h>
#include <regex.h>

int main() {
    char name[128];

    // Define the regular expression pattern
    char pattern[] = "^[0-9a-zA-Z]+$";

    // Compile the regular expression
    regex_t regex;
    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        printf("Error compiling regular expression\n");
        return 0;
    }

    // Read user input
    if (fgets(name, sizeof(name), stdin) != NULL) {
        // Remove the trailing newline character from the input
        if (name[strlen(name) - 1] == '\n') {
            name[strlen(name) - 1] = '\0';
        }

        // Check if the input matches the regular expression
        if (regexec(&regex, name, 0, NULL, 0) == REG_NOMATCH) {
            printf("Invalid\n");
        } else {
            printf("Matched\n");
        }
    }

    // Free the memory used by the regular expression
    regfree(&regex);

    return 0;
}
