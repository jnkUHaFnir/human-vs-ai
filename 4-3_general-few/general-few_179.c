#include <stdio.h>
#include <stdlib.h>

int **DoThis(int n, int arr[n]){
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
        b[i] = copy;
    }
    return b;
}

// Recursive function to find the target output
int findTargetOutput(int n, int arr[n], int level, int target[], int targetLen) {
    int found = 0;

    int **output = DoThis(n, arr);

    for (int i = 0; i < n; i++) {
        int match = 1;
        for (int j = 0; j < n; j++) {
            if (output[i][j] != target[j]) {
                match = 0;
                break;
            }
        }

        if (match == 1) {
            found = level;
            break;
        }

        if (!found) {
            found = findTargetOutput(n, output[i], level + 1, target, targetLen);
        }

        free(output[i]);
    }

    free(output);

    return found;
}

int main() {
    int a[] = {2, 3, 4, 1};
    int b[] = {1, 2, 4, 3};
    int target[] = {1, 2, 4, 3};
    int targetLen = sizeof(target) / sizeof(target[0]);

    int level = findTargetOutput(4, a, 1, target, targetLen);

    printf("Output found at level: %d\n", level);

    return 0;
}
