#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10

int convertbinary(char *binarynumber);

int main()
{
    int binaryreturn;
    char bnumber[MAX_LEN];

    printf("Enter binary byte or type q to quit:\n");

    while (fgets(bnumber, sizeof(bnumber), stdin) != NULL)
    {
        if (strcmp(bnumber, "q\n") == 0) {
            printf("Goodbye!\n");
            break;
        }

        int len = strlen(bnumber);

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
