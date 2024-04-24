#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int n, int *arr) {
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int findLevel(int **result, int n, int *target, int level) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        printArray(n, result[i]);
        bool isEqual = true;
        for (int j = 0; j < n; j++) {
            if (result[i][j] != target[j]) {
                isEqual = false;
                break;
            }
        }
        if (isEqual) {
            found = level;
            break;
        }
    }

    if (found > 0) {
        return found;
    }

    int **newResult = DoThis(n, *result);
    found = findLevel(newResult, n, target, level + 1);

    for (int i = 0; i < n; i++) {
        free(result[i]);
    }
    free(result);

    return found;
}

int main() {
    int a[] = {2, 3, 4, 1};
    int b[] = {1, 2, 4, 3};

    int n = sizeof(a) / sizeof(a[0]);
    int **result = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        result[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            result[i][j] = i + 1;
        }
    }

    int level = findLevel(result, n, b, 1);

    printf("Target array found at level: %d\n", level);

    return 0;
}
