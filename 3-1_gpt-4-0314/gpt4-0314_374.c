#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pSet = (int*) malloc(sizeof(int));
    int i = 0;
    int c, res;

    printf("Please enter a stream of numbers to make a set out of them: ");
    printf("\n");

    while ((res = scanf("%d", &c)) == 1) {
        pSet = (int *) realloc(pSet, sizeof(int) * (i + 1));

        if (pSet == NULL) {
            return -1;
        }

        pSet[i] = c;
        i++;
    }

    printf("The scanned numbers are: ");
    for (int j = 0; j < i; j++) {
        printf("%d ", pSet[j]);
    }
    printf("\n");

    free(pSet);
    return 0;
}
