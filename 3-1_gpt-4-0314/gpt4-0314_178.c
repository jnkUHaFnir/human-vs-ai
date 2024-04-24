#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int **DoThis(int n, int arr[][n], int l, int *size);
bool isEqual(int n, int arr1[], int arr2[]);

int main() {
    int a[4] = {2, 3, 4, 1};
    int b[4] = {1, 2, 4, 3};
    int arr[1][4] = {2, 3, 4, 1};
    int level = 1;
    int size;
    int **result;

    while (1) {
        result = DoThis(4, arr, level, &size);
        
        for (int i = 0; i < size; i++) {
            if (isEqual(4, result[i], b)) {
                printf("Level: %d\n", level + 1);
                return 0;
            }
        }

        arr = (int (*)[4]) result;
        level++;
    }

    return 0;
}

int **DoThis(int n, int arr[][n], int l, int *size){
    int total_size = l * (n - 1);
    *size = total_size;
    int **b = malloc(total_size * sizeof(*b));
    int i, j, k, index = 0;
    for (int r = 0; r < l; r++) {
        for (i = 0; i < n; i++) {
            j = (i + 1) % n;
            int *copy = malloc(n * sizeof(*copy));
            for (k = 0; k < n; k++)
                copy[k] = arr[r][k];
            int t = copy[i];
            copy[i] = copy[j];
            copy[j] = t;
            b[index] = copy;
            index++;
        }
    }
    return b;
}

bool isEqual(int n, int arr1[], int arr2[]) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}
