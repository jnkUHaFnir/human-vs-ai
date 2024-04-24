#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define STOP "q"

int convertbinary(char *binarynumber);


int main()
{
    int binaryreturn;
    char *bnumber;
    int len;
    bnumber = (char *)malloc(10 * sizeof(char *));

    printf("Enter binary byte or type q to quit:?\n");

    while (fgets(bnumber, 10, stdin) != NULL)
    {
        len = strlen(bnumber);
        if (bnumber[len - 1] == '\n')
        {
            bnumber[len - 1] = 0;
        }
        else
        {
            //blank line
        }

        if (strcmp(bnumber, STOP) == 0) // Check if bnumber is equal to STOP
        {
            break; // Terminate the loop
        }

        binaryreturn = convertbinary(bnumber);
        printf("%d\n", binaryreturn);
        printf("Enter binary byte or type q to quit:?\n");
    }

    printf("Goodbye!\n"); // Print "Goodbye!" before finishing the program

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
Enter binary byte or type q to quit:?
111
7
Enter binary byte or type q to quit:?
q
Goodbye!
