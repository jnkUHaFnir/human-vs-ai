#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main() {
    char name[50];
    int i, check;

    do {
        check = 0;
        fgets(name, sizeof(name), stdin); // More suitable than scanf for reading string input
        name[strcspn(name, "\n")] = 0; // Remove any newline character
        
        for (i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i]) && !isspace(name[i])) {
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while (check == 1);


    // Converting all input letters (after verification) to proper case
    for (i = 1; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }
    name[0] = toupper(name[0]);
    
    int x = 1;
    while (name[x] != '\0') {
        if (name[x - 1] == ' ')
            name[x] = toupper(name[x]);
        x++;
    }

    printf("Valid name: %s\n", name);

    return 0;
}
