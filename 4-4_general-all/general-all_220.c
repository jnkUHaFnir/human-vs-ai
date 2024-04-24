#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &m, &n);

    int *arr = malloc(sizeof(int) * n * m);
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < m * n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input\n");
            free(arr);
            return 1;
        }
    }

    // Print the values stored in the array
    for (int i = 0; i < m * n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr); // Don't forget to free the allocated memory

    return 0;
}
