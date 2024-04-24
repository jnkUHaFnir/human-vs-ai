#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100]; // Assuming maximum input length is 100 characters
    int i, check;

    do {
        check = 0;
        
        printf("Enter username: ");
        if (scanf("%99s", name) != 1) {
            scanf("%*[^\n]"); // Clear input buffer
            printf("Invalid input. Please enter a valid username.\n");
            continue;
        }

        for (i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i])) {
                printf("Invalid character. Please enter a valid username.\n");
                check = 1;
                break;
            }
        }
    } while (check != 0);

    // Convert username to lowercase except for first letter
    for (i = 1; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }
    // Convert first letter to uppercase
    name[0] = toupper(name[0]);

    printf("Processed username: %s\n", name);

    return 0;
}
