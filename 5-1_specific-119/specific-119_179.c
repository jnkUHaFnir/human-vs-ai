#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

bool compareArrays(int *arr1, int *arr2, int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
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

int findLevel(int n, int arr[n], int m, int **target, int level) {
    int **result = DoThis(n, arr);
    for (int i = 0; i < n; i++) {
        if (compareArrays(result[i], target, n)) {
            return level;
        }
    }
    for (int i = 0; i < n; i++) {
        int foundLevel = findLevel(n, result[i], m, target, level + 1);
        if (foundLevel != -1) {
            return foundLevel;
        }
    }
    return -1;
}

int main() {
    int a[] = {2, 3, 4, 1};
    int b[] = {1, 2, 4, 3};

    int **target = malloc(4 * sizeof(*target));
    for (int i = 0; i < 4; i++) {
        target[i] = malloc(4 * sizeof(int));
        for (int j = 0; j < 4; j++) {
            target[i][j] = b[j];
        }
    }

    int level = findLevel(4, a, 4, target, 1);
    printf("Target array found at level: %d\n", level);

    for (int i = 0; i < 4; i++) {
        free(target[i]);
    }
    free(target);

    return 0;
}
