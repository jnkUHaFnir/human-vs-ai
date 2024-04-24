#include <stdio.h>
#include <ctype.h>

int main() {
    char name[100]; // assuming max length of name is 99 characters
    int validInput = 0;

    do {
        if (scanf("%99s", name) == 1) { // %99s to avoid buffer overflow
            int i;
            for (i = 0; name[i] != '\0'; i++) {
                if (!isalpha(name[i])) {
                    printf("Invalid character. Please enter a valid name.\n");
                    validInput = 0;
                    break;
                }
                validInput = 1;
            }
        } else {
            printf("Please enter a valid name.\n");
            scanf("%*[^\n]"); // Clear input buffer
        }
    } while (!validInput);

    // Convert input to lower case (except first letter) and capitalize first letter
    name[0] = toupper(name[0]);
    for (int i = 1; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }

    printf("Formatted name: %s\n", name);

    return 0;
}
