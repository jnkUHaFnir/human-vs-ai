#include <stdio.h>
#include <stdlib.h>

#define FAIL -1

int main() {
    int *pSet = NULL;
    int i = 0;
    int c = 0;

    printf("Please enter a stream of numbers to make a set out of them: \n");

    while (scanf("%d", &c) == 1) {
        pSet = (int*) realloc(pSet, sizeof(int) * (i + 1));
        if (pSet == NULL) {
            // Handle memory allocation failure
            return FAIL;
        }
        pSet[i] = c;
        printf("%d ", c);
        i++;
    }

    // Print the scanned numbers
    printf("\nThe numbers scanned into the array are: ");
    for (int j = 0; j < i; j++) {
        printf("%d ", pSet[j]);
    }
    
    // Free dynamically allocated memory
    free(pSet);

    return 0;
}
