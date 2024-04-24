#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convertBinary(const char *binaryNumber);

int main() {
    char bnumber[10];
    int binaryReturn;

    printf("Enter binary byte or type q to quit:\n");

    while (fgets(bnumber, sizeof(bnumber), stdin) != NULL) {
        if (strlen(bnumber) > 1 && bnumber[0] == 'q') {
            printf("Goodbye!\n");
            break;
        }

        binaryReturn = convertBinary(bnumber);
        printf("%d\n", binaryReturn);
        printf("Enter binary byte or type q to quit:\n");
    }

    return 0;
}

int convertBinary(const char *binaryNumber) {
    int val = 0;

    while (*binaryNumber != '\0') {
        if (*binaryNumber != '0' && *binaryNumber != '1') {
            fprintf(stderr, "Error: Non-binary input detected.\n");
            return 0; // Return 0 for invalid input
        }

        val = 2 * val + (*binaryNumber++ - '0');
    }

    return val;
}
