#include <stdio.h>
#include <stdlib.h>

#define FAIL -1

int main() {
    int *pSet = NULL;
    int i = 0;
    int c;

    printf("Please enter a stream of numbers to make a set out of them: ");
    printf("\n");

    while(scanf("%d", &c) == 1) {  // Check the return value of scanf directly
        pSet = (int*)realloc(pSet, sizeof(int)*(i+1));
        if(pSet == NULL) {
            return FAIL;
        }
        pSet[i] = c;
        printf("%d ", c);
        i++;
    }

    // Print the elements of the array
    printf("\nScanned numbers into the array only once: ");
    for(int j = 0; j < i; j++) {
        printf("%d ", pSet[j]);
    }
    printf("\n");

    free(pSet);

    return 0;
}
