#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAIL 1

int main() {
    int *pSet = NULL;
    int i = 0;
    int c;

    printf("Please enter a stream of numbers to make a set out of them: \n");

    do {
        if (scanf("%d", &c) != 1) {
            break; // Exit the loop if scanf fails to read an integer
        }
        
        pSet = (int*) realloc(pSet, sizeof(int) * (i + 1));
        if (pSet == NULL) {
            return FAIL;        
        }
        
        pSet[i] = c;
        printf("%d ", c);
        i++;
    } while (1);

    // Print the array contents
    printf("\nArray contents: ");
    for (int j = 0; j < i; j++) {
        printf("%d ", pSet[j]);
    }

    // Free dynamically allocated memory
    free(pSet);

    return SUCCESS;
}
