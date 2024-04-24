#include <stdio.h>
#include <string.h>

int main() {
    char password[] = "1sure";
    char input[15];

    do {
        printf("Password: ");
        scanf("%14s", input); // Limit scanf to read up to 14 characters to avoid buffer overflow

        if (strcmp(password, input) == 0) {
            printf("Password accepted.\n");
            return 0;
        }
        else if (strlen(input) == 0) { // Check if input string is empty
            printf("No input detected.\n");
            continue;
        }
        else {
            printf("\nInvalid password.\n");
            continue;
        }
    } while (1);

    return 0;
}
