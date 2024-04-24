#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100]; // Example size
    int check, i;

    do {
        check = 0;
        printf("Please enter your name: ");
        fgets(name, sizeof(name), stdin); // Use fgets instead of scanf for safety
        name[strcspn(name, "\n")] = 0; // Remove newline character if present

        for (i = 0; name[i] != '\0'; i++) {
            if (!isalpha((unsigned char)name[i])) { // Check for alphabetic characters
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while (check == 1);
    
    printf("Valid name entered: %s\n", name);

    return 0;
}
#include <string.h>
#include <ctype.h>

void capitalize(char *name) {
    if (name[0]) {
        name[0] = toupper((unsigned char)name[0]);
    }
    // Capitalize first letter of each word
    for (int i = 1; name[i] != '\0'; i++) {
        name[i] = tolower((unsigned char)name[i]);
        if (isalpha((unsigned char)name[i]) && isspace((unsigned char)name[i - 1])) {
            name[i] = toupper((unsigned char)name[i]);
        }
    }
}

// somewhere in your main function, after validation, you would call the capitalize function:
// capitalize(name);
