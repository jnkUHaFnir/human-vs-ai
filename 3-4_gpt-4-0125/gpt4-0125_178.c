#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int **DoThis(int n, int arr[n], int *returnSize){
    int l = n;
    *returnSize = l;  // To keep track of the number of combinations generated.
    int **b = malloc(l * sizeof(*b)); // sizeof(*b) : sizeof(int *)
    int i, j, k;
    for (i = 0; i < l; i++) {
        j = (i + 1) % l;
        int *copy = malloc(l * sizeof(*copy)); // sizeof(int)
        for (k = 0; k < l; k++)
            copy[k] = arr[k];
        int t = copy[i];
        copy[i] = copy[j];
        copy[j] = t;
        b[i] = copy;
    }
    return b;
}

bool areArraysEqual(int n, int a[n], int b[n]) {
    for (int i = 0; i < n; i++)
        if (a[i] != b[i]) return false;
    return true;
}

int findSequenceLevels(int n, int arr[n], int target[n]) {
    int level = 1, returnSize, i, j;
    bool found = false;

    int **current = DoThis(n, arr, &returnSize);
    // Check if the target is immediately found in the first iteration.
    for (i = 0; i < returnSize; i++) {
        if (areArraysEqual(n, current[i], target)) {
            found = true;
            break;
        }
    }

    // Free the allocated memory as it is no longer needed.
    for (i = 0; i < returnSize; i++) {
        free(current[i]);
    }
    free(current);

    if (found) return level;

    int **next, nextSize;
    int *queue = malloc(n * sizeof(*queue));

    // Iteratively check at each level.
    while (!found) {
        level++;
        next = DoThis(n, arr, &nextSize);
        for (i = 0; i < nextSize; i++) {
            int **temp = DoThis(n, next[i], &returnSize);
            for (j = 0; j < returnSize; j++) {
                if (areArraysEqual(n, temp[j], target)) {
                    found = true;
                    break;
                }
            }
            for (int k = 0; k < returnSize; k++) {
                free(temp[k]);
            }
            free(temp);
            if (found) break;
        }
        // Free memory for next to avoid leaks.
        for (i = 0; i < nextSize; i++) {
            free(next[i]);
        }
        free(next);
        if (found) break;
    }

    free(queue);
    return level;
}

int main() {
    int a[] = {2, 3, 4, 1};
    int b[] = {1, 2, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);

    int level = findSequenceLevels(n, a, b);
    
    printf("Found at level: %d\n", level);
    
    return 0;
}
