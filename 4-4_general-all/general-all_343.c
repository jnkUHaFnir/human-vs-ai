#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100];
    int i, x;
    int check;

    do {
        check = 0;
        printf("Enter your name: ");
        scanf("%s", name);

        for (i = 0; i < strlen(name); i++) {
            // Check if the character is alphabetic
            if (!isalpha(name[i])) {
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while (check);

    // Convert all characters to lowercase
    for (i = 0; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }

    // Convert the first letter of each word to uppercase
    x = 0;
    while (name[x] != '\0') {
        if (x == 0 || name[x - 1] == ' ') {
            name[x] = toupper(name[x]);
        }
        x++;
    }

    printf("Formatted name: %s\n", name);

    return 0;
}
