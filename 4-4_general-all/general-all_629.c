#include <stdio.h>
#include <ctype.h>

int main() {
    char name[100];
    int check;

    do {
        check = 0;
        if (scanf("%99s", name) == 1) {
            for (int i = 0; name[i]; i++) {
                if (!isalpha(name[i])) {
                    printf("Invalid character. Please enter a valid name.\n");
                    check = 1;
                    break;
                }
            }
        } else {
            printf("Please enter a valid name.\n");
            // Clear input buffer
            while ((getchar()) != '\n');
        }
    } while (check == 1);

    // Convert all characters to lower case except the first letter
    for (int i = 1; name[i]; i++) {
        name[i] = tolower(name[i]);
    }
    // Convert the first letter to upper case
    name[0] = toupper(name[0]);

    printf("Formatted name: %s\n", name);

    return 0;
}
