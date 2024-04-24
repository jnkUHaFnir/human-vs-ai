#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STOP "q"

int convertbinary(char *binarynumber);

int main()
{
    int binaryreturn;
    char *bnumber;
    int len;

    bnumber = (char *)malloc(10 * sizeof(char));

    printf("Enter binary byte or type q to quit:\n");

    while (1)
    {
        fgets(bnumber, 10, stdin);
        // Remove newline character
        len = strlen(bnumber);
        if (bnumber[len - 1] == '\n')
        {
            bnumber[len - 1] = '\0';
        }

        if (strcmp(bnumber, STOP) == 0)
        {
            printf("Goodbye!\n");
            break;
        }

        binaryreturn = convertbinary(bnumber);
        printf("%d\n", binaryreturn);
        printf("Enter binary byte or type q to quit:\n");
    }

    free(bnumber);

    return 0;
}

int convertbinary(char *binarynumber)
{
    int val = 0;

    while (*binarynumber != '\0')
        val = 2 * val + (*binarynumber++ - '0');

    return val;
}
