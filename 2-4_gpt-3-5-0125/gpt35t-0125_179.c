#include <stdio.h>
#include <stdlib.h>

int **DoThis(int n, int arr[n], int target[n], int level);

int main() {
    int a[] = { 2, 3, 4, 1 };
    int b[] = { 1, 2, 4, 3 };
    
    int target[] = { 1, 2, 4, 3 };
    
    int **result = DoThis(4, a, target, 0);
    
    int i = 0;
    while (result[i] != NULL) {
        for (int j = 0; j < 4; j++) {
            printf("%d, ", result[i][j]);
        }
        printf("\n");
        i++;
    }
    
    return 0;
}

int **DoThis(int n, int arr[n], int target[n], int level) {
    int l = n;
    int **b = malloc(l * sizeof(*b));
    int i, j, k;
    
    for (i = 0; i < l; i++) {
        j = (i + 1) % l;
        int *copy = malloc(l * sizeof(*copy));
        for (k = 0; k < l; k++)
            copy[k] = arr[k];
        int t = copy[i];
        copy[i] = copy[j];
        copy[j] = t;
        
        if (level + 1 < n) {
            b[i] = DoThis(n, copy, target, level + 1);
        } else {
            b[i] = NULL;
            if (memcmp(copy, target, n * sizeof(int)) == 0) {
                printf("Found target at level %d\n", level + 1);
            }
        }
    }
    
    return b;
}
