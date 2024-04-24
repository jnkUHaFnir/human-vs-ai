#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[50];
    int i, check;

    // Validate input for valid characters
    do {
        if (scanf("%49[A-Za-z ]", name) == 1) {
            check = 0;
            for (i = 0; i < strlen(name); i++) {
                if (!isalpha(name[i]) && name[i] != ' ') {
                    printf("Invalid character. Please enter a valid name.\n");
                    check = 1;
                    break;
                }
            }
        } else {
            printf("Please enter a valid name.\n");
            // Clear input buffer
            scanf("%*s");
            check = 1;
        }
    } while (check);

    // Convert to lowercase and capitalize first letter
    name[0] = toupper(name[0]);
    for (i = 1; name[i]; i++) {
        name[i] = tolower(name[i]);
        if (name[i - 1] == ' ') {
            name[i] = toupper(name[i]);
        }
    }

    printf("Valid name: %s\n", name);

    return 0;
}
