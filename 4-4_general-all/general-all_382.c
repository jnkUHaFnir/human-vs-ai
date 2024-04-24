#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STOP "q"

int convertbinary(char *binarynumber);

int main()
{
    int binaryreturn;
    char bnumber[10]; // Changed from pointer to array
    int len;

    printf("Enter binary byte or type q to quit:\n");

    while (fgets(bnumber, 10, stdin))
    {
        if (strcmp(bnumber, STOP) == 0) // Compare input with quit condition
        {
            printf("Goodbye!\n");
            break;
        }

        len = strlen(bnumber);
        if (bnumber[len - 1] == '\n')
        {
            bnumber[len - 1] = '\0';
        }

        binaryreturn = convertbinary(bnumber);
        printf("%d\n", binaryreturn);
        printf("Enter binary byte or type q to quit:\n");
    }

    return 0;
}

int convertbinary(char *binarynumber)
{
    int val = 0;

    while (*binarynumber != '\0')
        val = 2 * val + (*binarynumber++ - '0');

    return val;
}
