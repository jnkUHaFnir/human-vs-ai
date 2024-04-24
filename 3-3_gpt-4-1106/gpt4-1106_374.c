#include <stdio.h>
#include <stdlib.h>

#define FAIL -1

int main() {
    int *pSet = malloc(sizeof(int)); // Do not cast the result of malloc in C.
    if (pSet == NULL) {
        return FAIL;
    }
    
    int i = 0; // Start index at 0
    printf("Please enter a stream of numbers to make a set out of them (press enter after each number and enter 'end' to finish): \n");

    // Variable to hold the result of scanf read
    int scanResult;
    
    while (1) {
        scanResult = scanf("%d", &pSet[i]); // Read next integer
        if (scanResult == EOF || scanResult == 0) {
            // If EOF or read fails, break from the loop
            break;
        }
        printf("%d ", pSet[i]); // Print read value
        i++;
        int *newpSet = realloc(pSet, sizeof(int) * (i + 1)); // Allocate space for one more integer
        if (newpSet == NULL) {
            free(pSet);
            return FAIL;
        }
        pSet = newpSet;
    }
    
    // Print array content for verification
    printf("\nContent of the set:\n");
    for (int j = 0; j < i; j++) {
        printf("%d ", pSet[j]);
    }
    printf("\n");

    free(pSet);
    return 0;
}
