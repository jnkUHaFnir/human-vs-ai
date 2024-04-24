#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[50]; // Make sure to adjust the size based on your requirements
    int i, check;

    do {
        check = 0;
        printf("Enter your name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0; // Remove trailing newline character
        
        for (i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i])) {
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while (check != 0);

    // Convert to lower case except for the first letter
    for (i = 1; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }
    // Capitalize the first letter
    name[0] = toupper(name[0]);
    
    // Capitalize the first letter of each word
    for (i = 1; name[i] != '\0'; i++) {
        if (isspace(name[i - 1])) {
            name[i] = toupper(name[i]);
        }
    }

    printf("Processed name: %s\n", name);

    return 0;
}
