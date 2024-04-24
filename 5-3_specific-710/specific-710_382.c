#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convertbinary(const char *binarynumber);

int main()
{
    char input[10];
    int decimal;

    printf("Enter binary byte or type q to quit:\n");

    while (fgets(input, sizeof(input), stdin) != NULL && strncmp(input, "q", 1) != 0)
    {
        // Check if the input is empty or only a newline character
        if (input[0] == '\n')
        {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        // Strip newline character if present
        input[strcspn(input, "\n")] = 0;

        decimal = convertbinary(input);
        printf("%d\n", decimal);

        printf("Enter binary byte or type q to quit:\n");
    }

    return 0;
}

int convertbinary(const char *binarynumber)
{
    int val = 0;

    while (*binarynumber != '\0')
    {
        val = 2 * val + (*binarynumber - '0');
        binarynumber++;
    }

    return val;
}
