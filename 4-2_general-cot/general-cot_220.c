#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    if(scanf("%d %d", &m, &n) != 2) {
        printf("Invalid input for m and n\n");
        return 1;
    }
    
    int *arr = malloc(sizeof(int) * n * m);
    if(arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < m * n; i++) {
        if (scanf("%d", arr + i) != 1) {
            printf("Invalid input for array element\n");
            return 1;
        }
    }

    // Output the array elements to verify input
    for (int i = 0; i < m * n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
