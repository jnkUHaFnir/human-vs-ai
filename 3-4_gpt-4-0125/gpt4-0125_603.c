#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100]; // Assuming a max name length of 99 characters.
    int check, i;

    do {
        printf("Please enter a valid name:\n");
        fgets(name, sizeof(name), stdin); // Use fgets to allow for spaces.
        name[strcspn(name, "\n")] = 0; // Removing the trailing newline character.
        
        check = 0;
        for (i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i]) && name[i] != ' ') { // Allowing spaces as well.
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while (check == 1);

    // Further processing...
    
    return 0;
}
// Assuming the validation is done, and 'name' is validated.
name[0] = toupper(name[0]);
for (i = 1; name[i] != '\0'; i++) {
    name[i] = tolower(name[i]);
    if (name[i-1] == ' ')
        name[i] = toupper(name[i]);
}
