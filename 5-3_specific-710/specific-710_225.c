#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

// Function to remove unwanted characters from a string
void sanitizeString(char *str) {
    regex_t regex;
    regcomp(&regex, "[^a-zA-Z0-9 ]", REG_EXTENDED);

    regoff_t offset = 0;
    regmatch_t match;

    while (regexec(&regex, str + offset, 1, &match, 0) == 0) {
        for (regoff_t i = offset + match.rm_so; i < offset + match.rm_eo; i++) {
            str[i] = ' '; // Replace unwanted character with space
        }
        offset += match.rm_eo; // Move the offset to the end of the match
    }

    regfree(&regex);
}

int main() {
    char data[] = "This is some\n 123 example data!@# with special characters.";

    printf("Before sanitization:\n%s\n", data);

    sanitizeString(data);

    printf("\nAfter sanitization:\n%s\n", data);

    return 0;
}
