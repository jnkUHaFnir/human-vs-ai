#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[50];
    int i, check;

    do {
        check = 0;
        printf("Enter name: ");
        scanf("%49[^\n]%*c", name); // Read up to 49 characters until newline
        for (i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i])) {
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while (check == 1);

    // Convert to lower case
    for (i = 0; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }

    // Capitalize first letter
    name[0] = toupper(name[0]);

    int x = 1;
    while(name[x] != '\0') {
        if (name[x - 1] == ' ') {
            name[x] = toupper(name[x]);
        }
        x++;
    }

    printf("Formatted name: %s\n", name);

    return 0;
}
