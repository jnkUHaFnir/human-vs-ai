#include <stdio.h>
#include <stdlib.h>

int compareArrays(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int findLevel(int n, int arr[n], int **output, int *input, int level) {
    for (int i = 0; i < n; i++) {
        if (compareArrays(output[i], input, n)) {
            return level;
        }
    }

    int **newOutput = DoThis(n, input);

    int result = findLevel(n, arr, newOutput, input, level + 1);

    for (int i = 0; i < n; i++) {
        free(newOutput[i]);
    }
    free(newOutput);

    return result;
}

int main() {
    int a[] = {2, 3, 4, 1};
    int b[] = {1, 2, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);

    int **output = DoThis(n, a);

    int level = findLevel(n, a, output, b, 1);

    printf("Level: %d\n", level);

    for (int i = 0; i < n; i++) {
        free(output[i]);
    }
    free(output);

    return 0;
}
