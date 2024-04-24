#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define STOP "q"

int convertbinary(char *binarynumber);

int main() {
    int binaryreturn; 
    char bnumber[10]; // Use a fixed-size char array instead of dynamic memory allocation for simplicity

    while (1) { // Infinite loop that will only break upon entering 'q'
        printf("Enter binary byte or type q to quit:\n");
        if (fgets(bnumber, 10, stdin)) {
            // Remove newline char if exists
            bnumber[strcspn(bnumber, "\n")] = 0;

            // Check if the input is 'q'
            if (strcmp(bnumber, STOP) == 0) {
                printf("Goodbye!\n");
                break;
            }

            binaryreturn = convertbinary(bnumber);
            printf("%d\n", binaryreturn); 
        } else {
            // Handle error or EOF
            printf("Error reading input or End Of File reached.\n");
            break;
        }
    }

    return 0; 
}

int convertbinary(char *binarynumber) {
    int val = 0;

    while (*binarynumber != '\0') {
        val = 2 * val + (*binarynumber++ - '0');
    }

    return val;
}
