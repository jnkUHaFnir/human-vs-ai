#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100];
    int i, x;
    int check;

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

    // Convert to lowercase and set the first letter to uppercase
    for (i = 1; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }
    name[0] = toupper(name[0]);
    x = 1;
    while (name[x] != '\0') {
        if (name[x - 1] == ' ') {
            name[x] = toupper(name[x]);
        }
        x++;
    }

    printf("Formatted name: %s\n", name);

    return 0;
}
