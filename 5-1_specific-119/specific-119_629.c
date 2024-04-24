#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_alpha_string(const char *str) {
    while (*str) {
        if (!isalpha(*str)) {
            return 0; // Not a valid alphabetic character
        }
        str++;
    }
    return 1; // All characters are alphabetic
}

void format_name(char *name) {
    int i;
    int capitalize_next = 1;

    for (i = 0; name[i]; i++) {
        if (capitalize_next && isalpha(name[i])) {
            name[i] = toupper(name[i]);
            capitalize_next = 0;
        } else {
            name[i] = tolower(name[i]);
        }

        if (name[i] == ' ') {
            capitalize_next = 1;
        }
    }
}

int main() {
    char name[100];

    do {
        printf("Enter your name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0; // Remove the newline character if present

        if (!is_alpha_string(name)) {
            printf("Invalid characters detected. Please enter a valid name.\n");
        }
    } while (!is_alpha_string(name));

    format_name(name);

    printf("Formatted name: %s\n", name);

    return 0;
}
