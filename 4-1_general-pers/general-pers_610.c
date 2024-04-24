#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[] = "1sure";
    char input[15];

    do
    {
        printf("Password: ");
        if (scanf("%14s", input) != 1) {
            printf("No input detected.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }

        // Check if the input is empty or consists of spaces
        int isValidInput = 0;
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isspace(input[i])) {
                isValidInput = 1;
                break;
            }
        }

        if (!isValidInput) {
            printf("No input detected.\n");
            continue;
        }

        if (strcmp(password, input) == 0)
        {
            printf("Password accepted.\n");
            return 0;
        }
        else
        {
            printf("Invalid password.\n");
            continue;
        }
    }
    while (1);

    return 0;
}
