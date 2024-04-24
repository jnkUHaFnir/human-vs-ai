#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("Enter the number of rows (m) and columns (n) separated by a space: ");
    if(scanf("%d %d", &m, &n) != 2){
        printf("Invalid input\n");
        return 1;
    }

    int *arr = malloc(sizeof(int)*n*m);
    if(arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the values for the %d x %d array:\n", m, n);
    for(int i = 0; i < m*n; i++) {
        if(scanf("%d", &arr[i]) != 1) {
            printf("Invalid input\n");
            free(arr);
            return 1;
        }
    }

    // Printing the array elements for verification
    printf("Array elements:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", arr[i*n + j]);
        }
        printf("\n");
    }

    // Freeing the allocated memory
    free(arr);

    return 0;
}
