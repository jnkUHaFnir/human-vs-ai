#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100];
    int i, check, x;

    do {
        check = 0;
        printf("Enter your name: ");
        scanf("%s", name);
        
        for (i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i])) {
                check = 1;
                printf("Invalid character. Please enter a valid name.\n");
                break;
            }
        }
    } while (check);

    // Convert all characters to lowercase except the first one
    for (i = 1; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }
    
    // Capitalize the first letter
    name[0] = toupper(name[0]);

    // Capitalize the first letter after a space
    for (x = 1; name[x] != '\0'; x++) {
        if (name[x - 1] == ' ') {
            name[x] = toupper(name[x]);
        }
    }

    printf("Formatted Name: %s\n", name);

    return 0;
}
