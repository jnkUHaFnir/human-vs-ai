#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STOP "q"

int convertbinary(const char *binarynumber);

int main()
{
    char bnumber[10];

    printf("Enter binary byte or type q to quit:\n");

    while (fgets(bnumber, 10, stdin))
    {
        bnumber[strcspn(bnumber, "\n")] = 0;  // Remove the newline character
        
        if (strcmp(bnumber, STOP) == 0)
        {
            printf("Goodbye!\n");
            break; // Exit the loop if input is "q"
        }

        int binaryreturn = convertbinary(bnumber);
        printf("%d\n", binaryreturn);

        printf("Enter binary byte or type q to quit:\n");
    }

    return 0;
}

int convertbinary(const char *binarynumber)
{
    int val = 0;

    while (*binarynumber != '\0')
        val = 2 * val + (*binarynumber++ - '0');

    return val;
}
