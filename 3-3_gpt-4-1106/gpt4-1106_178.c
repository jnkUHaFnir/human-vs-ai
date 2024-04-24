#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool arraysEqual(int *a, int *b, int length) {
    for (int i = 0; i < length; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int **DoThis(int n, int arr[n]){
    int **b = malloc(n * sizeof(*b));
    for (int i = 0; i < n; i++) {
        int *copy = malloc(n * sizeof(*copy));
        for (int k = 0; k < n; k++)
            copy[k] = arr[k];
        int t = copy[i];
        copy[i] = copy[(i + 1) % n];
        copy[(i + 1) % n] = t;
        b[i] = copy;
    }
    return b;
}

int findPermutationLevel(int n, int arr[n], int target[n], int currentLevel) {
    int **perms = DoThis(n, arr);
    for (int i = 0; i < n; i++) {
        if (arraysEqual(perms[i], target, n)) {
            // Clean up memory before returning
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    free(perms[j]);
                }
            }
            free(perms);
            return currentLevel;
        }
    }
    int level = -1;
    for (int i = 0; i < n; i++) {
        level = findPermutationLevel(n, perms[i], target, currentLevel + 1);
        if (level != -1) {
            break;
        }
    }
    // Clean up memory
    for (int i = 0; i < n; i++) {
        free(perms[i]);
    }
    free(perms);
    return level;
}

int main() {
    int a[] = {2, 3, 4, 1};
    int b[] = {1, 2, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    int level = findPermutationLevel(n, a, b, 1); // We start counting levels at 1
    printf("Level found: %d\n", level);
    return 0;
}
