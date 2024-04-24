#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100]; // assuming a max length of 99 characters for the name
    int check, i;
    
    do {
        check = 0;
        printf("Please enter a valid name:\n");
        if (scanf("%99s", name) != 1) { // using %99s to prevent buffer overflow
            printf("Input error.\n");
            // Clearing the input buffer
            while (getchar() != '\n');
            continue;
        }
        
        for (i = 0; name[i] != '\0'; i++) {
            if (!isalpha((unsigned char)name[i])) {
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while (check == 1);
    // Convert to lowercase except the first character
    for (i = 1; name[i] != '\0'; i++) {
        name[i] = tolower((unsigned char)name[i]);
    }

    // Always capitalize the first letter
    if (name[0]) name[0] = toupper((unsigned char)name[0]);

    // Capitalize the first letter after any space
    for (i = 1; name[i] != '\0'; i++) {
        if (isspace((unsigned char)name[i - 1])) {
            name[i] = toupper((unsigned char)name[i]);
        }
    }

    printf("Formatted Name: %s\n", name);

    return 0;
}
