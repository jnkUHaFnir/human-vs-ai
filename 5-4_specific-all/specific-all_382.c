#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int convertbinary(const char *binarynumber);

int main()
{
    char input[10]; // Fixed size input buffer
    int binaryreturn;

    printf("Enter binary byte or type q to quit:\n");

    while (1)
    {
        // Read the input from the user
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            fprintf(stderr, "Error reading input.\n");
            return 1;
        }

        // Remove newline character if present
        input[strcspn(input, "\n")] = '\0';

        // Check if the input is "q" to quit
        if (strcmp(input, "q") == 0)
        {
            printf("Goodbye!\n");
            break; // Exit the loop
        }

        binaryreturn = convertbinary(input);
        printf("%d\n", binaryreturn);
        printf("Enter binary byte or type q to quit:\n");
    }

    return 0;
}

int convertbinary(const char *binarynumber)
{
    int val = 0;

    while (*binarynumber != '\0')
    {
        if (*binarynumber != '0' && *binarynumber != '1')
        {
            fprintf(stderr, "Invalid binary input\n");
            return -1; // Indicate error
        }
        val = 2 * val + (*binarynumber++ - '0');
    }

    return val;
}
