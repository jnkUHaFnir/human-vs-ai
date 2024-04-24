#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[50]; // Adjust the size as needed

    int check = 0;
    do {
        check = 0;
        scanf("%49s", name); // Read up to 49 characters to avoid buffer overflow
        for (size_t i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i])) {
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while (check == 1);

    // Convert all characters to lower case except the first letter
    for (size_t i = 1; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }
    
    // Convert the first letter to uppercase
    name[0] = toupper(name[0]);
    
    // Capitalize the first letter of each word
    for (size_t i = 1; name[i]; i++) {
        if (name[i - 1] == ' ') {
            name[i] = toupper(name[i]);
        }
    }

    printf("Modified name: %s\n", name);

    return 0;
}
