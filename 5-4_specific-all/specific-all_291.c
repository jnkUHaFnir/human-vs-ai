#include <stdio.h>
#include <regex.h>

int main() {
    char name[128];
    regex_t regex;
    int reti;

    // Compile the regular expression pattern
    reti = regcomp(&regex, "^[0-9a-zA-Z]*$", 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 1;
    }

    // Get user input
    printf("Enter input: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }

    // Remove newline character at the end
    name[strcspn(name, "\n")] = 0;

    // Execute the regular expression
    reti = regexec(&regex, name, 0, NULL, 0);
    if (!reti) {
        printf("Valid input\n");
    } else {
        printf("Invalid input\n");
    }

    regfree(&regex); // Free the memory used by the regular expression
    return 0;
}
