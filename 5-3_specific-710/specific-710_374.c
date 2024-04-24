#include <stdio.h>
#include <stdlib.h>

#define FAIL -1

int main() {
    int *pSet = NULL;
    int i = 0, c;
    
    printf("Please enter a stream of numbers to make a set out of them: \n");

    while (scanf("%d", &c) == 1) {
        pSet = (int*) realloc(pSet, sizeof(int)*(i+1));
        if (pSet == NULL) {
            return FAIL;
        }

        pSet[i] = c;
        i++;
        printf("%d ", c);
    }

    // Print the numbers stored in the array
    printf("\nNumbers stored in the array: ");
    for (int j = 0; j < i; j++) {
        printf("%d ", pSet[j]);
    }
    printf("\n");

    free(pSet);

    return 0;
}
