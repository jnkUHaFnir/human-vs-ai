#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("Enter the number of rows (m) and columns (n): ");
    scanf("%d %d", &m, &n);

    int *arr = malloc(sizeof(int) * n * m);

    printf("Enter the values for the matrix (%d x %d):\n", m, n);
    for (int i = 0; i < m * n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the values in the array for testing
    printf("Values stored in the array:\n");
    for (int i = 0; i < m * n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Don't forget to free the dynamically allocated memory

    return 0;
}
