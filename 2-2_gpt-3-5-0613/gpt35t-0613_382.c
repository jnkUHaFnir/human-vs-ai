#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STOP "q\n"

int convertBinary(char *binaryNumber);

int main()
{
    char input[10];

    printf("Enter binary byte or type q to quit:\n");

    while (fgets(input, sizeof(input), stdin))
    {
        if (strcmp(input, STOP) == 0)
        {
            printf("Goodbye!\n");
            break;
        }

        int binaryReturn = convertBinary(input);
        printf("%d\n", binaryReturn);

        printf("Enter binary byte or type q to quit:\n");
    }

    return 0;
}

int convertBinary(char *binaryNumber)
{
    int val = 0;

    while (*binaryNumber != '\0')
    {
        val = 2 * val + (*binaryNumber++ - '0');
    }

    return val;
}
