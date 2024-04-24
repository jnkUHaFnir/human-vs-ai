#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100];
    int i, x, check;

    do {
        check = 0;
        scanf("%s", name);
        for (i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i])) {
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while (check != 0);

    // Convert to lowercase except the first letter
    for (i = 1; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }
    // Capitalize the first letter
    name[0] = toupper(name[0]);

    // Capitalize first letters after whitespace
    for (x = 1; name[x] != '\0'; x++) {
        if (name[x - 1] == ' ' || name[x - 1] == '\t') {
            name[x] = toupper(name[x]);
        }
    }

    printf("Processed name: %s\n", name);

    return 0;
}
