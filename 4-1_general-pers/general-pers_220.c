#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    if (scanf("%d %d", &m, &n) != 2) {
        printf("Invalid input\n");
        return 1; // Exit with error
    }

    int *arr = malloc(sizeof(int) * n * m);
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit with error
    }

    for (int i = 0; i < m * n; i++) {
        if (scanf("%d", arr + i) != 1) {
            printf("Invalid input for array element %d\n", i);
            free(arr); // Free allocated memory before exiting
            return 1; // Exit with error
        }
    }

    // Print the values in the array to verify input
    for (int i = 0; i < m * n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Clean up allocated memory
    free(arr);

    return 0;
}
