#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int **DoThis(int n, int arr[n], int *returnSize);
bool arraysEqual(int *a, int *b, int n);
int recursiveDoThis(int n, int arr[n], int target[], int currentLevel);

int main() {
    int a[] = {2, 3, 4, 1};
    int b[] = {1, 2, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);

    int levelReached = recursiveDoThis(n, a, b, 1);
    printf("Level reached: %d\n", levelReached);

    return 0;
}

// Recursive wrapper for DoThis to find the desired result
int recursiveDoThis(int n, int arr[n], int target[], int currentLevel) {
    int returnSize = 0;
    int **results = DoThis(n, arr, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        if (arraysEqual(results[i], target, n)) {
            // Freeing allocated memory
            for(int j = 0; j < returnSize; j++) {
                free(results[j]);
            }
            free(results);
            return currentLevel;
        }
        int deeperLevel = recursiveDoThis(n, results[i], target, currentLevel + 1);
        // If result is found in deeper levels, return that level
        if (deeperLevel != 0) {
            // Free allocated memory before returning
            for(int j = 0; j < returnSize; j++) {
                free(results[j]);
            }
            free(results);
            return deeperLevel;
        }
    }
    
    // Freeing allocated memory
    for (int i = 0; i < returnSize; i++) {
        free(results[i]);
    }
    free(results);

    // If the target array is not found, return 0
    return 0;
}

// Original DoThis function with minor modifications
int **DoThis(int n, int arr[n], int *returnSize) {
    *returnSize = n;
    int **b = malloc(n * sizeof(*b));
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int *copy = malloc(n * sizeof(*copy));
        for (int k = 0; k < n; k++) {
            copy[k] = arr[k];
        }
        int t = copy[i];
        copy[i] = copy[j];
        copy[j] = t;
        b[i] = copy;
    }
    return b;
}

// Utility function to check if two arrays are equal
bool arraysEqual(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}
