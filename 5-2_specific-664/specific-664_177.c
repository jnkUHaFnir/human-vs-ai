#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int **DoThis(int n, int arr[n]);
bool CheckOutput(int n, int **output, int *targetArr, int level, int depth);

int main() {
    int a[] = {2, 3, 4, 1};
    int b[] = {1, 2, 4, 3};
    int **result = DoThis(4, a);

    int target[] = {1, 2, 4, 3};

    int level = 1;
    while (!CheckOutput(4, result, target, level, 1)) {
        result = DoThis(4, *result);
        level++;
    }

    printf("Target found at level: %d\n", level);

    // Free memory
    for (int i = 0; i < 4; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}

int **DoThis(int n, int arr[n]) {
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

bool CheckOutput(int n, int **output, int *targetArr, int level, int depth) {
    if (depth > level) {
        for (int i = 0; i < n; i++) {
            int match = 1;
            for (int j = 0; j < n; j++) {
                if (output[i][j] != targetArr[j]) {
                    match = 0;
                    break;
                }
            }
            if (match) return true;
        }
        return false;
    } else {
        return CheckOutput(n, output, targetArr, level, depth + 1);
    }
}
