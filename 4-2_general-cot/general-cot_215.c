#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char name[100];
    int i, validInput;
    do {
        validInput = 1; // Assume input is valid
        printf("Enter your name: ");
        if (scanf("%99s", name) != 1) {
            printf("Invalid input format. Please enter a valid name.\n");
            scanf("%*s"); // Clear the input buffer
            validInput = 0;
            continue;
        }
        
        for (i = 0; name[i] != '\0'; i++) {
            if (!isalpha(name[i])) {
                printf("Invalid character. Please enter a valid name.\n");
                validInput = 0;
                break;
            }
        }
    } while (!validInput);
    
    // Convert input to lowercase
    for (i = 0; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }
    
    // Capitalize the first letter of the name
    name[0] = toupper(name[0]);
    
    printf("Valid username: %s\n", name);
    
    return 0;
}
