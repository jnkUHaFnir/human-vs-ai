#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convertbinary(char *binarynumber);

int main()
{
    char bnumber[10];
    int binaryreturn;
    
    printf("Enter binary byte or type q to quit:\n");

    while (fgets(bnumber, sizeof(bnumber), stdin) != NULL)
    {
        if (strcmp(bnumber, "q\n") == 0) {
            printf("Goodbye!\n");
            break;
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
    
    while (*binarynumber != '\n' && *binarynumber != '\0')
    {
        val = 2 * val + (*binarynumber++ - '0');
    }
    
    return val;
}
