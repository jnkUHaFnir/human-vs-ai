#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char name[100]; // Assuming the maximum length for the name

    // Checking for valid alphabetic characters
    int check;
    do {
        check = 0;
        printf("Enter a name: ");
        scanf("%s", name);
        for (int i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i])) {
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while (check != 0);

    // Converting input format
    name[0] = toupper(name[0]); // Capitalize the first letter

    for (int i = 1; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]); // Convert to lowercase
        if (name[i - 1] == ' ') {
            name[i] = toupper(name[i]); // Capitalize after a space
        }
    }

    printf("Formatted name: %s\n", name);

    return 0;
}
