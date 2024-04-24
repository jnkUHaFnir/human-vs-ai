#include <stdio.h>
#include <stdlib.h>

int compareArrays(int n, int *arr1, int *arr2) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // Arrays are not equal
        }
    }
    return 1; // Arrays are equal
}

void generateOutput(int n, int *arr) {
    int **result = DoThis(n, arr);
    int *desiredArray = {1, 2, 4, 3};

    for (int i = 0; i < n; i++) {
        if (compareArrays(n, result[i], desiredArray)) {
            printf("Desired array found at level: %d\n", 2);
            return;
        } else {
            generateOutput(n, result[i]);
        }
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(result[i]);
    }
    free(result);
}

int main() {
    int a[] = {2, 3, 4, 1};
    int n = sizeof(a) / sizeof(a[0]);
    
    generateOutput(n, a);

    return 0;
}
