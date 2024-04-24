#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int convertbinary(char *binarynumber);

int main()
{
    char bnumber[10]; // declare array instead of dynamically allocating memory
    int binaryreturn;

    printf("Enter binary byte or type q to quit:?\n");

    while (1)
    {
        fgets(bnumber, 10, stdin); // read input from user
        if (bnumber[0] == 'q' && (strlen(bnumber) == 2 || (strlen(bnumber) == 3 && bnumber[1] == '\n'))) // check for 'q' followed by newline
        {
            printf("Goodbye!\n");
            break; // exit the loop
        }

        // convert the input to decimal
        binaryreturn = convertbinary(bnumber);
        printf("%d\n", binaryreturn);
        printf("Enter binary byte or type q to quit:?\n");
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
