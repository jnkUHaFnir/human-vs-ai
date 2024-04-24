#include <stdio.h>
#include <stdlib.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int n, m;
    printf("Enter the value of m and n: ");
    if (scanf("%d %d", &m, &n) != 2) {
        printf("Invalid input\n");
        return 1;
    }

    int *arr = malloc(sizeof(int) * n * m);
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers:\n", m * n);
    for (int i = 0; i < m * n; i++) {
        while (scanf("%d", arr + i) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            clearInputBuffer(); // Clear input buffer
        }
    }

    // Print the array to verify input
    printf("Array elements: ");
    for (int i = 0; i < m * n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
