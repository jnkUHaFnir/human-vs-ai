#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char name[50];
    int i, check;

    do {
        check = 0;
        printf("Enter your name: ");
        scanf("%s", name);
        for (i = 0; i < strlen(name); i++) {
            if (isalpha(name[i]) == 0) {
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while (check == 1);

    // all to lower except the first letter
    for (i = 1; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }

    // first letter to upper
    name[0] = toupper(name[0]);

    printf("Formatted name: %s\n", name);

    return 0;
}
