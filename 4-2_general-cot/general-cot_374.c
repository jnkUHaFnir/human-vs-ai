#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pSet = NULL;
    int i = 0;
    int c;

    printf("Please enter a stream of numbers to make a set out of them: ");
    printf("\n");

    while (scanf("%d", &c) == 1) {
        pSet = (int *)realloc(pSet, sizeof(int) * (i + 1));
        if (pSet == NULL) {
            return 1; // or any suitable error code
        }
        pSet[i] = c;
        i++;
        printf("%d ", c);
    }

    // Print the array elements
    printf("\nArray elements: ");
    for (int j = 0; j < i; j++) {
        printf("%d ", pSet[j]);
    }

    // Free dynamically allocated memory
    free(pSet);

    return 0;
}
