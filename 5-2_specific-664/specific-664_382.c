#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10

int convertbinary(const char *binarynumber);

int main()
{
    char input[MAX_LENGTH];
    int binaryreturn;
    
    while (1) {
        printf("Enter binary byte or type q to quit: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Exit if input fails
        }
        
        if (input[0] == 'q' && (input[1] == '\n' || input[1] == '\0')) {
            printf("Goodbye!\n");
            break; // Exit upon q input
        }

        input[strcspn(input, "\n")] = 0; // Remove newline character
        
        binaryreturn = convertbinary(input);
        printf("%d\n", binaryreturn); 
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
