#include <stdio.h>
#include <stdlib.h>

int isSameArray(int n, int arr1[], int arr2[]) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // Arrays are different
        }
    }
    return 1; // Arrays are the same
}

int performOperation(int n, int arr[], int level, int original[], int **output) {
    if (isSameArray(n, arr, original)) {
        return level;
    }

    int *copy = malloc(n * sizeof(*copy));
    for (int i = 0; i < n; i++) {
        copy[i] = arr[i];
    }

    int nextLevel = level + 1;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int t = copy[i];
        copy[i] = copy[j];
        copy[j] = t;

        output[nextLevel-1] = copy;

        int result = performOperation(n, copy, nextLevel, original, output);
        if (result != -1) {
            return result;
        }

        // Reset copy back to original state for the next iteration
        t = copy[i];
        copy[i] = copy[j];
        copy[j] = t;
    }

    free(copy);

    return -1; // Not found at this level
}

int main() {
    int a[] = {2,3,4,1};
    int b[] = {1,2,4,3};

    int n = sizeof(a) / sizeof(a[0]);
    int **result = malloc(n * sizeof(*result));
    int level = performOperation(n, a, 1, b, result);

    if (level != -1) {
        printf("Found at level: %d\n", level);
    } else {
        printf("Input array not found\n");
    }

    for (int i = 0; i < level; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
