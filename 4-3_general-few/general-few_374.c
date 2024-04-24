#include <stdio.h>
#include <stdlib.h>

#define FAIL -1

int main() {
    int *pSet = NULL;
    int i = 0;
    int c;

    pSet = (int*)malloc(sizeof(int));
    if(pSet == NULL) {
        return FAIL;
    }

    printf("Please enter a stream of numbers to make a set out of them: \n");

    while (scanf("%d", &c) == 1) {
        pSet[i] = c;
        printf("%d ", c);

        i++;
        pSet = (int*)realloc(pSet, sizeof(int) * (i + 1));
        if(pSet == NULL) {
            return FAIL;
        }
    }

    printf("\n");

    for(int j = 0; j < i; j++) {
        printf("%d ", pSet[j]);
    }

    free(pSet);

    return 0;
}
