#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char name[100];
    int i, check;

    do {
        check = 0;
        if (scanf("%99s", name) != 1) {
            printf("Error reading input. Please enter a valid name.\n");
            while (fgetc(stdin) != '\n'); // clear input buffer
            continue;
        }

        for (i = 0; name[i]; i++) {
            if (!isalpha(name[i])) {
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while (check);

    // Convert all characters to lowercase except the first character
    for (i = 1; name[i]; i++) {
        name[i] = tolower(name[i]);
    }

    // Capitalize the first character
    name[0] = toupper(name[0]);

    // Print the formatted name
    printf("Formatted name: %s\n", name);

    return 0;
}
